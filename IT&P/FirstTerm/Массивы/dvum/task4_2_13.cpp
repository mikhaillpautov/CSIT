#include <iostream>

using namespace std;

int main() {
    //Размерность массива
    int n, c1{0}, c2{0}, mn, mx, imxi, imxj, imni, imnj, z;

    cout << "Enter array size: ";
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
    cout << endl;

    //Поиск минимума и максимума
    mx = mas[0][1];//[0][1] т.к максимальный мы ищем в незакрашенной области, не включая основную диагональ 
    mn = mas[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //Поиск максимального элемента в незакрашенной области
            if (i < j) {
                if (mas[i][j] > mx && mas[i][j] % 2 != 0) {
                    mx = mas[i][j];
                    imxi = i;
                    imxj = j;
                    c1++; //Для проверки наличия подходящих элементов
                }
            }
            //Поиск минимального элемента в закрашенной области
            else {
                if (mas[i][j] < mn && mas[i][j] % 2 == 0) {
                    mn = mas[i][j];
                    imni = i;
                    imnj = j;
                    c2++; //Для проверки наличия подходящих элементов
                }
            }
        }
    }

    //Вывод сообщения об отсутствии соответствующих элементов
    if (c1 == 0) cout << "No such odd element";
    if (c2 == 0) cout << "No such even element";

    //Замена MAX на MIN и MIN а MAX
    if (c1 != 0 && c2 != 0) {
        z = mas[imxi][imxj];
        mas[imxi][imxj] = mas[imni][imnj];
        mas[imni][imnj] = z;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mas[i][j] << "  ";
            }
            cout << endl;
        }
    }
    
    delete[] mas; //Очистка памяти
}