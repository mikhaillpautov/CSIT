#include<iostream>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;

    srand(time(NULL));
    int* mas = new int[n + n];
    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 10;
    }
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ) {
        if (mas[i] % x == 0) {
            n++;
            for (int j = n; j > i; j -= 1) {
                mas[j] = mas[j - 1];
            }
            mas[i + 1] = x;
            i += 2;
        }
        else i++;
    }
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    delete[] mas;
    return 0;
}