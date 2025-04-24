#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printposled(vector<int> v) {//вывод вектора
    for(int a : v) {
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    vector<int> posled1;
    int n;
    cin>>n;

    for(int i = 0; i < n; i++) {//заполнение вектора
        int x;
        cin >> x;
        posled1.push_back(x);
    }

    posled1.erase(remove_if(posled1.begin(), posled1.end(), [](int x) { //удление нечетных эл.
        return x % 2 != 0;
    }), posled1.end());
    printposled(posled1);

    auto min = min_element(posled1.begin(), posled1.end()); //циклический сдвиг, мин. элемент на первое место
    rotate(posled1.begin(), min, posled1.end());
    printposled(posled1);

    sort(posled1.begin(), posled1.end()); //сортировка последовательности
    printposled(posled1);

    int el;//вставка нового эл.
    cin >> el;
    auto enter = lower_bound(posled1.begin(), posled1.end(), el);
    posled1.insert(enter, el);
    printposled(posled1);



    return 0;
}
//4 1 6 8 2 4 3 7 5 9