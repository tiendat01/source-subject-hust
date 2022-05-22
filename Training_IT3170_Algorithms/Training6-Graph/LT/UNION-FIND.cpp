// đồ thị có trọng số

#include <bits/stdc++.h>
using namespace std;

// mặc định, ko quy định rank -> union lung tung
struct Union_Find {
    vector<int> iParent; // lưu phần tử đại diện của 1 collection
    // n đỉnh 1 -> n
    Union_Find(int n) {
        iParent = vector<int>(n+1);
        for (int i = 1; i <= n; i++) {
            iParent[i] = i;
        }
    }

    int Find(int x) {
        if (iParent[x] == x) return x;
        else {
            iParent[x] = Find(iParent[x]);
            return iParent[x];
        }
    }

    void Union(int x, int y) {
        iParent[Find(x)] = Find(y);
    }

    void cout_find(int n) {
        for (int i = 1; i <= n; i++) {
            cout << "Find(" << i << ") = "  << Find(i) << endl;
        }
    }
    
};

// rank implementation
struct Disjoint_Set {
    vector<int> iParent;
    vector<int> rank;

    // default constructor
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





// cài trực tiếp
const int MAX = 30;
/*datastructure disjoint-set*/
long long r[MAX]; // rank
long long p[MAX]; // parent of node

void makeSet(long long x){
    p[x] = x;
    r[x] = 0;
}

void unionSet(long long x, long long y){

    if(r[x] > r[y]){
        p[y] = x;
    } else {
        p[x] = y;
        if(r[x] == r[y]) r[y] += 1;
    }
}

long long findSet(long long x){
    if (p[x] != x){
        p[x] = findSet(p[x]);
    }
    return p[x];
}
/*end datastructure*/