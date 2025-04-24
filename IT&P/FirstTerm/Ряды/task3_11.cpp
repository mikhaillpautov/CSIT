#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, g = 500, n = 1; // g - ограничение; n = 1 т.к первый элемент = x/n и так проще позже высчитывать степень и делитель прибавлением 2
    long double arctan = 1, eps = 0.000001;
    cout << "Enter x: ";
    cin >> x;

    for(int i = 1; i <= g && abs(arctan) > eps; i++) {
        if(i == 1) {
            arctan = 0; //Если не установить значение в самом начале, то цикл не начнется т.к arctg без значения не может сравниться с eps
        }
        if(i % 2 != 0) { //нечетные элементы
            arctan += pow(x, n)/n;
            n += 2;
        }
        else { //четные элементы
            arctan -= pow(x, n)/n;
            n += 2;
        }
        if(i == g) 
            cout << "Rashod" << endl;
    }
cout << "arctg = " << arctan << endl;
return 0;
}