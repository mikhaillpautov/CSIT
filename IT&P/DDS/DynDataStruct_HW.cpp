#include <iostream>
#include <unordered_map>
using namespace std;



struct queue {
    int inf;
    queue* next;
};

void push(queue*& head, queue*& tail, int x) {
    queue* r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!head && !tail) {
        head = tail = r;
    } else {
        tail->next = r;
        tail = r;
    }
}

int pop(queue*& head, queue*& tail) {
    queue* r = head;
    int i = head->inf;
    head = head->next;
    if (!head) {
        tail = NULL;
    }
    delete r;
    return i;
}

bool cellExist(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int cellToIndex(string& cell) {
    char colChar = cell[0];
    int row = cell[1] - '1';
    int col = tolower(colChar) - 'a';
    return row * 8 + col;
}

string indexToCell(int index) {
    int row = index / 8;
    int col = index % 8;
    return string(1, 'A' + col) + to_string(row + 1);
}

void hourseway(string& startStr, string& endStr) {
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    queue* head = nullptr;
    queue* tail = nullptr;

    unordered_map<int, pair<int, int>> visited;

    int start = cellToIndex(startStr);
    int end = cellToIndex(endStr);
    push(head, tail, start);
    visited[start] = {0, -1};

    while (head) {
        int now = pop(head, tail);
        int dist = visited[now].first;

        if (now == end) {
            break;
        }

        int x = now % 8;
        int y = now / 8;

        for (int i = 0; i < 8; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (cellExist(newX, newY)) {
                int nextCell = newY * 8 + newX;

                if (visited.find(nextCell) == visited.end()) {
                    push(head, tail, nextCell);
                    visited[nextCell] = {dist + 1, now};
                }
            }
        }
    }

    string path;
    int now = end;
    while (now != -1) {
        path = indexToCell(now) + " " + path;
        now = visited[now].second;
    }

    cout <<  path << endl;
}





int main() {
    string startStr, endStr;
    cin >> startStr;
    cin >> endStr;
    


    hourseway(startStr, endStr);
}