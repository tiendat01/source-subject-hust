// undirected graph

#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n, m;
vector<int> adj[N];
vector<int> isVisted(N, -1); // 3 color : -1 , 0 , 1

vector<int> kthCycle(N, -1);
vector<int> parent(N, -1); // đỉnh liền trước theo thứ tự duyệt DFS
int cnt_cycles = 0;

void input() {
  cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void dfs_cycle(int u , int p) {
  // tất cả các đỉnh kề của u đã được duyệt ở trạng thái
  if (isVisted[u] == 1) return ;

  if (isVisted[u] == 0) {
    cnt_cycles++;
    kthCycle[p] = cnt_cycles;
    int tmp = p;
    while (tmp != u) {
      tmp = parent[tmp];
      kthCycle[tmp] = cnt_cycles;
    }

    return ;
  }

  // u chưa được thăm hay isVisted[u] == -1
  isVisted[u] = 0;
  parent[u] = p;

  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs_cycle(v, u);
  }

  isVisted[u] = 1;
}

void print_cycles() {
  if (cnt_cycles < 1) cout << "Không có chu trình";
  for (int i = 1; i <= cnt_cycles; i++) {
    cout << i << "th-Cycle: ";
    for (int u = 1; u <= n; u++) {
      if (kthCycle[u] == i) cout << u << ' ';
    } 
    cout << endl;
  }
}


int main() {
  input();
  
  for (int u = 1; u <= n; u++) {
    if (isVisted[u] == -1) {
      dfs_cycle(u, -1);
    }
  }

  print_cycles();


}


// 13 14
// 1 2
// 2 3
// 3 4
// 4 6
// 4 7
// 5 6
// 3 5
// 7 8
// 6 10
// 5 9
// 10 11
// 11 12
// 11 13
// 12 13