#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 101;
const int MAX_M = 501;
const int MOD = 1e9 + 7;

int N, M;
int a[MAX_N];
int f[MAX_N][MAX_M];

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
}

/*
f(i, j) = số cách phân hoạch j cửa hàng sử dụng
các chi nhanh 1..i
f(N, M)

f(0, 0) = 1
f(0, j > 0) = 0
f(i > 0, 0) = 0
=> tinh tu bai toan con (bottom-up)

0 < k <= j: k la so cua hang phan hoach cho 1 chi nhanh i
k chia hết a(i) => a(i) <= k <= j, k += a(i)

f(i, j) = sum_{k} f(i-1, j-k)

=> O(N * M^2)


C2: f(i, j) = sum_{k} f(i-1, j-k)
=> f(i, j) = f(i-1, j-a[i])    + f(i-1, j-a[i]*2) + ...
ma f(i, j-a[i]) = f(i-1, j-a[i]*2) + f(i-1, j-a[i]*3) + ...

=> f(i, j) = f(i, j-a[i]) + f(i-1, j-a[i])
O(N * M)

*/

int main() {
    input();

    f[0][0] = 1; // biên, phan hoach vua du M cua hang cho N chi nhanh

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; ++j) {
            // k cua hang chia het cho a[i]
            for (int k = a[i]; k <= j; k += a[i]) {
                f[i][j] += f[i-1][j-k];

                if (f[i][j] >= MOD)
                    f[i][j] -= MOD;
            }
        }
    }

    // cach2:
    // for (int i = 1; i <= N; i++) {
    //     for (int j = a[i]; j <= M; ++j) {
    //         f[i][j] = f[i][j-a[i]] + f[i-1][j-a[i]];
    //         if (f[i][j] >= MOD)
    //             f[i][j] -= MOD;            
    //     }
    // }

    cout << f[N][M];
    return 0;
}