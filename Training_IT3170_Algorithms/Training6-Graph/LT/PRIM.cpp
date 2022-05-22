#include <bits/stdc++.h>
#include "UNION-FIND.cpp"
#include "EDGE.cpp"
using namespace std;

// O(V^2)
// mỗi phần tử adj[v] là 1 tập các cạnh chứa đỉnh v
vector<edge> Prim(int n, vector< vector<edge> > adj) {
    vector<bool> isInTree(n+1, false);
    vector<edge> mst;
    vector<int> iBest_W(n+1, 1e9); // iBest_W[v]: k/c tu v tới mst
    vector<int> iBest_Adj(n+1, -1); // iBest_Adj[v]: đỉnh gần v nhất trong mst

    iBest_W[1] = 0; // bắt đầu duyệt từ đỉnh 1, nhg chưa thêm vào mst
    // cây có số cạnh E = số đỉnh V - 1
    while(mst.size() < n-1) {
        int u = -1, v = -1, w = 1e9;
        for (int x = 1; x <= n; ++x) {
            // chọn đỉnh x chưa được thêm vào mst, và cạnh chứa x có trọng số nhỏ nhất w min
            if (isInTree[x] == false && iBest_W[x] < w) {
                u = iBest_Adj[x], v = x, w = iBest_W[x];
            }
        }
        if (v == -1) return mst; // do thi ko lien thong (rừng)

        isInTree[v] = true; /// cho đỉnh v vào cây
        // cập nhật các đỉnh kề với v (ở trên)
        for (edge e : adj[v]) {
            // e.v là các đỉnh kề với v (v ở trên)
            // e.u chính là đỉnh v (v ở trên)
            if (iBest_W[e.v] > e.weight) {
                iBest_W[e.v] = e.weight;
                iBest_Adj[e.v] = v; // or e.u
            }
        }

        if (v != 1) mst.push_back(edge(u, v, w));

    }

    return mst;
}



// O((V + E)*log(V))
vector<edge> Prim1(int n, vector< vector<edge> > adj) {

    // first: weight, second: đỉnh
    priority_queue< pair<int,int> , 
        vector<pair<int,int>>, greater<pair<int,int>> > pq;

    vector<edge> mst;
    vector<int> iBest_W(n+1, 1e9); // iBest_W[v]: k/c tu v tới mst
    vector<int> iBest_Adj(n+1, -1); // iBest_Adj[v]: đỉnh gần v nhất trong mst

    iBest_W[1] = 0; 
    pq.push(pair(iBest_W[1], 1));

    while (mst.size() < n-1) {
        while (!pq.empty() && 
            pq.top().first != iBest_W[pq.top().second])  {
                pq.pop();
        }

        if (pq.empty()) return mst; // đồ thị ko liên thông (rừng)

        int w = pq.top().first, v = pq.top().second, u = iBest_Adj[v];
        for (edge e : adj[v]) {
            if (iBest_W[e.v] > e.weight) {
                iBest_W[e.v] = e.weight;
                iBest_Adj[e.v] = e.u;

                pq.push(pair(iBest_W[e.v], e.v));
            }
        }

        if (v != 1) mst.push_back(edge(u, v, w));
    }

    return mst;

}

int main() {
    vector< vector<edge> > adj;
    vector<edge> tmp;

    int n = 7;
    adj.resize(n+1);

    tmp.push_back(edge(1, 2, 7));
    tmp.push_back(edge(1, 4, 5));
    adj[1] = tmp;
    tmp.clear();

    tmp.push_back(edge(2, 1, 7));
    tmp.push_back(edge(2, 3, 8));
    tmp.push_back(edge(2, 4, 9));
    tmp.push_back(edge(2, 5, 7));
    adj[2] = tmp;
    tmp.clear();

    tmp.push_back(edge(3, 2, 8));   
    tmp.push_back(edge(3, 5, 5));
    adj[3] = tmp;
    tmp.clear();

    tmp.push_back(edge(4,1,5));
    tmp.push_back(edge(4,2,9));
    tmp.push_back(edge(4,5,15));
    tmp.push_back(edge(4,6,6));
    adj[4] = tmp;
    tmp.clear();


    tmp.push_back(edge(5,2,7));
    tmp.push_back(edge(5,3,5));
    tmp.push_back(edge(5,4,15));
    tmp.push_back(edge(5,6,8));
    tmp.push_back(edge(5,7,9));
    adj[5] = tmp;
    tmp.clear();

    tmp.push_back(edge(6,4,6));
    tmp.push_back(edge(6,5,8));
    tmp.push_back(edge(6,7,11));
    adj[6] = tmp;
    tmp.clear();

    tmp.push_back(edge(7,5,9));
    tmp.push_back(edge(7,6,11));
    adj[7] = tmp;
    tmp.clear();

    vector<edge> mst = Prim(n, adj);
    for (int i = 0; i < mst.size(); i++) {
        mst[i].cout_edge();
    }

}