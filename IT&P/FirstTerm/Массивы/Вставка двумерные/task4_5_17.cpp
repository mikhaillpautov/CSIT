#include<iostream>
using namespace std;
int main() {
    int n, c, k;
    cin >> n;
    k = n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 10;
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[j][i] << " ";
        cout << endl;
    }

    for (int i = 0; i < k;) {
        c = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) c++;
        }
        if (c == n) {
            k -= 1;
            for (int t = i; t < k; t++) {
                a[t] = a[t + 1];
            }
        }
        else i++;
    }

    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) cout << a[j][i] << " ";
        cout << endl;
    }
   
    return 0;
}
