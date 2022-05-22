// tính chất của cây: chỉ có 1 đường đi duy nhất giữa 2 đỉnh bất kỳ trong cấy

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

const int N = 1e5+1;
int n;
vector<ii> adj[N];
vector<int> iDist(N, 0);
vector<bool> isVisited(N, false);
int longest_path = 0;


void input() {
  cin >> n;
  int u, v, w;
  for (int i = 1; i <= n-1; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
}

void dfs(int u, int p) {
  if (isVisited[u]) return ;
  isVisited[u] = true;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i].first, w = adj[u][i].second;
    if (v == p) continue;
    iDist[v] = iDist[u] + w;
    dfs(v, u);
  }
}

// trả về 1 đỉnh trong đường đi dài nhất
int find_v_max() {
  int max_dist_from1 = 0;
  int v_max_from1 = 1;
  for (int i = 1; i <= n; i++) {
    if (max_dist_from1 < iDist[i]) {
      v_max_from1 = i;
      max_dist_from1 = iDist[i];
    }
  }

  return v_max_from1;
}

void init() {
  iDist.assign(N, 0);
  isVisited.assign(N, false);
}


int main() {
  input();
  dfs(1, -1); // duyệt dfs từ đỉnh 1, tìm đường đi từ đỉnh 1 tới các đỉnh

  int v_max = find_v_max();

  init();

  dfs(v_max, -1);

  for (int i = 1; i <= n; i++) {
    longest_path = max(longest_path, iDist[i]);
  }

  cout << longest_path;
}