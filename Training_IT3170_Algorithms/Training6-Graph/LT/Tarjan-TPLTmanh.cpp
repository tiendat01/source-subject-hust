// Áp dụng tìm tplt mạnh trong đồ thị có huơgns
// O(n+m)
// dựa vào việc phân tích cây DFS:

#include <bits/stdc++.h>
using namespace std;

const int n = 1001;
vector<int> adj[n];
vector<int> low(n), num(n, -1); // -1 : chưa thăm
int cur_num = 0; // thứ tự duyệt
vector<bool> bConnect (n, false); // kiểm tra xem đỉnh v còn đc kết nối với đồ thị hay ko
// nếu tìm đc 1 tplt mạnh và đỉnh v thuộc tplt mạnh đó
// ta loại đỉnh v khỏi đồ thị : bConnect[v] = false;

stack<int> iComp;

// do thi co huong : u -> v
void addDirectedEdge(int u, int v) {
    adj[u].push_back(v);
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
        cout << "TPLT: ";
        while (true) {
            int cur_vertice = iComp.top();
            iComp.pop();
            bConnect[cur_vertice] = false; // nếu đỉnh thuộc tplt mạnh đã tìm thấy, loại ra khỏi đồ thị
            cout << cur_vertice << ' ';
            if (cur_vertice == u) break;
        }
        cout << endl;
    }
    
}

int main() {

    addDirectedEdge(1,2);
    addDirectedEdge(2,3);
    addDirectedEdge(3,1);
    addDirectedEdge(3,4);
    addDirectedEdge(4,6);
    addDirectedEdge(6,5);
    addDirectedEdge(6,7);
    addDirectedEdge(6,9);
    addDirectedEdge(5,8);
    addDirectedEdge(8,11);
    addDirectedEdge(11,5);
    addDirectedEdge(7,9);
    addDirectedEdge(7,10);
    addDirectedEdge(9,4);

    int v = 11; // số đỉnh

    for (int u = 1; u <= v; u++) {
        // u chưa được thăm
        if (num[u] == -1) {
            SCC(u);
        }
        
    }
}