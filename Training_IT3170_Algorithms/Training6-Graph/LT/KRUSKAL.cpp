// Tìm cây khung nhỏ nhất của đồ thị vô hướng
// O(E*log(V))

#include <bits/stdc++.h>
#include "UNION-FIND.cpp"
#include "EDGE.cpp"
using namespace std;

bool comp_edgew(const edge &e1, const edge &e2) {
    return e1.weight < e2.weight;
}

// trả về ds cạnh, n đỉnh
vector<edge> Kruskal(int n, vector<edge> graph) {
    Union_Find collections = Union_Find(n+1);
    sort(graph.begin(), graph.end(), comp_edgew);

    vector<edge> mst;
    // duyệt các cạnh
    for (int i = 0; i < graph.size(); i++) {
        int u = graph[i].u, v = graph[i].v;

        // u, v thuộc cùng collection (cây) khi Find(u) == Find(v)
        // đảm bảo khi thêm các cạnh vào mst, sẽ ko có chu trình xảy ra
        if (collections.Find(u) != collections.Find(v)) {
            collections.Union(u, v);
            mst.push_back(graph[i]);
        }
    }
    return mst;
}

int main() {
    int n = 7; // số đỉnh

    vector<edge> graph; // đồ thị vô hướng
    graph.push_back(edge(1,2,7));
    graph.push_back(edge(1,4,5));
    graph.push_back(edge(2,3,8));
    graph.push_back(edge(2,4,9));
    graph.push_back(edge(2,5,7));
    graph.push_back(edge(3,5,5));
    graph.push_back(edge(4,5,15));
    graph.push_back(edge(4,6,6));
    graph.push_back(edge(5,6,8));
    graph.push_back(edge(5,7,9));
    graph.push_back(edge(6,7,11));

    vector<edge> mst = Kruskal(n, graph);

    for (int i = 0; i < mst.size(); i++) {
        mst[i].cout_edge();
    }

}