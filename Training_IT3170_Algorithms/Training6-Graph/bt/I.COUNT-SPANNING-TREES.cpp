// // 60 point tle?

// #include<bits/stdc++.h>
// using namespace std;

// struct edge {
//   int u, v;
//   edge(int _u, int _v) {
//     u = _u;
//     v = _v;
//   }
// };

// struct Union_Find {
//     vector<int> iParent; // lưu phần tử đại diện của 1 collection
//     // n đỉnh 1 -> n
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

// const int N = 26;
// vector<edge> edges;
// vector<bool> isAdd(N, false);
// vector<int> prev_edge(N, 0); // lưu chỉ số (trong edges) của cạnh ứng với lời giải cấp k
// int n, m;
// int count_sptree = 0;

// void input() {
//   cin >> n >> m;
//   int u, v; 
//   for (int i = 0; i < m;  i++) {
//     cin >> u >> v;
//     edges.push_back(edge(u, v));
//   }
// }

// bool isUCV(int loigiaicapk, int j) {

//   Union_Find collections = Union_Find(N);
//   for (int i = 1; i < loigiaicapk; i++) {
//     int u = edges[prev_edge[i]].u, v = edges[prev_edge[i]].v;
//     int ru = collections.Find(u), rv = collections.Find(v);
//     if (ru == rv) return false;
//     collections.Union(ru, rv);
//   }
//   if (collections.Find(edges[j].u) == collections.Find(edges[j].v))
//     return false;

//   return true;
// }

// void Try(int loigiaicapk) {
//   for (int j = prev_edge[loigiaicapk-1]+1; j < m; ++j) {
//     if (isUCV(loigiaicapk, j)) {
//       prev_edge[loigiaicapk] = j;

//       if (loigiaicapk == n-1) {
//         count_sptree++;
//       }
//       else 
//         Try(loigiaicapk+1);
//     }
//   }
// }

// int main() {
//   ios_base::sync_with_stdio(0); cin.tie(0);
//   input();
//   prev_edge[0] = -1;
//   Try(1);

//   cout << count_sptree;
// }




// 40 points
#include <bits/stdc++.h>
using namespace std;

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
const int M = 26;
int n , m;
vector< pair<int, int> > edges;
vector<int> index_edge_inMST(M, -1); // chỉ số của các cạnh trong edges bắt đầu từ 0
long long count_sp_tree = 0;
Disjoint_Set collections;

void input() {
  cin >> n >> m;
  int u , v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    edges.push_back({u, v});
  }
}

void solution() {
    count_sp_tree++;
}


bool check_cycle(int j , int loigiaicapk) {
  // Disjoint_Set collections;
    // prepare a new disjoint set with already relationship in graph
    collections = Disjoint_Set(n);
    for (int i = 1; i <= loigiaicapk-1; ++i) {
        int ru = collections.Find(edges[index_edge_inMST[i]].first);
        int rv = collections.Find(edges[index_edge_inMST[i]].second);
        collections.Union(ru, rv);
 
    }
    // check here
    if (collections.Find(edges[j].first) != collections.Find(edges[j].second)) {
        // collections.Union(edges[j].first, edges[j].second);
        return true;
    }
    return false;
}

// lời giải cấp k là thêm cạnh thứ j vào mst
void Try(int loigiaicapk) {
  for (int j = index_edge_inMST[loigiaicapk-1]; j < m; j++) {
    if (check_cycle(j, loigiaicapk)) {
      index_edge_inMST[loigiaicapk] = j;

      if (loigiaicapk == n-1) {
        solution();
      }
      else {
        Try(loigiaicapk+1);
      }
    }
  }
} 

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  input();
  index_edge_inMST[0] = 0; // tránh runtime-err
  Try(1);

  cout << count_sp_tree;
  return 0;
}







// 80 point sửa code giống 100points nhg chỉ đc 80 points ???

// #include<bits/stdc++.h>
// using namespace std;

// const int N = 1000;

