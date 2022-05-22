#include <bits/stdc++.h>

using namespace std;

int cost[21][21]; // chi phi
int n, m; // vertex and edge
int min_cost = INT_MAX;
int min_res = INT_MAX;
int cur_cost = 0;
int path[21];
bool is_visited[21];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, c;
        // c > 0
        cin >> from >> to >> c;
        min_cost = min(c, min_cost);
        cost[from][to] = c;
    }
}

bool isUCV(int kth_sol, int val_sol) {
    if (cost[path[kth_sol-1]][val_sol] <= 0) return false;
    if (is_visited[val_sol]) return false; // ko lap lai diem da den
    return true;
}

void Try(int kth_sol) {
    for (int i = 1; i <= n; i++) {
        if (isUCV(kth_sol, i)) {
            path[kth_sol] = i;
            is_visited[i] = true;
            cur_cost += cost[path[kth_sol-1]][i];

            if (kth_sol == n) {
                if (cost[path[kth_sol]][1] > 0) {
                    int last_cost = cur_cost + cost[path[kth_sol]][1];
                    min_res = min(last_cost, min_res);
                }
            }

            else {
                int can_duoi = cur_cost + (n-kth_sol+1) * min_cost;
                if (can_duoi < min_res) // dk tach nhanh can
                    Try(kth_sol+1);
            }

            // return status:
            is_visited[i] = false;
            cur_cost -= cost[path[kth_sol-1]][i];
        }
    }
}

int main() {
    input();
    path[1] = 1;
    is_visited[1] = true;
    Try(2);
    cout << min_res;
    return 0;
}