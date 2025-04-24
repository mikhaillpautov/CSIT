#include<iostream>

using namespace std;
int main() {

    int n;
    cin >> n;
    //Вводить по мере увеличения степени от 0 -> n
    double* a = new double[n + 1];
    for (int i{ 0 }; i < n + 1; i++)
        cin >> a[i];
    double* b = new double[n];
    for (int i{ 1 }; i < n + 1; i++) {
        b[i - 1] = a[i] * i;
        cout << b[i - 1] << " ";
    }
    cout << "\n";
    double* c = new double[2 * n];
    for (int i{ 0 }; i < 2 * n; i++) {
        c[i] = 0;
    }
    for (int i{ 0 }; i < n + 1; i++) {
        for (int j{ 0 }; j < n; j++) {
            c[i + j] += a[i] * b[j];
        }
    }

    for (int i = 0; i < 2 * n; i++)
        cout << c[i] << " ";

    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
