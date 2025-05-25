#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stack {
    int inf;
    stack *next;
};

void push(stack *& h, int X) {
    stack *r = new stack;
    r->inf = X;
    r->next = h;
    h = r;
}

int pop(stack *& h) {
    int X = h->inf;
    stack *p = h;
    h = h->next;
    delete p;
    return X;
}

void reverse(stack *& h) {
    stack *h1 = nullptr;
    while (h) {
        push(h1, pop(h));
    }
    h = h1;
}

void remove_edge(vector<vector<int>>& l, int u, int v) {
    auto it = find(l[u].begin(), l[u].end(), v);
    if (it != l[u].end()) {
        l[u].erase(it);
    }

    it = find(l[v].begin(), l[v].end(), u);
    if (it != l[v].end()) {
        l[v].erase(it);
    }
}

vector<int> find_eulerian_path(vector<vector<int>> l) {
    vector<int> path;
    int odd_degree_count = 0;
    int start = 0;

    for (int i = 0; i < l.size(); ++i) {
        if (l[i].size() % 2 != 0) {
            odd_degree_count++;
            start = i;
        }
    }

    if (odd_degree_count != 0 && odd_degree_count != 2) {
        return {};
    }
    stack *st = nullptr;
    push(st, start);

    while (st) {
        int v = st->inf;

        if (!l[v].empty()) {
            int u = l[v].back();
            push(st, u);
            remove_edge(l, v, u);
        } else {
            path.push_back(pop(st));
        }
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
        //NOTHING
    /*
     vector<vector<int>> L = {
        {3, 4, 5, 7},   // 0
        {3, 8},         // 1
        {4, 7, 9},      // 2
        {0, 1, 7, 10},  // 3
        {0, 2, 6},      // 4
        {0, 6, 10},     // 5
        {4, 5},         // 6
        {0, 2, 3, 8, 9},// 7
        {1, 7, 9},      // 8
        {2, 7, 8},      // 9
        {3, 5}          // 10
    };*/

    //CYCLE
     /*vector<vector<int>> L = {
        {1,2},      //0
        {0,2,4,6},  //1
        {0,1,3,4},  //2
        {2,4},      //3
        {1,2,3,5},  //4
        {4,6},      //5
        {1,5}       //6
    };*/

            //PATH
    
    vector<vector<int>> L = {
        {1,2},      //0
        {0,2,3},    //1
        {0,1,4},    //2
        {1,4},      //3
        {2,3}       //4
    };


    vector<int> euler_path = find_eulerian_path(L);

    if (euler_path.empty()) {
        cout << "No cycle or path" << endl;
    } else {
        if (euler_path.front() == euler_path.back()) {
            cout << "cycle: ";
        } else {
            cout << "path: ";
        }

        for (size_t i = 0; i < euler_path.size(); ++i) {
            cout << euler_path[i];
            if (i != euler_path.size() - 1) {
                cout << " - ";
            }
        }
        cout << endl;
    }

    return 0;
}