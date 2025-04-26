#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

ifstream inputFile ("C:/Users/super/CLionProjects/proga/txt's/STAFF.txt");
ofstream outputFile ("C:/Users/super/CLionProjects/proga/txt's/STAFFout_1.txt");

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

void quickSort(vector<staff>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high].salary;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j].salary >= pivot) { // >= по возрастанию, <= по убыванию
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<staff> x;
    x = inF();
    int n = x.size();
    quickSort(x,0,n-1);
    for (int i = 0; i < n; i++) {
        outF(x[i]);
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
