// O(n + m)

// phân tích cây DFS: tính:
// num[u] = thứ tự duyệt các đỉnh của DFS
// low[u] = chỉ số của đỉnh nhỏ nhất mà u có thể chạm được (bởi 1 cạnh ngược)
// khi tiếp tục duyệt theo cây con có gốc tại u

#include<bits/stdc++.h>
using namespace std;
const int n = 1001;
vector<int> adj[n];
vector<int> low(n), num(n, -1); // -1 : chưa thăm
int cur_num = 0; // thứ tự duyệt


// do thi vo huong:
void addUndirectedEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// duyệt theo đỉnh u, đỉnh p la đỉnh ngay trước trong thứ tự duyệt DFS
void analyzeDFS(int u, int p) {
    low[u] = num[u] = ++cur_num;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v == p) continue; // ko xét điểm ngay trước trong thứ tự duyệt DFS
        // chưa thăm
        if (num[v] == -1) {
            analyzeDFS(v, u);
            cout << v << "<---" << u << endl;
            low[u] = min(low[u], low[v]);
        }  
        else {
            // đã thăm , cạnh ngược
            cout << v << "<---" << u << "da tham" << endl;
            low[u] = min(low[u], num[v]);
        }
    }
}

void coutVector(vector<int> vt, int v) {
    for (int i = 1; i <= v; ++i) {
        cout << setw(2) << vt[i] << ' ';
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
            analyzeDFS(u, -1);
            // cout << "check"; // đồ thị trên chỉ có 1 tplt
        }
        
    }

    coutVector(num, v);
    cout << endl;
    coutVector(low, v);

}