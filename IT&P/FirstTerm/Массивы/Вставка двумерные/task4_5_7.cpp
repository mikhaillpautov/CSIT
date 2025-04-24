#include<iostream>
using namespace std;
int main() {
    int n, c, k, l = 0, cnt = 0;
    cin >> n;
    k = n;
    n = 2 * n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < k && j < k) a[i][j] = rand() % 10;
            else a[i][j] = -555;
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (a[i][j] != -555) cout << a[j][i] << " ";
        cout << endl;
    }

    int* bb = new int[n];
    int* b = new int[n];
   

    for (int i = 0; i < k; i++) {
        c = 0;
        for (int j = 0; j < k; j++) if (a[i][j] % 2 != 0) c++;
        if (c == 0) {
            bb[l] = i;
            l++;
        }
    }

    for (int i = 0; i < l; i++) cout << bb[i] << " ";

    for (int i = 0; i < k; i++) {
        for (int u = 0; u < l; u++) {
            if (i - cnt == bb[u]) {
                k++;
                b = a[i];
                for (int t = k; t > i; t -= 1) {
                    a[t] = a[t - 1];
                }
                cnt++;
                a[i + 1] = b;
                i++;

            }

        }
    }



    cout << '\n' << l << '\n';
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (a[j][i] != -555) cout << a[j][i] << " ";
        cout << endl;
    }
    return 0;
}
