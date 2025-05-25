#include <vector>
#include <iostream>

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

void dfsStack(int v, vector<vector<int>>& L, vector<bool>& visited, stack* &Stack) {
    visited[v] = true;

    for (int neighbor : L[v]) {
        if (!visited[neighbor]) {
            dfsStack(neighbor, L, visited, Stack);
        }
    }

    push(Stack, v);
}

stack* topologicalSort(vector<vector<int>>& L) {
    int V = L.size();
    vector<bool> visited(V, false);
    stack *Stack = nullptr;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfsStack(i, L, visited, Stack);
        }
    }
    
    return Stack;
}

int main() {
    vector<vector<int>> L = {
        {1,2},
        {2,3,4},
        {4,5},
        {6},
        {6},
        {4,7},
        {7,8},
        {8},
        {}
    };

    stack *sorted = topologicalSort(L);

    while (sorted) {
        cout << pop(sorted) << " ";
    }
    cout << endl;

    return 0;
}