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

vector<edge> adj[100];
vector<int> iDistance(100, 1e9);

void addUndirectedEdge(int u, int v, int weight1, int weight2) {
    adj[u].push_back(edge(u, v, weight1));
    adj[v].push_back(edge(v, u, weight2));
}

// u -> v
void addDirectedEdge(int u, int v, int weight) {
    adj[u].push_back(edge(u, v, weight));
}

// O(V * E)
void BellmanFord(int n, int start) {
    iDistance[start] = 0;
    for (int i = 1; i < n-1; ++i) {
        for (int u = 1; u <= n; ++u) {
            // u kề v
            for (int j = 0; j < adj[u].size(); ++j) {
                int v = adj[u][j].v;
                int w = adj[u][j].weight;
                iDistance[v] = min(iDistance[v], w + iDistance[u]);
            }
        }
    }
}