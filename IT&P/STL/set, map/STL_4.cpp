123 45 678 90 321 12 456 78 901#include <iostream>
#include <set>
#include <vector>

using namespace std;

void extractDigits(int num, set<int>& digits) {//разделение числа на цифры
   while (num > 0) {
        digits.insert(num % 10);
        num /= 10;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    set<int> three; //множество цифр их трехзначных
    set<int> two;// множество цифр из двузнвчных

    for (int num : numbers) {
        if (num >= 100 && num <= 999) {
            extractDigits(num, three);
        } else if (num >= 10 && num <= 99) {
            extractDigits(num, two);
        }
    }

    set<int> result;
    for (int digit : three) {
        if (two.find(digit) == two.end()) {//проверяем есть ли цифра в двузначных
            result.insert(digit);
        }
    }

    cout << "Only in treedidgts: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;

    return 0;
}
//9

//123 45 678 90 321 12 456 78 901
