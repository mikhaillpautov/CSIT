#include <iostream>

using namespace std;

int main() {
    //Размерность массива
    int n;
    cin >> n;

    //Создание массива
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
}