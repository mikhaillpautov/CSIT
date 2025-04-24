#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "n = ";
    cin >> n;

    //Создание треугольника Паскаля
    int** mas = new int* [n + 1];
    for (int i = 0; i <= n; i++) mas[i] = new int[i + 1];
    mas[0][0] = 1;
    mas[1][0] = mas[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        mas[i][0] = 1;
        for (int j = 1; j < i; j++) mas[i][j] = mas[i - 1][j - 1] + mas[i - 1][j];
        mas[i][i] = 1;
    }
    //Вывод треугольника Паскаля
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << mas[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;


    for (int i = 0; i < n + 1; i++)
        cout << mas[n][i] << " ";

    delete[] mas;
    return 0;
}
