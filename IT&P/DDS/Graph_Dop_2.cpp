#include <iostream>
#include <vector>
using namespace std;

struct queue {
    int inf;
    queue* next;
};

void push(queue *&h, queue *&t, int x) {
    queue *r = new queue;
    r->inf = x;
    r->next = NULL;
    if(!h && !t) {
        h = t = r;
    }
    else {
        t ->next = r;
        t = r;
    }
}

int pop(queue *&h, queue *&t) {
    queue *r = h;
    int i = h->inf;
    h = h->next;
    if(!h) {
        t = NULL;
    }
    delete r;
    return i;
}

bool visiting(vector<bool> &v, int x) {
    return v[x] = true;
}

bool checkVisit(vector<bool> &v, int x) {
    return v[x];
}

void nerec_obh_v_glub(vector<vector<int>> &v, int first) {
    int n = v.size();
    queue *h = NULL;
    queue *t = NULL;
    vector<bool> vis_ver(n, false);
    push(h, t, first);
    visiting(vis_ver, first);

    while(h) {
        int now = pop(h, t);
        cout << now << " ";
        for(int i = v[now].size() - 1; i >= 0; --i) {
            int sosed = v[now][i];
            if(!checkVisit(vis_ver, sosed)) {
                push(h, t, sosed);
                visiting(vis_ver, sosed);
            }
        }
    }
    cout << endl;
}

/*
void printQueue(queue *h, queue *t) {
    while(h) {
        int x = pop(h, t);
        cout << x << " ";
        h = h->next;
    }
    cout << endl;
}
*/


int main() {
    vector<vector<int>> graph = {
        {4},                //0
        {8, 6, 9},          //1
        {6,4},              //2
        {6, 9 ,5},          //3
        {0, 2, 7, 10},      //4
        {10, 3},            //5
        {8, 1, 3, 2, 7},    //6
        {6, 4, 10},         //7
        {1, 6},             //8
        {1, 3},             //9
        {4, 7, 5}           //10
    };

    nerec_obh_v_glub(graph, 0);
}