// O(n+m)

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
vector<bool> isVisited(1001, false);
vector<bool> isVisitedAdj(1001, false);

// do thi vo huong:
void addUndirectedEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// do thi co huong : u -> v
void addDirectedEdge(int u, int v) {
    adj[u].push_back(v);
}


void DFS(int u) {
    if (isVisitedAdj[u])
        return ; // da duyet cac dinh ke voi u
    isVisitedAdj[u] = true;
    isVisited[u] = true;
    cout << u << ' ';
    // duyet cac dinh v ke voi dinh u
    for(int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        isVisited[v] = true;
        DFS(v);
    }
}

void DFS_ver2(int u) {
    // cách 1
    isVisited[u] = true;
    cout << u << ' ';
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!isVisited[v]) {
            DFS_ver2(v);
        }
    }


    // cách 2:
    // if (isVisited[u]) return ;
    //
    // isVisited[u] = true;
    // cout << u << ' ';
    // for (int i = 0; i < adj[u].size(); ++i) {
    //     int v = adj[u][i];
    //     DFS_ver2(v);
    // }
}


int main() {
    addDirectedEdge(1,2);
    addDirectedEdge(1,3);
    addDirectedEdge(3,2);
    addDirectedEdge(3,4);
    addDirectedEdge(2,5);
    addDirectedEdge(4,1);
    addDirectedEdge(5,6);
    addDirectedEdge(6,3);
    addDirectedEdge(6,4);
    addDirectedEdge(6,7);
    addDirectedEdge(6,8);
    addDirectedEdge(6,9);
    addDirectedEdge(9,10);
    addDirectedEdge(7,9);
    addDirectedEdge(7,8);
    addDirectedEdge(8,11);
    addDirectedEdge(10,9);

    // DFS(1);
    DFS_ver2(1);
}

