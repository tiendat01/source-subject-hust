// // 40 points??? TLE (ko nên dùng)

// duyệt nhánh cận kruskal
// #include <bits/stdc++.h>
// using namespace std;

// struct edge {
//     int u, v; 
//     int weight;

//     edge(int _u, int _v, int _w) {
//         u = _u;
//         v = _v;
//         weight = _w;
//     }

//     void cout_edge() {
//         cout << u << " - " << v << "(" << weight << ")" << endl;
//     }
// };

// void addDirectEdge(vector<edge> adj[], int u, int v, int w) {
//     adj[u].push_back(edge(u, v, w));
// }

// void addUndirectEdge(vector<edge> adj[], int u, int v, int w) {
//     adj[u].push_back(edge(u, v, w));
//     adj[v].push_back(edge(v, u, w));
// }


// struct Union_Find {
//     vector<int> iParent; // lưu phần tử đại diện của 1 collection
//     Union_Find(int n) {
//         iParent = vector<int>(n+1);
//         for (int i = 1; i <= n; i++) {
//             iParent[i] = i;
//         }
//     }

//     int Find(int x) {
//         if (iParent[x] == x) return x;
//         else {
//             iParent[x] = Find(iParent[x]);
//             return iParent[x];
//         }
//     }

//     void Union(int x, int y) {
//         iParent[Find(x)] = Find(y);
//     }

//     void cout_find(int n) {
//         for (int i = 1; i <= n; i++) {
//             cout << "Find(" << i << ") = "  << Find(i) << endl;
//         }
//     }
    
// };

// const int N = 21;
// const int M = 31;
// vector<edge> edges;

// bool isAdded[M];
// Union_Find collections = Union_Find(N);

// int n, m, k; // n đỉnh, m cạnh, // k-mst has k edges
// int min_w = INT_MAX;
// int cur_w = 0;
// int kiluc = INT_MAX;

// bool myCompare(edge a , edge b) {
//     return a.weight < b.weight;
// }

// void input() {
//     cin >> n >> m >> k;
//     int u, v, w;
//     for (int i = 0; i < m; i++) {
//         cin >> u >> v >> w;
//         edges.push_back(edge(u, v, w));
//         min_w = min(min_w, w);
//     }
//     sort(edges.begin(), edges.end(), myCompare);
// }

// bool check_connected() {
//     bool isInMST[N];
//     memset(isInMST, false, sizeof(isInMST));
//     int tmp = 0;
//     for (int j = 0; j < edges.size(); ++j) {
//         if (isAdded[j]) {
//             isInMST[edges[j].u] = true, isInMST[edges[j].v] = true;
//             tmp = edges[j].v;
//         }
//     }
//     // các đỉnh
//     int cur = collections.Find(tmp);
//     for (int i = 1; i <= n; i++) {
//         if (isInMST[i]) {
//             if (collections.Find(i) != cur) return false;
//         }
//     }
//     return true;
// }

// void solution() {
//     if (check_connected()) 
//         kiluc = min(kiluc, cur_w);
// }

// // lời giải cấp k là thêm 1 cạnh thứ k
// void Try(int loigiaicapk) {
//     for (int j = loigiaicapk-1; j < m; j++) {
//         int u = edges[j].u, v = edges[j].v, w = edges[j].weight;
//         if (!isAdded[j] && collections.Find(u) != collections.Find(v)) {
//             isAdded[j] = true;         
//             Union_Find prev = collections;
//             collections.Union(u, v);
//             cur_w += w;

//             if (loigiaicapk == k) {
//                 solution();
//             }
//             else {
//                 // nhánh cận
//                 if (kiluc > cur_w + (k - loigiaicapk) * min_w) 
//                     Try(loigiaicapk+1);
//             }

//             isAdded[j] = false;
//             collections = prev;
//             cur_w -= w;
            
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     input();
//     Try(1);
//     cout << kiluc;
// }






// // dùng Prim 100 points
// #include <bits/stdc++.h>
// using namespace std;
// using ii = pair<int, int>;
// const int N = 1e5+1;

// int n, m, k;
// vector<ii> adj[N];
// int min_w = 1e9;

// void input() {
//     cin >> n >> m >> k;
//     int u, v, w;
//     for (int i = 0; i < m; i++) {
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//         min_w = min(min_w, w);
//     }
// }

// O(V^2)
// đỉnh start đc duyệt đầu tiên
// int Prim(int start) {
//     int sum = 0;
//     vector<bool> isInTree(n+1, false);
//     vector<int> iBest_W(n+1, 1e9); // iBest_W[v]: k/c tu v tới mst
//     vector<int> iBest_Adj(n+1, -1); // iBest_Adj[v]: đỉnh gần v nhất trong mst

