#include  <iostream>
#include <ctime>
using namespace std;

struct stack {
    int inf;
    stack *next;
};

void push(stack *& h, int X) {
    stack *r = new stack;
    r->inf = X;
    r->next = h;
    h = r;
}

int pop(stack *& h) {
    int X = h->inf;
    stack *p = h;
    h = h->next;
    delete p;
    return X;
}

void reverse(stack *& h) {
    stack *h1 = nullptr;
    while (h) {
        push(h1, pop(h));
    }
    h = h1;
}

void change(stack *& h) {
    stack *h1 = nullptr;
    stack *res = nullptr;
    int x, y;
    while (h) {
        x = pop(h);
        push(res, x);
        while (h) {
            y = pop(h);
            if (x != y) {
                push(h1, y);
            }
        }
        reverse(h1);
        h = h1;
        h1 = nullptr;
    }
    reverse(res);
    h = res;
}

int main() {
    stack *head = nullptr;
    int n = 15, x;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        x = rand() % 5;
        cout << x << " ";
        push(head, x);
    }
    reverse(head);
    change(head);
    cout << "\n";
    while(head) {
        cout << pop(head) << " ";
    }
}