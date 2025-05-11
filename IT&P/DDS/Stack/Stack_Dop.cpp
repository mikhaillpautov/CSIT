#include <algorithm>
#include <iostream>
#include <ctime>
#include <map>
#include <string>
using namespace std;

struct stack {
    char inf;
    stack *next;
};

void push(stack *& h, char X) {
    stack *r = new stack;
    r->inf = X;
    r->next = h;
    h = r;
}

char pop(stack *& h) {
    char X = h->inf;
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

char top(stack *& h) {
    return h->inf;
}

int prior(char X) {
    if(X == '(') return 1;
    if(X == '+' || X == '-') return 2;
    if(X == '*' || X == '/') return 3;
    return 0;
}
bool oper(char X) {
    if(X == '+' || X == '-' || X == '*' || X == '/') return true;
    return false;
}
int main() {
    stack *znak = nullptr;
    string virazhenie;
    getline(cin, virazhenie);
    string res;

    for(char X : virazhenie) {
        if(isalpha(X) || isdigit(X)) {
            res += X;
        }
        else if(X == '(') {
            push(znak, '(');
        }
        else if(znak == nullptr && oper(X)) {
            push(znak, X);
        }
        else if(X == ')') {
            while(top(znak) != '(') {
                res += pop(znak);
            }
            if(znak != nullptr) pop(znak);
        }
        else if(oper(X)) {
            while(prior(top(znak))>= prior(X)) {
                res += pop(znak);
            }
            push(znak, X);
        }
    }
    while(znak) {
        res += pop(znak);
    }
    cout << res << endl;
}
//5+(3+(2+4*(3-1)+2)/4+1)*4
//a+(b+(c+d*(b-e)+c)/d+e)*d