#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Size n: ";
    cin >> n;

    // Резервируем массив с дополнительным местом для возможных вставок строк X
    int** mas = new int*[2*n];
    for (int i = 0; i < 2*n; i++) {
        mas[i] = new int[n];
    }

    // Заполнение массива
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mas[i][j] = rand() % 20 - 4;
        }
    }

    // Вывод исходного массива
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mas[i][j] << ' ';
        }
        cout << endl;
    }

    // Перемещаем строки вниз и вставляем строки X
    int currentRow = n;
    for (int i = 0; i < n; ++i) {
        bool allPositive = true;
        for (int j = 0; j < n; ++j) {
            if (mas[i][j] <= 0) {
                allPositive = false;
                break;
            }
        }

        if (allPositive) {
            // Сдвигаем все последующие строки вниз
            for (int k = currentRow - 1; k >= i; --k) {
                for (int l = 0; l < n; ++l) {
                    mas[k + 1][l] = mas[k][l];
                }
            }

            // Вставляем строку X
            for (int j = 0; j < n; ++j) {
                mas[i + 1][j] = 0;
            }

            currentRow++;
        }
    }

    // Вывод результирующего массива
    cout << "\nРезультат:\n";
    for (int i = 0; i < currentRow; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mas[i][j] << ' ';
        }
        cout << endl;
    }
    delete[] mas;
    return 0;
}