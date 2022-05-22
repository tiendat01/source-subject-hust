// đồ thị ko trọng số
// tim đường đi ngắn nhất giữa 2 đỉnh a->b đi qua ít cạnh nhất
// gọi BFS 1 lần từ đỉnh a tới khi tìm thấy b thì dừng
// hoặc gọi BFS từ đỉnh a tới tất cả các đỉnh khác

// O(n+m)

#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

vector<int> adj[N];
vector<int> iDist(N, -1); // lưu k/c từ đỉnh start tới các đỉnh khác

queue<int> Q;

void addDirectedEdge(int u, int v) {
    adj[u].push_back(v);
}

void BFS_shortestpath(int start) {
    Q.push(start);
    iDist[start] = 0;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            // nếu chưa thăm
            if (iDist[v] == -1) {
                Q.push(v);
                iDist[v] = 1 + iDist[u];
            }
        }
    }
}


bool BFS(int src, int dest, int v,
         int pred[], int dist[])
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;
 
    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];
 
    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 
    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
 
    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
 
                // We stop BFS when we find
                // destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}
 
// utility function to print the shortest distance
// between source vertex and destination vertex
void printShortestDistance(int src,
                           int dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v], dist[v];
 
    if (BFS(src, dest, v, pred, dist) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }
 
    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl); // path bị ngược
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 
    // distance from source is in distance array
    cout << "Shortest path length is : "
         << dist[dest];
 
    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

int main() {
    addDirectedEdge(1,2);
    addDirectedEdge(1,3);
    addDirectedEdge(2,5);
    addDirectedEdge(3,2);
    addDirectedEdge(3,4);
    addDirectedEdge(4,1);
    addDirectedEdge(5,6);
    addDirectedEdge(6,3);
    addDirectedEdge(6,4);
    addDirectedEdge(6,7);
    addDirectedEdge(6,8);
    addDirectedEdge(6,9);
    addDirectedEdge(7,8);
    addDirectedEdge(7,9);
    addDirectedEdge(8,11);
    addDirectedEdge(9,10);
    addDirectedEdge(10,9);

    int v = 11; // số đỉnh

    // bắt đầu từ đỉnh 1:
    BFS_shortestpath(1);

    // từ 1 -> 5
    cout << iDist[5] << endl;

    // truy vết đường đi: (tham khảo geekforgeeks)
    printShortestDistance(1,5,v);

}