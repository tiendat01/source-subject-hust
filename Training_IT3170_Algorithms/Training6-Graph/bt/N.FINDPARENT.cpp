// duyệt cây theo bfs
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n;
vector<int> adj[N];
vector<int> parent(N, 0);

void input() {
  cin >> n;
  int e = n - 1;
  for (int i = 0; i < e; ++i) {
    int a , b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

void bfs_parent() {
  queue<int> q;
  int root = 1;
  q.push(root); parent[root] = root;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i];
      if (parent[v] == 0) {
        parent[v] = u;
        q.push(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  input();
  bfs_parent();
  for (int i = 2; i <= n; ++i) {
    cout << parent[i] << " ";
  }
}