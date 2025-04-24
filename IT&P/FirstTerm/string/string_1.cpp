#include "iostream"
#include "string"
using namespace std;

int main() {
    string a;
    //string::size_type n;
    int n,h, m;
    getline(cin, a);
    n = a.length();
    for (int i = 0; i < n; i++) {
        if(a[i] >= '0' && a[i] <= '9') {
            h = a[i] - '0';
            if(h % 2 == 0 && h > m) {
                m = h;
            }
        }
    }
    cout << m << endl;
}
//найти макс. цифру