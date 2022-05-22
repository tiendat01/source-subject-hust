// // C++ program to demonstrate min heap
// #include <iostream>
// #include <queue>
 
// using namespace std;
 
// struct compare
// {
//     bool operator()(const int & a, const int & b)
//     {
//         return a<b;
//     }
// };

// void showpq(priority_queue<int, vector<int>, compare > gq)
// {
//     priority_queue<int, vector<int>, compare > g = gq;
//     while (!g.empty()) {
//         cout << '\t' << g.top();
//         g.pop();
//     }
//     cout << '\n';
// }
 
// int main()
// {
//     priority_queue<int, vector<int>, compare > gquiz;
//     gquiz.push(10);
//     gquiz.push(30);
//     gquiz.push(20);
//     gquiz.push(5);
//     gquiz.push(1);
 
//     cout << "The priority queue gquiz is : ";
//     showpq(gquiz);
 
//     cout << "\ngquiz.size() : " << gquiz.size();
//     cout << "\ngquiz.top() : " << gquiz.top();
 
//     cout << "\ngquiz.pop() : ";
//     gquiz.pop();
//     showpq(gquiz);
 
//     return 0;
// }



#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

#define MAX 1000

typedef pair<int, int> v_and_le; // luu dinh hang xom v cua dinh u va dist(u,v)
vector<v_and_le> ke[MAX];

int n, m; // n dinh, m canh
int dist[MAX]; // luu khoang cach tu s sang u
int pre[MAX]; // luu dinh trc u trong duong di ngan nhat tu s->u
int data[MAX][MAX];
int dist_uv[MAX][MAX];

int dist_bfs[MAX];
int pre_bfs[MAX];


void dijkstra(int s) {
    priority_queue <v_and_le, vector<v_and_le>, greater<v_and_le>> H;
    for (int i = 0; i < n; i++) {
        dist[i] = INT32_MAX;
        pre[i] = -1; 
    }
    dist[s] = 0; 
    H.push(v_and_le(s, dist[s]));
    while (H.size()) {
        int u = H.top().first;
        int dist_u = H.top().second;
        H.pop();
        for (int i = 0; i < ke[u].size(); i++) {
            int v = ke[u][i].first;
            int l_uv = ke[u][i].second;
            if (dist[v] > dist_u + l_uv) {
                dist[v] = dist_u + l_uv;
                pre[v] = u;
                H.push(v_and_le(v, dist[v]));
            }
        }

    }
}

void bfs(int s, int f) { // start and finish
    int u;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        dist_bfs[i] = -1;
        pre_bfs[i] = -1;
    }
    dist_bfs[s] = 0;
    q.push(s);

    while(q.size() != 0) {
        u = q.front();
        q.pop();

        for (int i = 0; i < ke[u].size(); i++) {
            int t = ke[u][i].first;
            if (dist_bfs[t] == -1) {
                dist_bfs[t] = dist_bfs[u] + 1;
                pre_bfs[t] = u;
                q.push(t);
            }
        }
    }


    // truy vet
    if (dist_bfs[f] == -1) cout << "Khong co duong di tu " << data[s] << " toi " << data[f] << endl;
    else {
        vector<int> path;
        while (f != s) {
            path.push_back(f);
            f = pre_bfs[f];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        cout << "Duong di ngan nhat :" << endl;
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a,b; // cua robot 1
    int c,d; // cua robot 2
    int r; // khoang cach toi thieu giua 2 robot

    ifstream fileInput("input.txt");

	if (fileInput.fail())
	{
		cout << "Failed to open this file!" << endl;
		return -1;
	}
    fileInput >> n;
    fileInput >> m;
		
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                fileInput >> data[i][j];
            }
            ke[data[i][0]].push_back(v_and_le(data[i][1], data[i][2]));
            ke[data[i][1]].push_back(v_and_le(data[i][0], data[i][2]));
        }
    fileInput >> a >> b;
    fileInput >> c >> d;
    fileInput >> r;
    
    fileInput.close();
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << data[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for (int i = 0; i < n; i++) {
        dijkstra(i);
        for (int j = 0; j < n; j++) {
            dist_uv[i][j] = dist[j];
        }
    }

    bfs(a,b);
    bfs(c,d);

    
    return 0;
}
