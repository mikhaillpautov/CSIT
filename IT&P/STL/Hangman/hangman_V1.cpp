#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

char ThemeChoose() {
    cout << "Which topic would you like to play with?\n";
    cout << "1) Music\n" << "2) Fruits\n" << "3) Transport\n" << "4) Cites\n" << endl;
    int num;
    cin >> num;
    switch (num) {
        case 1:
            return 'm';
            break;
        case 2:
            return 'f';
            break;
        case 3:
            return 't';
            break;
        case 4:
            return 'c';
        default:
            cout << "Invalid choice. Defaulting to Music.\n";
            return 'm';
    }
}

string wordChoosing(char T) {
    ifstream input("C:/Users/super/CLionProjects/proga/txt's/Themes.txt");
    string line;
    vector<string> words;
    while (getline(input, line)) {
        if (!line.empty() && line[0] == T) {
            line = line.substr(2); // Удаляем первые два символа
            words.push_back(line);
        }
    }
    if (words.empty()) {
        cout << "No words found for the selected theme. Exiting...\n";
        exit(1);
    }
    srand(time(NULL));
    size_t size = words.size();
    int s = rand() % size;
    return words[s];
}

vector<char> wordToSymb(string word) {
    vector<char> letters;
    for (char c : word) {
        letters.push_back(c);
    }
    return letters;
}

vector<char> ___Vec(vector<char> letters) {
    vector<char> Spaces(letters.size(), '_');
    return Spaces;
}

void VecPrint(const vector<char>& vec) {
    for (char a : vec) {
        cout << a << " ";
    }
    cout << endl;
}

void clearScreen() { // Для красивого вывода
    for (int i = 0; i < 100; i++) {
        cout << "\n";
    }
}

void hangStation(int hits) { // Рисунок повешенного
    switch (hits) {
        case 1:
            cout << "    ***************\n"
                 "             |      *\n"
                 "             |      *\n"
                 "             |      *\n"
                 "             |      *\n"
                 "             O      *\n"
                 "           / | /    *\n"
                 "             |      *\n"
                 "            / /     *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "*********************\n"
                 "*                   *\n";
            break;
        case 2:
            cout << "    ***************\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "             O      *\n"
                 "           / | /    *\n"
                 "             |      *\n"
                 "            / /     *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "*********************\n"
                 "*                   *\n";
            break;
        case 3:
            cout << "    ***************\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "             O      *\n"
                 "           / | /    *\n"
                 "             |      *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "*********************\n"
                 "*                   *\n";
            break;
        case 4:
            cout << "    ***************\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "            O       *\n"
                 "            |       *\n"
                 "            |       *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "*********************\n"
                 "*                   *\n";
            break;
        case 5:
            cout << "    ***************\n"
                 "                    *\n"
                 "                    *\n"
                 "            O       *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "*********************\n"
                 "*                   *\n";
            break;
        case 6:
            cout << "    ***************\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "                    *\n"
                 "*********************\n"
                 "*                   *\n";
            break;
    }
}

int main() {
    char t = ThemeChoose();
    string word = wordChoosing(t);
    string Usrword = "";
    cout << "The word has been chosen!\n";

    vector<char> letters = wordToSymb(word);
    vector<char> Spaces = ___Vec(letters);
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '-'};

    int hits = 6;

    while (hits > 0 && Usrword != word) {
        cout << "Available letters: ";
        for (char c : alphabet) {
            if (c != '#') {
                cout << c << " ";
            }
        }
        cout << "\n";

        VecPrint(Spaces);
        cout << "Enter a letter: ";
        string letter;
        cin >> letter;
        char let = letter[0];

        bool isCorrect = false;
        for (size_t i = 0; i < letters.size(); ++i) {
            if (letters[i] == let) {
                Spaces[i] = let;
                isCorrect = true;
            }
        }

        if (isCorrect) {
            cout << "Correct guess!\n";
            for (size_t i = 0; i < alphabet.size(); ++i) {
                if (alphabet[i] == let) {
                    alphabet[i] = '#';
                }
            }
            clearScreen();
            hangStation(hits);
        } else {
            clearScreen();
            hangStation(hits);
            cout << "Wrong letter! You have " << hits - 1 << " attempts left.\n";
            hits--;
            for (size_t i = 0; i < alphabet.size(); ++i) {
                if (alphabet[i] == let) {
                    alphabet[i] = '#';
                }
            }
        }

        Usrword = "";
        for (char c : Spaces) {
            Usrword += c;
        }
    }

    if (hits == 0) {
        clearScreen();
        cout << "You lost! The word was: " << word << endl;
    } else {
        clearScreen();
        cout << "Congratulations! You win!" << endl;
    }

    return 0;
}