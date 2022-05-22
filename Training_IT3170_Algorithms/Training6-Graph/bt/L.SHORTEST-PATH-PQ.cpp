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

const int N = 1e6+1;

int n, m;
vector<edge> adj[N];
vector<int> iDistance(N, 1e9);
int s, t;

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


void input() {
  cin >> n >> m;
  int u, v , w;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    adj[u].push_back(edge(u, v, w));
  }
  cin >> s >> t;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  input();
  Dijkstra(s);
  if (iDistance[t] < 1e9)
    cout << iDistance[t];
  else cout << -1;
  
}