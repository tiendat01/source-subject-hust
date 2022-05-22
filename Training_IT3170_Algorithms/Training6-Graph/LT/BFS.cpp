// O(n + m)

#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

vector<int> adj[N];
vector<bool> bVisited(N, false);

queue<int> Q;

void addDirectedEdge(int u, int v) {
    adj[u].push_back(v);
}

void BFS(int start) {
    Q.push(start);
    bVisited[start] = true;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        cout << u << ' ';
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            // nếu chưa thăm
            if (!bVisited[v]) {
                Q.push(v);
                bVisited[v] = true;
            }
        }
    }
}

int main() {

    addDirectedEdge(1,2);
    addDirectedEdge(1,3);
    addDirectedEdge(2,5);
    addDirectedEdge(3,2);
    addDirectedEdge(3,4);
    addDirectedEdge(4,1);
    addDirectedEdge(5,6);
    addDirectedEdge(6,3);
    addDirectedEdge(6,4);
    addDirectedEdge(6,7);
    addDirectedEdge(6,8);
    addDirectedEdge(6,9);
    addDirectedEdge(7,8);
    addDirectedEdge(7,9);
    addDirectedEdge(8,11);
    addDirectedEdge(9,10);
    addDirectedEdge(10,9);

    int v = 11; // số đỉnh

    for (int u = 1; u <= v; u++) {
        if (!bVisited[u]) 
            BFS(u);
    }
}