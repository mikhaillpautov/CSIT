#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

string to_lower(string s) {
    for(int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

set<string> to_set(string s) {
    set<string> set_word;
    if(s[s.length()-1] != ' ') {
        s += " ";
    }
    while(s != "") {
        set_word.insert(to_lower(s.substr(0, s.find(' '))));
        s.erase(0, s.find(' ') + 1);
    }
    return set_word;
}
int main() {
    ifstream input("C:/Users/super/CLionProjects/proga/txt's/textFile.txt");
    set<string> temp, voskl, vopr, pov, res1, res2;
    string s;

    while(input) {
        getline(input, s);
    }
    while(s != "") {
        int pos = s.find_first_of("'!?.'");
        temp = to_set(s.substr(0, pos));
        if (s[pos] == '!') {
            voskl.insert(temp.begin(), temp.end());
        }
        if (s[pos] == '?') {
            vopr.insert(temp.begin(), temp.end());
        }
        if (s[pos] == '.') {
            pov.insert(temp.begin(), temp.end());
        }
        s.erase(0, pos + 2);
    }
    
    cout << '\n';
    set_intersection(pov.begin(), pov.end(), voskl.begin(), voskl.end(), inserter(res1, res1.begin()));

    for (auto i : res1) {
        cout << i << " ";
    }

}