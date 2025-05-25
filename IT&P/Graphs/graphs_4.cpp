#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> &X, vector<bool> &vis, int A) {
    vis[A] = true;
    for (int i = 0; i < X[A].size(); ++i) {
        if (!vis[X[A][i]]) {
            dfs(X, vis, X[A][i]);
        }
    }
}

void findUnrich(vector<vector<int>> &X, int A) {
    vector<bool> vis(X.size(), false);
    dfs(X, vis, A);

    for (int i = 0; i < X.size(); ++i) {
        if (!vis[i]) {
            cout << i << " ";
        }
    }
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

    int A;
    cin >> A;
    findUnrich(L, A);

    return 0;
}