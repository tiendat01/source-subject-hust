// O(n + m)

// dựa theo t/t phân tích cây DFS, tìm low[] để xác định cầu

#include <bits/stdc++.h>
using namespace std;

const int n = 1001;
vector<int> adj[n];
vector<int> low(n), num(n, -1); // -1 : chưa thăm
int cur_num = 0; // thứ tự duyệt
vector<pair<int, int>> iiBridges; // first -> second: is a bridge

// do thi vo huong:
void addUndirectedEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// duyệt theo đỉnh u, đỉnh p la đỉnh ngay trước trong thứ tự duyệt DFS
void find_bridge(int u, int p) {
    low[u] = num[u] = ++cur_num;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
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
            iiBridges.push_back({u, v});
    }
}

int main() {
    addUndirectedEdge(1,2);
    addUndirectedEdge(1,3);
    addUndirectedEdge(2,3);
    addUndirectedEdge(3,4);
    addUndirectedEdge(4,6);
    addUndirectedEdge(4,9);
    addUndirectedEdge(6,5);
    addUndirectedEdge(6,7);
    addUndirectedEdge(6,9);
    addUndirectedEdge(5,8);
    addUndirectedEdge(5,11);
    addUndirectedEdge(7,9);
    addUndirectedEdge(7,10);
    addUndirectedEdge(8,11);

    int v = 11; // số đỉnh

    for (int u = 1; u <= v; u++) {
        // tplt
        if (num[u] == -1) {
            find_bridge(u, -1);
            // cout << "check"; // đồ thị trên chỉ có 1 tplt
        }
        
    }

    // in ra cầu theo thứ tự duyệt DFS giữa 2 đỉnh u -> v
    for (int i = 0; i < iiBridges.size(); i++) {
        cout << iiBridges[i].first << " -> " << iiBridges[i].second << endl;
    }
}