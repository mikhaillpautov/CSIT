#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct stack {
    int inf;
    stack *next;
};

void push(stack *& h, char X) {
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

int top(stack *& h) {
    int X = h->inf;
    return X;
}

int countDividers(int X) {
    if(X <= 0) {
        return 0;
    }
    int c = 0;
    for(int i = 1; i*i <= X; i++) {
        if(X % i == 0) {
            if(i*i == X) {
                c += 1;
            } else {
                c += 2;
            }
        }
    }
    return c;
}

int main() {
    int n;
    cin >> n;

    stack *first = nullptr;
    stack *temp = nullptr;
    stack *temp_2 = nullptr;

    vector<int> dividers;

    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        int t = rand() % 10;
        push(first, t);
        push(temp_2, t);
        dividers.push_back(countDividers(t));
    }
    cout << endl;

    while(temp_2) {
        cout << pop(temp_2) << " ";
    }
    cout << endl;


    int maxEl = *max_element(dividers.begin(), dividers.end());

    while(first) {
        if(countDividers(top(first)) == maxEl) {
            pop(first);
        }else {
            push(temp, pop(first));
        }
    }
    while(temp) {
        push(first, pop(temp));
    }

    while(first) {
        cout << pop(first) << " ";
    }
}
