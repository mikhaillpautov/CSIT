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

int main() {
    int n;
    cin >> n;

    stack *first = nullptr;
    stack *temp_2 = nullptr;

    vector<int> nums;

    int min;
    int lastEven;

    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        int t = 1 + rand() % 10;
        push(first, t);
        push(temp_2, t);
        nums.push_back(t);
    }
    cout << endl;

    min = nums[0];
    for(int i = 0; i < nums.size(); i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    while(first) {
        int num = pop(first);
        cout << num << " ";
        if(num % 2 == 0) {
            lastEven = num;
        }
    }
    cout << endl;

    while(temp_2) {
        int num2 = pop(temp_2);
        if(num2 == min) {
            push(first, num2);
            push(first, lastEven);
        }
        else {
            push(first, num2);
        }
    }

    reverse(first);
    while(first) {
        cout << pop(first) << " ";
    }
}