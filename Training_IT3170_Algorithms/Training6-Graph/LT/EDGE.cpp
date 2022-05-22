#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v; 
    int weight;

    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }

    void cout_edge() {
        cout << u << " - " << v << "(" << weight << ")" << endl;
    }
};

void addDirectEdge(vector<edge> adj[], int u, int v, int w) {
    adj[u].push_back(edge(u, v, w));
}

void addUndirectEdge(vector<edge> adj[], int u, int v, int w) {
    adj[u].push_back(edge(u, v, w));
    adj[v].push_back(edge(v, u, w));
}