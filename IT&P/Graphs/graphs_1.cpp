#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SmezhAmount(vector<vector<int>> v, int n) {
    vector<int> res;
    for (int i = 0; i < v[n].size(); ++i) {
        res.push_back(v[n][i]);
    }

    for(int i = 0; i < v.size(); ++i) {
        int c = count(v[i].begin(), v[i].end(), n);
        if(c) {
            res.push_back(i);
        }
    }
    cout << res.size();
}


int main() {
    vector<vector<int>> L = {
        {3, 7},     //0
        {3, 8},     //1
        {4},        //2
        {10},       //3
        {0},        //4
        {0, 10},    //5
        {4, 5},     //6
        {2, 3, 9},  //7
        {7},        //8
        {2, 8},     //9
        {5}         //10
    };
    int v;
    cin >> v;
    if(v > L.size() - 1 || v < 0) {
        return 1;
    };

    SmezhAmount(L, v);

}