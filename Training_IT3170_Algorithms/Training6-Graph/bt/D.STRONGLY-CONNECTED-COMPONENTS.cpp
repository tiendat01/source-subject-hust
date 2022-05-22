// Áp dụng tìm tplt mạnh trong đồ thị có huơgns
// O(n+m)
// dựa vào việc phân tích cây DFS:

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n, m; // n đỉnh m cạnh
vector<int> adj[N];
vector<int> low(N), num(N, -1); // -1 : chưa thăm
int cur_num = 0; // thứ tự duyệt
vector<bool> bConnect (N, false); // kiểm tra xem đỉnh v còn đc kết nối với đồ thị hay ko
// nếu tìm đc 1 tplt mạnh và đỉnh v thuộc tplt mạnh đó
// ta loại đỉnh v khỏi đồ thị : bConnect[v] = false;

int countTPLTM = 0;

stack<int> iComp;

// do thi co huong : u -> v
void addDirectedEdge(int u, int v) {
    adj[u].push_back(v);
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v ; cin >> u >> v;
        addDirectedEdge(u,v);
    }
}


void SCC(int u) {
    iComp.push(u);
    bConnect[u] = true; // thuộc đồ thị
    
    // tính low và num
    low[u] = num[u] = ++cur_num;
    for (int i = 0; i < adj[u].size(); ++i) {
        // do là đồ thị có hướng nên ko cần check đỉnh duyệt trước của v
        int v = adj[u][i];
        // v chưa connect với đồ thị, chưa đc duyệt
        if (num[v] == -1) {
            SCC(v);
            low[u] = min(low[u], low[v]);
        }  
        // v đã connect với đồ thị
        else if (bConnect[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    // tìm thấy tplt mạnh:
    if (num[u] == low[u]) {
        while (true) {
            int cur_vertice = iComp.top();
            iComp.pop();
            bConnect[cur_vertice] = false; // nếu đỉnh thuộc tplt mạnh đã tìm thấy, loại ra khỏi đồ thị
            if (cur_vertice == u) break;
        }

        countTPLTM++;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    for (int u = 1; u <= n; u++) {
        // u chưa được thăm
        if (num[u] == -1) {
            SCC(u);
        }
        
    }
    cout << countTPLTM;
}