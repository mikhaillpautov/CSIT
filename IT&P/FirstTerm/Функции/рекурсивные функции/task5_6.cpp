#include "iostream"
using namespace std;

int f(int n, int x) {
    if (n == 0) return n, 1;
    if (n == 1) return n, 2*x;

    int k = 1;
    int t = 2*x;

    for (int i = 2; i <= n; i++) {
        int c = 2 * x * t - 2 * (i - 1) * k;
        k = t;
        t = c;
    }
    return t;
}
int main() {
    int n, x;
    cin >> n >> x;
    cout << f(n, x) << endl;
    return 0;
}