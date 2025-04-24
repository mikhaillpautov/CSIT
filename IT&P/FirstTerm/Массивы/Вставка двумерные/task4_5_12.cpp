#include <iostream>
using namespace std;
int main() {
    int n, p = 0;
    bool negative = true;
    cin >> n;
    p=n;

    int** mas = new int*[n];
    for (int i = 0; i < n; i++) {
        mas[i] = new int[n];
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = rand() % 10 - 2;
            cout << mas[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n;){
        negative = false;
        for (int j = 0; j < n; j++) {
            if (mas[i][j] <=0) {
                negative = true;
                break;
            }
        }
        if(negative == false) {
            n--;
           for (int j = i; j < n; j++) {
               mas[j] = mas[j+1];
           }
        }
        else {
            i++;
        }
    }
    cout << " Array:  " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            cout << mas[i][j] << "  ";
        }
        cout << endl;
    }

    delete[] mas;
    return 0;
}