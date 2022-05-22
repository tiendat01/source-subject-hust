#include <bits/stdc++.h>
using namespace std;

const int N = 31;

int n, K; // n dinh K canh trong duong di can tim
int m; // so canh cua do thi

vector< vector<int> > ds_ke;
bool isvisited[N];
int res = 0;
int pre_node;

void input_xulychiso0() {
    cin >> n >> K;
    cin >> m;
    ds_ke = vector<vector<int>>(N);
    // ds_ke.resize(N+1);
    // ds_ke.push_back({0});
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ds_ke[u].push_back(v);
        ds_ke[v].push_back(u);
    }
}

bool isUCV(int pre_node, int cur_node) {
    if (pre_node == 0) return true; // dinh dau tien trong k-path

    if (isvisited[cur_node]) return false;

    // check co edge noi 2 node ko
    for (int i = 0; i < ds_ke[pre_node].size(); i++) {
        if (ds_ke[pre_node][i] == cur_node) return true;
    }

    return false;

}

void TRY(int k) {
    for (int j = 1; j <= n; j++) {
        if (isUCV(pre_node, j)) {
            int save = pre_node;
            isvisited[j] = true;
            pre_node = j;

            if (k == K+1) {
                res++;
            }
            else {
                TRY(k+1);
            }
            
            isvisited[j] = false;
            pre_node = save;
        }
    }
}


int main() {
    input_xulychiso0();
    TRY(1);
    cout << res/2;
    return 0;
}