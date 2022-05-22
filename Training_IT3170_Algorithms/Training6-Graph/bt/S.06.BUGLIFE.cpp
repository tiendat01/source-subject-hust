// check có phải là đồ thị nam-nữ
// tô màu đồ thị bằng 2 màu = duyệt DFS
// tô xog check xem 2 đỉnh kề nhau có cùng màu => ko là đồ thị nam-nữ

#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
const int M = 1e6+1;

int n, m; // n : số bugs (Số đỉnh), m : số interactions (số cạnh)
vector<int> adj[N];
vector<int> color(N, -1); // 0 hoặc 1 hoặc -1(chưa tô)
bool is_bipartite = true;

// do thi vo huong:
void addUndirectedEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// ban đầu từ đỉnh đầu tiên sẽ đc tô màu 0
void check_bipartite(int u) {
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (color[v] == -1) {
            color[v] = 1 - color[u];
            check_bipartite(v);
        }
        else if (color[v] == color[u]) {
            is_bipartite = false; // 2 đỉnh u,v kề nhau cùng màu
            return ;
        }
    }
}


void input() {
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    color.clear();
    color.assign(N, -1);
    is_bipartite = true;

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        addUndirectedEdge(a, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); // 100points
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        for (int u = 1; u <= n; u++) {
            // chưa tô 
            if (color[u] == -1) {
                color[u] = 0; // tô màu cho đỉnh đầu tiên duyệt
                check_bipartite(u);
            } 
        }
        if (is_bipartite) cout << "Scenario #" << t << ":\nNo suspicious bugs found!\n";
        else cout << "Scenario #" << t << ":\nSuspicious bugs found!\n";
    }
}