#include <iostream>

using namespace std;

int main() {
    //Размерность массива
    int n, mn, mx, imn, imx;

    cout << "Enter array size: ";
    cin >> n;

    //Создание пустой строки для замены
    int *arr = new int[n];

    //Создание двумерного массива
    int **mas = new int*[n];
    for (int i = 0; i < n; i++) {
        mas[i] = new int[n];
    }

    //Заполнение случайными числами
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = rand() % 10;
            cout << mas[i][j] << "  ";
        }
        cout << endl;
    }

    //Поиск строк в которых находятся максимцм и минимум
    mn = mas[0][0];
    mx = mas[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mas[i][j] >= mx) {
                mx = mas[i][j];
                imx = i;
            }
            if (mas[i][j] < mn) {
                mn = mas[i][j];
                imn = i;
            }
        }
    }

    cout << '\n';

    //Замена строк
    for (int i = 0; i < n; i++) {
        arr[i] = mas[imx][i];
        mas[imx][i] = mas[imn][i];
        mas[imn][i] = arr[i];
    }

    //Вывод изменеоого массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mas[i][j] << "  ";

        }
        cout << endl;
    }
    //Очистка памяти
    delete[] mas;
    delete[] arr;
}