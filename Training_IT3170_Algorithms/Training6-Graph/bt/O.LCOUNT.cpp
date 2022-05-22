// đếm sô nút lá trong cây
// nút lá có bậc là 1

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n; // n cạnh
vector<int> deg(N, 0); // cạnh

void input_and_deg() {
    cin >> n;
    int u, v;
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    input_and_deg();
    int leaf_count = 0;
    for (int i = 2; i <= n; ++i ) {
        if (deg[i] == 1)  
            leaf_count++;
    }
    cout << leaf_count;
}