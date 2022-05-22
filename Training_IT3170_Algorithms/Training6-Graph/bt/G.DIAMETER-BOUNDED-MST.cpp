#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v; 
    int weight;

    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }

};


// rank implementation
struct Disjoint_Set {
    vector<int> iParent;
    vector<int> rank;

    Disjoint_Set() {

    }

    // n đỉnh 1 -> n
    Disjoint_Set(int n) {
        iParent = vector<int>(n+1);
        rank = vector<int>(n+1);
        for (int i = 1; i <= n; i++) {
            iParent[i] = i;
            rank[i] = 0;
        }
    }
    // khử đệ quy
    int Find(int x) {
        while (iParent[x] != x) {
            iParent[x] = iParent[iParent[x]];
            x = iParent[x]; 
        }
        return x;
    }
    
    void Union(int x, int y) {
        int rx = iParent[x], ry = iParent[y];
        if (rx == ry) return ; // cùng thuộc 1 collections

        if (rank[rx] > rank[ry]) // rank cao hơn làm cha
            iParent[ry] = rx;
        else {
            iParent[rx] = ry;
            if (rank[rx] == rank[ry]) rank[ry]++;
        }
    }

    void cout_find(int n) {
        for (int i = 1; i <= n; i++) {
            cout << "Find(" << i << ") = "  << Find(i) << endl;
        }
    }

};