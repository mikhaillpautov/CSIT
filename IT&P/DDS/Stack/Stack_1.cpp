#include <algorithm>
#include  <iostream>
#include <ctime>
#include <vector>
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
int top(stack *& h) {
    char X = h->inf;
    return X;
}

int main() {
    int n;
    cin >> n;

    vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    vector<char> consonant = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};

    stack *first = nullptr;
    stack *second = nullptr;
    stack *third = nullptr;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int t = rand() % 26;
        char bukva =  letters[t];
        push(first, bukva);
        push (third, bukva);
    }

    while(third) {
        cout << pop(third) << " ";
    }
    cout << '\n' << '\n';

    int c = 0;
    bool firstof_vowel = false;
    while (firstof_vowel != true) {
        char now = pop(first);
        push(second, now);
        c++;
        if(find(vowels.begin(), vowels.end(), now) != vowels.end()){
            firstof_vowel = true;
        }
    }

    push(first, '?');
    for (int i = 0; i < c; i++) {
        push(first, pop(second));
    }

    while(first) {
        cout << pop(first) << " ";
    }
}
