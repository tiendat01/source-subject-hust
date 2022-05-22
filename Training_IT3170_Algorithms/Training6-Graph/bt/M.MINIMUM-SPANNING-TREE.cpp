// kruskal

#include<bits/stdc++.h>
using namespace std;
using ll = long long; // dùng long long mới full điểm
// rank implementation
struct Disjoint_Set {
    vector<ll> iParent;
    vector<ll> rank;
    // n đỉnh 1 -> n
    Disjoint_Set(ll n) {
        iParent = vector<ll>(n+1);
        rank = vector<ll>(n+1);
        for (ll i = 1; i <= n; i++) {
            iParent[i] = i;
            rank[i] = 0;
        }
    }
    // khử đệ quy
    ll Find(ll x) {
        while (iParent[x] != x) {
            iParent[x] = iParent[iParent[x]];
            x = iParent[x]; 
        }
        return x;
    }
    
    void Union(ll x, ll y) {
        ll rx = Find(x), ry = Find(y);
        if (rx == ry) return ; // cùng thuộc 1 collections

        if (rank[rx] > rank[ry]) // rank cao hơn làm cha
            iParent[ry] = rx;
        else {
            iParent[rx] = ry;
            if (rank[rx] == rank[ry]) rank[ry]++;
        }
    }

};

struct edge {
    ll u, v; 
    ll weight;

    edge(ll _u, ll _v, ll _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

const ll N = 1e5+1;
ll n, m;
vector<edge> edges;
ll min_w = 0;

void input() {
  cin >> n >> m;
  ll u, v, w;
  for (ll i = 0; i < m; i++) {
    cin >> u >> v >> w;
    edges.push_back(edge(u, v, w));
  }
}

bool myCompare(edge a, edge b) {
  return a.weight < b.weight;
}

// kruskal
void min_spanning_tree() {
  Disjoint_Set collections = Disjoint_Set(n+1);
  sort(edges.begin(), edges.end(), myCompare);
  for (ll i = 0; i < m; i++) {
    ll u = edges[i].u, v = edges[i].v, w = edges[i].weight;
    if (collections.Find(u) != collections.Find(v)) {
      collections.Union(u, v);
      min_w += w;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  input();
  min_spanning_tree();
  cout << min_w;
}