#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int N = 1e5+1;
int n, m;
vector<ii> adj[N]; // danh sách cạnh: adj[u][i].first = v, adj[u][i].second = index of edge
vector<int> low(N), num(N, -1); // -1 : chưa thăm
vector<bool> isBridge(N, false);
int cur_num = 0; // thứ tự duyệt

void input() {
  cin >> n >> m;
  int u , v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

}

// xác định cạnh cầu
// duyệt theo đỉnh u, đỉnh p la đỉnh ngay trước trong thứ tự duyệt DFS
void find_bridge(int u, int p) {
    low[u] = num[u] = ++cur_num;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        int edge_index = adj[u][i].second;
        if (v == p) continue; // ko xét điểm ngay trước trong thứ tự duyệt DFS
        if (num[v] == -1) {
            find_bridge(v, u);
            low[u] = min(low[u], low[v]);
        }  
        else {
            low[u] = min(low[u], num[v]);
        }
        // điều kiên để 1 đỉnh và đỉnh trước nó trong thứ tự duyệt DFS trở thành 1 cầu
        // theo DFS: thứ tự u -> v
        if (low[v] > num[u]) 
            isBridge[edge_index] = true;
    }
}

// 2 đỉnh có thể nối với nhau t/m đề bài 
// <=> đường đi giữa 2 đỉnh đó chỉ chứa các cạnh cầu
// hàm này tính ra số đỉnh x (=cur_num) mà t/m đường đi giữa 2 trong x cạnh này chỉ chứa cạnh cầu
// x-1 vì bỏ qua đỉnh liền kề với đỉnh đang xét => Công thức là C(2, x-1) 
void dfs_count_v_bridge(int u) {
  num[u] = ++cur_num;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i].first;
    int edge_index = adj[u][i].second;
    if (num[v] == -1 && isBridge[edge_index]) {
      dfs_count_v_bridge(v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  input();

  // tìm cầu
  for (int u = 1; u <= n; ++u) {
    if (num[u] == -1) {
      cur_num = 0;
      find_bridge(u, -1); // duyệt dfs tìm cầu cho từng tplt
    }
  }

  num.assign(N, -1);

  // ứng với mỗi tplt tính số cạnh thoả mãn , kết quả sẽ là tổng
  // ct tính cạnh thoả mãn: C(2, x-1) với x là số đỉnh s/c đường đi từ u tới các đỉnh này chỉ chứa cầu
  // ở đây cur_num = x
  ll res = 0;
  for (int u = 1; u <= n; ++u) {
    if (num[u] == -1) {
      cur_num = 0;
      dfs_count_v_bridge(u);
      if (cur_num > 2) {
        res += 1LL * (cur_num - 1) * (cur_num - 2) / 2; 

      }
    }
  }

  cout << res;

}