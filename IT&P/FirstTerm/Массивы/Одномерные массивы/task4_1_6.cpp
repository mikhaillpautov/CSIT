#include "iostream"

using namespace std;

int main() {
    int n, x, s = 0;
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter x: "; //Число для проверки на кратность
    cin >> x;

    //Создание массива, наполненного псевдослучайными числами
    int *mas = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        mas[i] = rand() % 10;
        cout << mas[i] << " ";
    }
    cout << endl;

    //Вычисление ответа
    for(int i = 0; i < n; i++) {
        if(mas[i] != 0 && mas[i] % x != 0) {
            cout << i << " ";
            s += mas[i]; //Сумма нужна для вывода в случае отсутствия подходящих элементов
        }
        else if(i == n - 1 && s == 0) {
            cout << "No such elements";
        }
    }
    delete[] mas;//очищение памяти
}