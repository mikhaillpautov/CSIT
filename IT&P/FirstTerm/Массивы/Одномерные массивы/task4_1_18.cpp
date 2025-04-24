#include "iostream"

using namespace std;

int main() {
    int n, min, max, xi, ni; // xi - идекс последнего максимального элемента, ni - индекс первого минимального элемента
    cout << "Enter array size: ";
    cin >> n;

    //Создание массива, наполненного псевдослучайными числами
    int *mas = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        mas[i] = rand() % 10 ;
        cout << mas[i] << " ";
    }
    cout << endl;
    max = mas[0];
    min = mas[0];

    //Нахождение первого мин
    for(int i = 0; i < n; i++) {
        if(mas[i] < min) {
            min = mas[i];
            ni = i;
        }
    }

    //Нахождение последнего макс
    for(int j = n - 1; j >= 0; j--) {
        if(mas[j] > max) {
            max = mas[j];
            xi = j;
        }
    }

    //Изменение значений
    mas[xi] = min;
    mas[ni] = max;

    //Вывод измененного массива
    for(int g = 0; g < n; g++) {
        cout << mas[g] << " ";
    }
    delete [] mas;//очищение памяти
}