// long long u[N];
// long long v[N];
// long long prev_edge[N]; // lưu chỉ số (trong edges) của cạnh ứng với lời giải cấp k
// long long n, m;
// long long count_sptree = 0;

// /*datastructure disjoint-set*/
// const int MAX = 1000;
// long long r[MAX]; // rank
// long long p[MAX]; // parent of node

// void makeSet(long long x){
//     p[x] = x;
//     r[x] = 0;
// }

// void unionSet(long long x, long long y){

//     if(r[x] > r[y]){
//         p[y] = x;
//     } else {
//         p[x] = y;
//         if(r[x] == r[y]) r[y] += 1;
//     }
// }

// long long findSet(long long x){
//     if (p[x] != x){
//         p[x] = findSet(p[x]);
//     }
//     return p[x];
// }
// /*end datastructure*/



// void input() {
//   cin >> n >> m;
//   for (long long i = 0; i < m;  i++) {
//     cin >> u[i] >> v[i];
//   }
// }

// bool isUCV(long long loigiaicapk, long long j) {

//   for (long long i = 1; i <= n; i++) makeSet(i);
//   for (long long i = 1; i < loigiaicapk; i++) {
//     long long u1 = u[prev_edge[i]], v1 = v[prev_edge[i]];
//     long long ru = findSet(u1), rv = findSet(v1);
//     unionSet(ru, rv);
//   }
//   if (findSet(u[j]) == findSet(v[j]))
//     return false;

//   return true;
// }

// void Try(int loigiaicapk) {
//   for (int j = prev_edge[loigiaicapk-1]+1; j < m; ++j) {
//     if (isUCV(loigiaicapk, j)) {
//       prev_edge[loigiaicapk] = j;

//       if (loigiaicapk == n-1) {
//         count_sptree++;
//       }
//       else 
//         Try(loigiaicapk+1);
//     }
//   }
// }

// int main() {
//   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//   input();
//   prev_edge[0] = -1;
//   Try(1);

//   cout << count_sptree;
// }


















// lời giải 100đ
// code tham khảo check 100 points

#include <bits/stdc++.h>
#define MAX_N 101
#define MAX_M 1000
using namespace std;

int N,M;
int b[MAX_M];
int e[MAX_M];// (b[i],e[i]) la canh thu i cua do thi
int X[MAX_N];// model solution, set of indices of edges of spanning tree
long long ans;
// data structure for disjoint-set
int r[MAX_N];// r[v] is rank of set v
int p[MAX_N];// p[v] is parent of v
long long rs;

void link(int x, int y){
    if(r[x] > r[y]) p[y] = x;
    else{
        p[x] = y;
        if(r[x] == r[y]) r[y] = r[y] + 1;
    }
}

void makeSet(int x){
    p[x] = x;
    r[x] = 0;
}

int findSet(int x){
    if(x != p[x])
    p[x] = findSet(p[x]);
    return p[x];
}

void input(){
    cin >> N >> M;
    for(int i = 1; i<= M; i++){
        cin >> b[i] >> e[i];
    }
}

void solution(){
    ans++;
}

int checkNoCycle(int val, int k){
    // check if set edges (b[X[1]],e[X[1]]), (b[X[2]],e[X[2]]),
    // ..., (b[X[val]],e[X[val]]) induces a cycle
    for(int i = 1; i <= N; i++) makeSet(i);
    for(int j = 1; j < k; j++){
        int u = b[X[j]];
        int v = e[X[j]];
        int ru = findSet(u);
        int rv = findSet(v);
        if(ru == rv) return 0;// node u and v belong to the
        // same set --> creating a cycle
        link(ru,rv);// otherwise, link two sets together
    }
    if(findSet(b[val]) == findSet(e[val])) return 0;
    return 1;
}

void TRY(int k){
    for(int v = X[k-1] + 1; v <= M; v++){
        if(checkNoCycle(v,k)){
            X[k] = v;
            if(k == N-1){
                solution();
            }else{
                TRY(k+1);
            }
        }
    }
}

void solve(){
    ans = 0;
    X[0] = 0;
    TRY(1);
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}
