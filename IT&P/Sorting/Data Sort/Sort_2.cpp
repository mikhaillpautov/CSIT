#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

ifstream inputFile ("C:/Users/super/CLionProjects/proga/txt's/STAFF.txt");
ofstream outputFile ("C:/Users/super/CLionProjects/proga/txt's/STAFFout_2.txt");

struct date {
    int dd, mm, yy;
};

struct staff {
    string name;
    string post;
    date dateOfB;
    int experience;
    int salary;
};

date str_to_date(string str) {
    date x;
    string temp = str.substr(0, 2);
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2);
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4);
    x.yy = atoi(temp.c_str());
    return x;
}

vector<staff> inF() {
    vector<staff> x;
    staff temp;
    while(inputFile.peek() != EOF) {
        inputFile >> temp.name;
        inputFile >> temp.post;
        string tmp;
        inputFile >> tmp;
        temp.dateOfB = str_to_date(tmp);
        inputFile >> temp.experience;
        inputFile >> temp.salary;
        x.push_back(temp);
    }
    return x;
}

void outF(staff x) {
    outputFile << setw(10) << left << x.name;
    outputFile << setw(12) << left << x.post;
    if (x.dateOfB.dd < 10) {
        outputFile <<  left << '0' << x.dateOfB.dd << '.';
    }
    else {
        outputFile << left << x.dateOfB.dd << '.';
    }
    if (x.dateOfB.mm < 10) {
        outputFile << left << '0' << x.dateOfB.mm << '.';
    }
    else {
        outputFile << left << x.dateOfB.mm << '.';
    }
    outputFile << setw(6) << left << x.dateOfB.yy;
    outputFile <<setw(4) << x.experience;
    outputFile << x.salary << endl;
}

bool compare(const staff& a, const staff& b) {
    if (a.dateOfB.yy != b.dateOfB.yy) {
        return a.dateOfB.yy > b.dateOfB.yy; // > по убыванию, < по возрастанию
    }
    return a.experience > b.experience;
}

void combSort(vector<staff>& arr) {
    int n = arr.size();
    int gap = n;
    bool swapped = true;
    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;
        swapped = false;
        for (int i = 0; i < n - gap; i++) {
            if (compare(arr[i + gap], arr[i])) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main() {
    vector<staff> x;
    x = inF();
    int n = x.size();
    combSort(x);
    for (int i = 0; i < n; i++) {
        outF(x[i]);
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
