// dùng bfs duyệt cây nhị phân, ko cần tạo đồ thị
// O(f)

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int f, s, g; // tầng cao nhất f, làm sao đi từ s->g
int u, d; // đi lên được u tầng, đi xuống d tâng

queue<int> q;
vector<int> push(N, 0);
vector<bool> isVisited(N, false);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> f >> s >> g >> u >> d;

    q.push(s);
    isVisited[s] = true;

    while(!q.empty()) {
        int v = q.front(); q.pop();
        if (v == g) {
            cout << push[v];
            return 0;
        }

        int cur_floor;
        if (v + u <= f) {
            cur_floor = v + u;
            push[cur_floor] = push[v] + 1;
            if (!isVisited[cur_floor]) 
                q.push(cur_floor), isVisited[cur_floor] = true;
        }
        if (v - d > 0) {
            cur_floor = v - d;
            push[cur_floor] = push[v] + 1;
            if (!isVisited[cur_floor]) 
                q.push(cur_floor), isVisited[cur_floor] = true;
        }
    }

    cout << "use the stairs" ;
    return 0;

}