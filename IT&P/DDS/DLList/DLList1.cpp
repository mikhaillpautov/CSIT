#include <iostream>
#include <ctime>
using namespace std;

struct list {
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, int x) {
    list *r = new list;
    r->inf = x;
    r->next = NULL;
    if(!h && !t) {
        r->prev = NULL;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print(list *h, list *t) {
    list *p = h;
    while(p) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}

list *find(list *h, list *t, int x) {
    list *p = h;
    while(p) {
        if(p->inf == x) break;
        p = p->next;
    }
    return p;
}

void insert_after(list *&h, list *&t, list *&r, int y) {
    list *p = new list;
    p->inf = y;
    if(r == t) {
        p->next = NULL;
        p->prev = r;
        r->next = p;
        t = p;
    }
    else {
        r->next->prev = p;
        p->next = r->next;
        p->prev = r;
        r->next = p;
    }
}

void del_node(list *&h, list *&t, list *&r) {
    if(r == h && r == t) {
        h = t = NULL;
    }
    else if(r == h) {
        h = h->next;
        h->prev = NULL;
    }
    else if(r == t) {
        t = t->prev;
        t->next = NULL;
    }
    else {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

void del_list(list *&h, list *&t) {
    while(h) {
        list *p = h;
        h = h->next;
        if(h) h->prev = NULL;
        delete p;
    }
}

int main() {
    list *head = NULL;
    list *tail = NULL;

    int n;
    cin >> n;
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        int x = rand() % 2;
        push(head, tail, x);
    }

    print(head, tail);

    int min = head->inf;
    list *p = head->next;
    while(p) {
        if(p->inf < min) {
            min = p->inf;
        }
        p = p->next;
    }

    list *first_min = head;
    while(first_min && first_min->inf != min) {
        first_min = first_min->next;
    }
    list *last_min = tail;
    while(last_min && last_min->inf != min) {
        last_min = last_min->prev;
    }

    if(first_min && last_min) {
        if(first_min == last_min) {
            del_node(head, tail, first_min);
        }
        else {
            del_node(head, tail, first_min);
            del_node(head, tail, last_min);
        }
    }

    print(head, tail);

    del_list(head, tail);

    return 0;
}