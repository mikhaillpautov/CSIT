#include "iostream"
//#include "time.h"

using namespace std;

int main() {
    int n, summ = 0;
    cout << "Enter array size: ";
    cin >> n;

    int *mas = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        mas[i] = rand() % 10;//заполнение массива
        cout << mas[i] << " ";
    }
    cout << endl;

    for(int j = 0; j < n; j++) {  
        if(j % 2 != 0 && mas[j] % 2 != 0) { //Проверка нечетности номера и значения элемента
            summ += mas[j]; //Прибавление элемента в сумму
        }
        else if(j == n - 1 && summ == 0) {
            cout << "No such elements in array" << endl;
        }
    }

    //Вывод суммы
    if(summ != 0) {
        cout << "Summ = " << summ << endl;
    }

    delete[] mas;//очищение памяти
}