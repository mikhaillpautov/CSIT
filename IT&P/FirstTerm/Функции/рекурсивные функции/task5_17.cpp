#include <iostream>
using namespace std;

void printhalf(int n, int current = 1) {
    if (current > n) return; 
    for (int i = 0; i < current; ++i) {
        cout << current;
    }
    for (int i = 0; i < 2 * (n - current) - 1; ++i) {
        cout << "-";
    }
    for (int i = 0; i < current; ++i) {
        cout << current;
    }
    cout << endl;
    printhalf(n, current + 1);
}

void printTriangle(int n) {
    printhalf(n);
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            cout << i;
        }
        for (int j = 0; j < 2 * (n - i) - 1; ++j) {
            cout << "-";
        }
        for (int j = 0; j < i; ++j) {
            cout << i;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    printTriangle(n);

    return 0;
}