#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    //0 -> n
    double* mas = new double[n + 1]; //коэффициенты многочлена
    for (int i = 0; i <= n; ++i) {
        cin >> mas[i];
    }

    double* arr = new double[n]; //коэффициенты производной
    for (int i = 0; i < n; ++i) {
        arr[i] = (i + 1) * mas[i + 1];
    }

    double* result = new double[n + 1];
    for (int i = 0; i <= n; ++i) {
        result[i] = mas[i];
    }
    for (int i = 0; i < n; ++i) {
        result[i] += arr[i];
    }

    for (int i = 0; i <= n; ++i) {
        cout << result[i] << " ";
    }

    delete[] mas;
    delete[] arr;
    delete[] result;

    return 0;
}