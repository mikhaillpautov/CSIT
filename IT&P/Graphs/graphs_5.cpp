#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void findShort(vector<vector<int>>& Gr, int A, int B) {
    int n = Gr.size();
    vector<bool> used(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    used[A] = true;
    q.push(A);
    parent[A] = -1;

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        for (int i = 0; i < Gr[y].size(); ++i) {
            if (!used[Gr[y][i]]) {
                used[Gr[y][i]] = true;
                parent[Gr[y][i]] = y;
                q.push(Gr[y][i]);

                if (Gr[y][i] == B) {
                    break;
                }
            }
        }
    }

    vector<int> path;
    int v = B;
    while (v != -1) {
        path.push_back(v);
        v = parent[v];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    cout << endl;
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

    int A, B;
    cin >> A >> B;
    findShort(L, A, B);

    return 0;
}
