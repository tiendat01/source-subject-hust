#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct compare {
    // sap xep queue tang dan
    // priority_queue lay ra phan tu co do uu tien cao nhat (phan tu nho nhat)
    bool operator() (pair<int, int> l, pair<int, int> r) {
        return l.second > r.second;
    }
};

// adj[i][j] co kieu pair<int, int> (j la chi so cua ds cac dinh ke voi i)
// adj[i][j].first: dinh ke voi i
// adj[i][j].second: k/c giua 2 dinh i va dinh ke voi no
vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    /*****************
    template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
    > class priority_queue;

    voi priority_queue mac dinh thi phan tu lon nhat co do uu tien lon nhat, tuc la queue giam dan
    *****************/

   priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pQ;
   vector<int> dist = vector<int>(adj.size()); // k/c tu dinh 0 den cac dinh i (i = 0..n)
   // ban dau cac dist rat lon
    for (unsigned int i = 0; i < dist.size(); i++) {
        dist[i] = INT_MAX;
    }
    // k/c tu 0 den 0 la 0
    dist[0] = 0; 
    // khoi tao priority_queue
    for (unsigned int i = 0; i < adj.size(); i++) {
        pQ.push({i, dist[i]});
    }

    while (!pQ.empty()) {
        pair<int, int> u = pQ.top(); pQ.pop();
        for (pair<int, int> v : adj[u.first]) {
            if (dist[v.first] > dist[u.first] + v.second) {
                dist[v.first] = dist[u.first] + v.second;
                pQ.push({v.first, dist[v.first]});
            }
        }
    }
    return dist;
}

int main() {
	cout << "Ho ten: Nguyen Tien Dat\n" << "MSSV: 20194242\n";
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}
