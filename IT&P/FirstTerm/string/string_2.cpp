#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, smax, smin;
    string razdel = "!?,.:;- ";
    getline(cin, s1);
    s1 += '.';
    string::size_type pos = 0, k, max = 0, min;
    string::size_type maxstart, maxend, minstart, minend;
    k = s1.find_first_of(razdel);//первый знак пунктуации, конец первого слова

    while (k != string::npos) {
        string word = s1.substr(pos, k - pos);//выделяем слово
        if (word.length() > max) {//проверям, что слово самое длинное и сохраянем индексы его начала и конца
            max = word.length();
            smax = word;
            maxstart = pos;
            maxend = k;
        }
        else if (word.length() < min) {//то же самое, только с самым коротким
            min = word.length();
            smin = word;
            minstart = pos;
            minend = k;
        }
        if (ispunct(s1[k])) {//сдвигаем начало слова
            pos = k + 2;
        }
        else {
            pos = k + 1;
        }
        k = s1.find_first_of(razdel, pos);//индекс нового знака пунктуации и конец след. слова
    }

    s1.erase(maxstart, maxend - maxstart);
    s1.insert(maxstart, smin);
    s1.erase(minstart, minend - minstart);
    s1.insert(minstart, smax);

    cout << s1 << endl;

    return 0;
}