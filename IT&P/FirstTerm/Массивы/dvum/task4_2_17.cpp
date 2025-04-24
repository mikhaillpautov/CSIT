#include <iostream>
using namespace std;
int main() {
    
    int n, c, h;
    cin >> n;
    c = n * n - 1;

    //Создание массива
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    //Заполнение массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[j][i] = c;
            c -= 1;
        }
    }
    //"Переворачивание" нечетных строк
    for (int i = n - 2; i >= 0; i -= 2) {
        for (int j = 0; j < n / 2; j++) {
            h = a[n - 1 - j][i];
            a[n - 1 - j][i] = a[j][i];
            a[j][i] = h;
        }
    }
    //Вывод массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }

    delete[] a;//Очистка памяти
    return 0;
}
