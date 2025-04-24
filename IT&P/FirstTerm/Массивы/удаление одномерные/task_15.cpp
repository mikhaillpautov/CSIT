#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "RUS");
    int n, x;

    cin >> n;
    cin >> x;
    int* mas = new int(2*n);
    srand(time(NULL));
    for (int i=0; i < n; i++){
        mas[i] = rand() % 10;
        cout << mas[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ) {
        if (mas[i] == x) {
            n++;
            for (int j = n; j > i + 1; j-=1) { // сдвиг элементов вправо
                mas[j] = mas[j-1];
            }
            mas[i+1] = x; // заполнение освободившейся ячейки
            i+=2; // переход через новый элемент
        }
        else {
            i++;
        }
    }


    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    return 0;
}