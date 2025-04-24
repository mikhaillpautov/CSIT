#include "iostream"

using namespace std;

int main() {

    int n;
    cin >> n;

    double* a = new double[n + 1];
    for (int i = 0; i < n + 1; i++) {
        cin >> a[i];
    }

    double* b = new double[n];
    for (int i = 1; i < n + 1; i++) {
        b[i-1] = a[i] * i;
        cout << b[i-1] << "  ";
    }

    double* c = new double[n + 2];
    c[0] = 0;
    cout << "C ";
    for (int i = 1; i < n + 2; i++) {
        c[i] = a[i - 1] / i;
        cout << c[i] << "  ";
    }
}