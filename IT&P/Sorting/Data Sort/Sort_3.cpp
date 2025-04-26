#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

ifstream inputFile ("C:/Users/super/CLionProjects/proga/txt's/STAFF.txt");
ofstream outputFile ("C:/Users/super/CLionProjects/proga/txt's/STAFFout_3.txt");

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
    if (a.salary != b.salary) {
        return a.salary > b.salary; // Сначала по зарплате
    }
    if (a.dateOfB.yy != b.dateOfB.yy) {
        return a.dateOfB.yy > b.dateOfB.yy; // Затем по году рождения
    }
    return a.experience > b.experience; // Наконец, по стажу
}

// Сортировка выбором
void selectionSort(vector<staff>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Индекс минимального элемента

        // Поиск минимального элемента в неотсортированной части
        for (int j = i + 1; j < n; j++) {
            if (compare(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }

        // Обмен минимального элемента с текущим
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    vector<staff> x;
    x = inF();
    int n = x.size();
    selectionSort(x);
    for (int i = 0; i < n; i++) {
        outF(x[i]);
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
