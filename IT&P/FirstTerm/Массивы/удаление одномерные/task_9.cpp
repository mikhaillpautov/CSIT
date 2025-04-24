#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "RUS");
    int n, x;
    cin >> n;
    cin >> x;

    int *mas = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 10;
        cout << mas[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ) {
        if (mas[i] % x == 0 && mas[i] % 2 == 0) {
            n--;
            for (int j = i; j < n; j++) { // сдвиг всех элементов влево
                mas[j] = mas[j + 1];
            }
        }
        else { // переход к следующему элементу только когда мы проверим тот, что сейчас.
            i++;
        }
    }


    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    return 0;
}