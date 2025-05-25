#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<vector<int>> X) {
    for(int i = 0; i < X.size(); i++) {
        cout << i << ": " << X[i].size() << endl;
    }
}

int main() {
    vector<vector<int>> L = {
        {3, 4, 5, 7},   //0
        {3, 8},         //1
        {4, 7, 9},      //2
        {0, 1, 7, 10},  //3
        {0, 2, 6},      //4
        {0, 6, 10},     //5
        {4, 5},         //6
        {0, 2, 3, 8, 9},//7
        {1, 7, 9},      //8
        {2, 7, 8},      //9
        {3, 5}          //10
    };

    print(L);

    return 0;
}