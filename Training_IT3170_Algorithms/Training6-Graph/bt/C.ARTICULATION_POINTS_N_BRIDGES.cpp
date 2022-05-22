// O(n + m)

// dựa theo t/t phân tích cây DFS, tìm low[] để xác định cầu

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;

int n, m; // n đỉnh m cạnh
vector<int> adj[N];
vector<int> low(N), num(N, -1); // -1 : chưa thăm
int cur_num = 0; // thứ tự duyệt
// vector<pair<int, int>> iiBridges; // first -> second: is a bridge

vector<bool> b_in_apoints(N, false);
int count_bridge = 0, count_a_point = 0;


// do thi vo huong:
void addUndirectedEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void input() {
    cin >> n >> m;
    for (int e = 0; e < m; ++e) {
        int u, v; cin >> u >> v;
        addUndirectedEdge(u, v);
    }
}

// duyệt theo đỉnh u, đỉnh p la đỉnh ngay trước trong thứ tự duyệt DFS
void find_bridge(int u, int p) {

    int children_of_u = 0;

    low[u] = num[u] = ++cur_num;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p) continue; // ko xét điểm ngay trước trong thứ tự duyệt DFS
        if (num[v] == -1) {
            children_of_u++;
            find_bridge(v, u);
            low[u] = min(low[u], low[v]);
            // điều kiên để 1 đỉnh và đỉnh trước nó trong thứ tự duyệt DFS trở thành 1 cầu
            // theo DFS: thứ tự u -> v
            if (low[v] > num[u]) count_bridge++;

            // u -> v trong cây dfs:
            // nếu low[v] >= num[u] có 2 TH để u là a_point:
            // TH2: - u là root và có ít nhất 2 con     
            if (p == -1) {
                if (children_of_u >= 2) b_in_apoints[u] = true;
            }
            // TH1: - u ko là root 
            else {
                if (low[v] >= num[u]) b_in_apoints[u] = true;
            }

        }  
        else {
            low[u] = min(low[u], num[v]);
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();

    for (int u = 1; u <= n; u++) {
        // tplt
        if (num[u] == -1) {
            find_bridge(u, -1);
        }
        
    }

    // for (int u = 1; u <= n; u++) {
    //     cout << num[u] << ' ';
    // }
    // cout << endl;
    // for (int u = 1; u <= n; u++) {
    //     cout << low[u] << ' ';
    // }


    for(int u = 1; u <= n; ++u) {
        if (b_in_apoints[u]) { count_a_point++;
        // cout << u << endl;
        }
        
    }

    cout << count_a_point << ' ' << count_bridge;

}