// 100 points I problems

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