//     iBest_W[start] = 0; // bắt đầu duyệt từ đỉnh 1, nhg chưa thêm vào mst
//     // cây có số cạnh E = số đỉnh V - 1
//     for (int i = 1; i <= k+1; i++) {
//         int u = -1, v = -1, w = 1e9;
//         for (int x = 1; x <= n; ++x) {
//             // chọn đỉnh x chưa được thêm vào mst, và cạnh chứa x có trọng số nhỏ nhất w min
//             if (isInTree[x] == false && iBest_W[x] < w) {
//                 u = x, v = iBest_Adj[x], w = iBest_W[x];
//             }
//         }
//         sum += w;
//         if (u == -1) return sum; // do thi ko lien thong (rừng)

//         isInTree[u] = true; /// cho đỉnh u vào cây
        
//         // cập nhật các đỉnh kề với u (ở trên) vào iBest
//         for (auto e : adj[u]) {
//             int v_u = e.first, w_u = e.second; // v_u kề với u
//             if (isInTree[v_u] == false && iBest_W[v_u] > w_u) {
//                 iBest_W[v_u] = w_u;
//                 iBest_Adj[v_u] = u;
//             }
//         }
//     }

//     return sum;
// }


// int main() {
//     input();
//     int min_sum = 1e9;
//     for (int i = 1; i <= n; ++i) {
//         min_sum = min(min_sum, Prim(i));
//     }

//     cout << min_sum;
// }







// sắp xếp các cạnh theo weight, tối ưu nhánh cận và chỉ số duyệt for của Try => 100 p
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

const int N = 21;
const int M = 31;
vector<edge> edges;

vector<int> index_edges_inMST(M, -1);
Disjoint_Set collections; // default constructor

int n, m, k; // n đỉnh, m cạnh, // k-mst has k edges
int min_w = INT_MAX;
int cur_w = 0;
int kiluc = INT_MAX;

bool myCompare(edge a , edge b) {
    return a.weight < b.weight;
}

void input() {
    cin >> n >> m >> k;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
        min_w = min(min_w, w);
    }
    sort(edges.begin(), edges.end(), myCompare);

}

//check mst cuối cùng có liên thông
bool check_connected() {

    int r = -1;
    // i duyệt theo lời giải cấp k : 1->loigiaicapk (=k)
    for (int i = 1; i <= k; i++) {
        int ru = collections.Find(edges[index_edges_inMST[i]].u); // root of u
        int rv = collections.Find(edges[index_edges_inMST[i]].v); // root of v
        if (ru != rv) return false;

        if (r == -1) r = ru;
        if (r != ru) return false; // để chắc chắn ru ko đổi, lưu ru lần đầu tiên vào biến r
    }

    return true;
}

void solution() {
    // for (int i = 1; i <= k; i++) {
    //     cout << edges[index_edges_inMST[i]].u << ' ' << 
    //     edges[index_edges_inMST[i]].v << ' ' << 
    //     edges[index_edges_inMST[i]].weight << endl;
    // }
    // cout << endl;
    if (check_connected()) 
        kiluc = min(kiluc, cur_w);
}

bool checkCycle(int j, int loigiaicapk) {
    // Disjoint_Set collections;
    // prepare a new disjoint set with already relationship in graph
    collections = Disjoint_Set(n);
    // i duyệt theo cấp k của lời giải
    for (int i = 1; i <= loigiaicapk-1; ++i) {
        int ru = collections.Find(edges[index_edges_inMST[i]].u);
        int rv = collections.Find(edges[index_edges_inMST[i]].v);
        collections.Union(ru, rv);

    }
    // check here
    if (collections.Find(edges[j].u) != collections.Find(edges[j].v)) {
        // collections.Union(edges[j].u, edges[j].v);
        return true;
    }
    return false;
}

// lời giải cấp k là thêm 1 cạnh thứ j vào cây
// cấp k của lời giải lại bắt đầu từ chỉ số 1
void Try(int loigiaicapk) {
    // do các cạnh thêm vào mst là phân biệt và tập cạnh edges ban đầu đc sắp tăng dần
    // j là chỉ số của cạnh bắt đầu từ 0
    for (int j = index_edges_inMST[loigiaicapk-1]; j < m; j++) {
        int u = edges[j].u, v = edges[j].v, w = edges[j].weight;   
        if (checkCycle(j, loigiaicapk)) {
        // cout << u << ' ' << v  << ' ' << w << endl; 

            cur_w += w;
            index_edges_inMST[loigiaicapk] = j;
            if (loigiaicapk == k) {
                solution();
            }
            else {
                // nhánh cận
                int tmp = cur_w;
                for (int i = 1; i <= k-loigiaicapk; i++) 
                    tmp += edges[index_edges_inMST[loigiaicapk] + i].weight;
                    // do các cạnh thêm vào là phân biệt và tập cạnh đc sắp xếp tăng dần theo weight
                if (tmp < kiluc) Try(loigiaicapk+1);
            }
            cur_w -= w;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    index_edges_inMST[0] = 0;
    Try(1);
    cout << kiluc;
}

