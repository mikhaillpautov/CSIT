#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n = 100, x;
    double y = 1, eps = 0.000001;

    cout << "Enter x: ";
    cin >> x;

    for(int i = 1; i <= n && abs(y) > eps; i++) {
        if(i == 1) { //Если не задать значение y, цикл не начнётся, это, скорее всего, костыль, но я не знаю сделать подругому
            y = 0;
        }
        y += pow(-1, i - 1) * pow(x, i) / i;
        cout << y << endl;
        if(i == n)
            cout << "Rashod";
        cout << "ln(1 + x) = " << y << endl;
    }

    

    return 0;
}