#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, word;
    string razdel = "!?,.;:- ";

    getline(cin, s1);
    getline(cin, word);
    s1 += '.';

    string::size_type pos = 0, k;
    string::size_type len = word.length();
    k = s1.find_first_of(razdel);//индекс первого знака пунктуации, конец первого слова

    while (k != string::npos) {//пока есть слова
        string slovo = s1.substr(pos, k - pos);
        bool allin = true;
        for(int i = 0; i < len; i++) {//проходя по всем символам word, проверям все ли символы word есть в slovo
            if(slovo.find(word[i]) == string::npos) {
                allin = false;//если нет, то переходим к следующему слову
                break;
            }
        }
        if(allin) {
            s1.erase(pos, k);
        }
        if(ispunct(s1[k])) {//начало следующего слова
            pos = k + 2;
        }
        else {
            pos = k + 1;
        }

        k = s1.find_first_of(razdel, pos);//индекс знака пунктуации следующего слова, его конец

    }

    cout << s1 << endl;
}

