#include <bits/stdc++.h>
#include "EDGE.cpp"
using namespace std;

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

// O(E*log(V))
void Dijkstra(int start) {
    iDistance[start] = 0;
    // first: iDistance = đường đi từ start to đỉnh second, second: đỉnh
    priority_queue< pair<int,int>, 
        vector<pair<int,int>>, greater<pair<int,int>> > pq;
    // sắp xếp pq tăng dần từ đầu hàng đợi

    pq.push(pair(iDistance[start], start));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        // duyệt các đỉnh kề với u _ đỉnh đầu hàng đợi
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].v;
            int w = adj[u][i].weight;
            if (w + iDistance[u] < iDistance[v]) {
                iDistance[v] = w + iDistance[u];
                pq.push(pair(iDistance[v], v));
            }
        }
    }
}


int main() {

}