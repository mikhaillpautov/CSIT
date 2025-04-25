#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

bool isNumber(const string& str) {
    for (char c : str) {
        if (c < '0' || c > '9') return false;
    }
    return !str.empty();
}

int main() {
    string input;
    ifstream inputFile("C:/Users/super/CLionProjects/proga/txt's/STL_5.txt");
    getline(inputFile, input);

    vector<string> tokens;
    string token;

    for (char c : input) {
        if (c != ' ') {
            token += c;
        } else if (!token.empty()) {
            tokens.push_back(token);
            token.clear();
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    string firstToken = tokens[0]; 
    int firstNumberFrequency = 0;

    map<string, int> frequencyMap;
    for (const string& t : tokens) {
        frequencyMap[t]++;
    }

    if (isNumber(firstToken)) {
        firstNumberFrequency = frequencyMap[firstToken];
    } else {
        cout << "First token is not a number." << endl;
        return 0;
    }

    bool found = false;
    for (const auto& pair : frequencyMap) {
        if (pair.second == firstNumberFrequency && !isNumber(pair.first)) {
            cout << pair.first << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No words found with the specified frequency.";
    }

    cout << endl;

    return 0;
}