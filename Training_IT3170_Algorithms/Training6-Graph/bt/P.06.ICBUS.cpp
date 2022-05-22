#include <bits/stdc++.h>
using namespace std;

const int N = 5001;

int n, k;
int C[N], D[N];
using ii =  pair<int, int>;
vector<int> road[N];

vector<ii> new_graph[N];
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<int> iDist(N, 1e9); // memset +oo

void addUndirectedEdge(int u, int v) {
    road[u].push_back(v);
    road[v].push_back(u);
}

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }

    for (int j = 0; j < k; ++j ) {
        int u , v; 
        cin >> u  >> v;
        addUndirectedEdge(u, v);
    }

}

void addDirectedWeight(int u, int v, int w) {
    new_graph[u].push_back({v, w}); // u -> v : w
}

void bfs(int root) {
    int D_tmp[N]; memset(D_tmp, 0, sizeof(D_tmp));
    queue<int> q; q.push(root);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (D_tmp[u] == D[root]) continue;
        for (int i = 0; i < road[u].size(); i++) {
            int v = road[u][i];
            // check v đã thăm và v != root
            if (D_tmp[v] == 0 && v != root) {
                addDirectedWeight(root, v, C[root]);
                D_tmp[v] = D_tmp[u] + 1;
                q.push(v);
            }
        }
    }
   
}

void dijkstra(int start) {
    iDist[start] = 0;
    pq.push({start, iDist[start]});
    while (!pq.empty()) {
        int u = pq.top().first;
        int w_u = pq.top().second;
        pq.pop();
        for (int i = 0; i < new_graph[u].size(); i++) {
            int v = new_graph[u][i].first;
            int w = new_graph[u][i].second;
            if (w + iDist[u] < iDist[v]) {
                iDist[v] = w + iDist[u];
                pq.push({v, iDist[v]});
            }
        }
    }
}

void process() {
    for (int i = 1; i <= n; i++) bfs(i);
    dijkstra(1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    input();
    process();
    cout << iDist[n];
}