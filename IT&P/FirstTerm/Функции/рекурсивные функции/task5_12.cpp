#include <iostream>
#include <cmath>
using namespace std;

int f(int n, int k) {
    if (n != 0) {
        return n % 10 * pow(2, k) + f(n / 10, k + 1);
    }
    else return 0;
}
int main() {
    int n, x;
    cin >> n;
    cout << f(n, 0) << endl;
    return 0;
}