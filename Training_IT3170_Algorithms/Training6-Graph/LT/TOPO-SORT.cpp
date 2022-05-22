// có n công việc (n đỉnh) , mỗi công việc i cần có các d/s các
// cv j khác cần hoàn thành trước
// i -> j là 1 cạnh của đồ thị có hướng
// tìm trình tự (đường đi) để thực hiện tất cả cv (duyệt các tất cả các đỉnh)
// nếu đồ thị có hướng tồn tại chu trình => ko có trình tự thực hiện cv thoả mãn

// O(n + m)

#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

vector<int> adj[N];
vector<bool> bVisited(N, false);
vector<int> iOrder; // thứ tự thực hiện cv

// do thi co huong : u -> v
void addDirectedEdge(int u, int v) {
    adj[u].push_back(v);
}

void topo_sort(int u) {
    if (bVisited[u]) return ; // đã thăm

    // DFS cho đồ thị có hướng
    bVisited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        topo_sort(v);
    }
    // lưu trình tự thực hiện
    iOrder.push_back(u);
}

int main() {

    addDirectedEdge(3,4);
    addDirectedEdge(4,2);
    addDirectedEdge(5,1);
    addDirectedEdge(5,2);
    addDirectedEdge(6,1);
    addDirectedEdge(6,3);

    int v = 6; // số đỉnh

    for (int u = 1; u <= v; u++) {
        if (!bVisited[u])
            topo_sort(u);
    }

    // in ra thứ tự thực hiệN cv
    for (int i = 0; i < iOrder.size(); ++i) {
        cout << setw(2) << iOrder[i] << ' ';
    }
}