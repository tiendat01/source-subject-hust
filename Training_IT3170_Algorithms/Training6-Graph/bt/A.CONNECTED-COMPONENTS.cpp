// do thi vo huong
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n, m; // n dinh, m canh
vector<int> adj[N];
vector<int> ith_component(N, -1);

void addUndirectedEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        addUndirectedEdge(u, v);
    }
}

void find_ith_component(int ith_comp, int u) {
    if (ith_component[u] != -1) return ;

    ith_component[u] = ith_comp;

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        find_ith_component(ith_comp, v);
    }
}

int main() {
    input();
    int count_comp = 0;
    for (int u = 1; u <= n; u++) {
        if (ith_component[u] == -1) {
            find_ith_component(count_comp, u);
            count_comp++; 
        }
    }
    cout << count_comp;
}