#include <iostream>

using namespace std;

int main() {
    //Размерность массива
    int n;
    cin >> n;

    //Создание строки и заполнение её случайными числами
    srand(time(NULL));
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << "  ";
    }

    cout << '\n' << '\n';

    //Создание двумерного массива и заполнение его случайными числами
    int **mas = new int*[n];
    for (int i = 0; i < n; i++) {
        mas[i] = new int[n];
    }
    //Заполнение
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = rand() % 10;
            cout << mas[i][j] << "  ";
        }
        cout << endl;

    }

    //Замена четных строк
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                mas[i][j] = arr[j];
            }
        }
    }
    cout << '\n';
    //Вывод измененного массива 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mas[i][j] << "  ";
        }
        cout << endl;
    }
    
    delete[] mas;//Очистка памяти
}