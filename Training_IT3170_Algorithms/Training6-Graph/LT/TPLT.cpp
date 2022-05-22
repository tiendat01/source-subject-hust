// O(n+m)

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
vector<int> iComponent(1001, -1);
int n; // so dinh

// do thi vo huong:
void addUndirectedEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// do thi co huong : u -> v
void addDirectedEdge(int u, int v) {
    adj[u].push_back(v);
}

// tat ca cac dinh co cung iComponent se thuoc cung 1 tplt
void findComponent(int cur_comp, int u) {
    if (iComponent[u] != -1) return ;

    iComponent[u] = cur_comp;

    cout << u << ' ';

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        findComponent(cur_comp, v);
    }
}

int countTPLT() {
    int num_comp = 0;
    for (int u = 1; u <= n; u++) {
        if (iComponent[u] == -1) {
            cout << "TPLT thu " << num_comp+1 << ": ";
            findComponent(num_comp, u);
            num_comp++;
            cout << endl;
        }
    }
    return num_comp;
}

int main() {
    n = 8;
    addUndirectedEdge(1,2);
    addUndirectedEdge(1,7);
    addUndirectedEdge(1,8);
    addUndirectedEdge(2,7);
    addUndirectedEdge(4,5);
    addUndirectedEdge(4,6);
    addUndirectedEdge(5,6);
    addUndirectedEdge(7,8);

    cout << countTPLT();
}
