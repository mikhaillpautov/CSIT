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

list* getTail(list* cur) {
    if (cur == NULL) return NULL;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    return cur;
}

list* partition(list* low, list* high, list*& newLow, list*& newHigh) {
    list* pivot = high;
    list* prev = NULL;
    list* cur = low;
    list* tail = pivot;

    while (cur != pivot) {
        if (cur->inf < pivot->inf) {
            if (newLow == NULL) {
                newLow = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        else {
            if (prev != NULL) {
                prev->next = cur->next;
            }
            list* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
            cur = tmp;
        }
    }

    if (newLow == NULL) {
        newLow = pivot;
    }

    newHigh = tail;
    return pivot;
}

list* quickSort(list* low, list* high) {
    if (low == NULL || low == high) {
        return low;
    }

    list* newLow = NULL;
    list* newHigh = NULL;

    list* pivot = partition(low, high, newLow, newHigh);

    if (newLow != pivot) {
        list* tmp = newLow;
        while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = NULL;

        newLow = quickSort(newLow, tmp);

        tmp = getTail(newLow);
        tmp->next = pivot;
        pivot->prev = tmp;
    }

    pivot->next = quickSort(pivot->next, newHigh);
    if (pivot->next != NULL) {
        pivot->next->prev = pivot;
    }

    return newLow;
}

int main() {
    list *head = NULL;
    list *tail = NULL;

    int n;
    cin >> n;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int x = rand() % 10;
        push(head, tail, x);
    }
    print(head, tail);

    head = quickSort(head, tail);
    tail = getTail(head);

    print(head, tail);
}