#include "iostream"

using namespace std;

int main() {
    int n, max;
    cout << "Enter array size: ";
    cin >> n;

    //Создание массива, наполненного псевдослучайными числами
    int *mas = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        mas[i] = rand() % 10;
        cout << mas[i] << " ";
    }
    cout << endl;
    max = mas[0];

    //Нахождение максимума
    for(int i = 0; i < n; i++) {
        if(mas[i] > max) {
            max = mas[i];
        }
    }

    //Вычисление ответа
    for(int i = 0; i < n; i++) {
        if(mas[i] >= max) {
            mas[i] *= -1;
            cout << mas[i] << " ";
        }
        else {
            cout << mas[i] << " ";
        }
    }
    delete[] mas;//очищение памяти
}