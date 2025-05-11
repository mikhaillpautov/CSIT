#include <iostream>
#include <ctime>
#include <cmath>
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

bool sostav(int x) {
    if(x <= 3) {
        return false;
    }
    int delitel = 2;
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            if(i == x/i) {
                delitel += 1;
            }
            else {
                delitel += 2;
            }
            if (delitel >= 3) {
                return true;
            }
        }
    }
    return false;
}



int main() {
    list *head = nullptr;
    list *tail = nullptr;

    int n;
    cin >> n;
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        int x = rand() % 10;
        push(head, tail, x);
    }

    print(head, tail);


    list *temp = head;
    list *fsost = nullptr;

    while (temp) {
        if (sostav(temp->inf)) {
            fsost = temp;
            break;
        }
        temp = temp->next;
    }

    if (!fsost || fsost == head) {
        return 1;
    }
    fsost->prev->next = nullptr;
    list *new_head = fsost;
    fsost->prev = nullptr;

    tail->next = head;
    head->prev = tail;

    head = new_head;
    tail = fsost->prev;

    print(head, tail);
    del_list(head, tail);

    return 0;
}
