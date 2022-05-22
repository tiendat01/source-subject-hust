// check đồ thị hai phía nam/nữ

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n, m; // n đỉnh , m cạnh
vector<int> adj[N];
vector<int> iSide(N, -1); // 1thSide or 0thSide
bool is_bipartite = true;

// do thi vo huong:
void addUndirectedEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// dfs
void check_bipartite(int u) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (iSide[v] == -1) {
            iSide[v] = 1 - iSide[u];
            check_bipartite(v);
        }
        else if (iSide[v] == iSide[u]) {
            is_bipartite = false;
            return ;
        }
    }
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >>  u >> v;
        addUndirectedEdge(u, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    for (int u = 1; u <= n; u++) {
        if (iSide[u] == -1) {
            iSide[u] = 0;
            check_bipartite(u);
        }
    }
    if (is_bipartite) cout << 1;
    else cout << 0;
}
