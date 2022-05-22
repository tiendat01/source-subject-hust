#include<bits/stdc++.h>
using namespace std;

const int N = 10009;
int n, m;
int X[N], Y[N]; 
int iMem[N][N]; // do dai cua day chung dai nhat cua X[1->i] va Y[1->j]

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> X[i];
    for (int j = 1; j <= m; j++) 
        cin >> Y[j];
    memset(iMem, 0, sizeof(iMem));
}

// 100 points
// int LCS(int i, int j) {
//     if (i == 0 || j == 0) return 0;
//     if (iMem[i][j] != -1) return iMem[i][j];
//     int res = 0;
//     res = max(LCS(i-1,j), LCS(i, j-1));
//     if (X[i] == Y[j])
//         res = max(res, 1 + LCS(i-1, j-1));
//     iMem[i][j] = res;
//     return res;
// }

// 100 points
int LCS() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i] == Y[j]) 
                iMem[i][j] = 1 + iMem[i-1][j-1];
            else 
                iMem[i][j] = max(iMem[i-1][j], iMem[i][j-1]);
        }
    }
    return iMem[n][m];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    cout << LCS();
    return 0;
}