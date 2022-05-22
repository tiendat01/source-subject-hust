#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int n, T, D;
int a[N], t[N];
int f[N][N];

void input() {
    cin >> n >> T >> D;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    memset(f, -1, sizeof(f));
}

/* 
f[i][k] là lượng hàng lấy được nhiều nhất từ 1..i điểm và
nhà kho i phải được lấy, t/g đã lấy hàng ko vượt quá k 
*/
// top down
// thoi gian lay hang ko vuot qua k : k >= t[i]
// nha kho i phai duoc lay hang
int warehouse(int i, int k) {
    if (i < 1) return 0;
    if (k < t[i]) {
        f[i][k] = 0;
        return 0;
    }
    if (f[i][k] != -1) return f[i][k];

    int res = 0;
    // 1 <= i-j <= D
    for (int j = i-D; j <= i-1; j++) {
        res = max(res, warehouse(j, k-t[i]));
    }
    res += a[i];
    f[i][k] = res;
    return res;
}

int main() {
    input();
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        for (int k = 1; k <= T; k++){
            ans = max(ans, warehouse(i, k));
        }
    }
    cout << ans;
    return 0;
}