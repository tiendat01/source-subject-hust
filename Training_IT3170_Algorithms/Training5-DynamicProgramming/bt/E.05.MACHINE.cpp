#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e6 + 1;
int n;
int s[N], t[N]; // 1 <= s[i] < t[i] <= 2*1e6
int maxAmount[N];

// maxAcount[X] = gia tri cua doan lon nhat ma co diem cuoi t <= X

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] >> t[i];
    }
    memset(maxAmount, 0, sizeof(maxAmount));
}

// bottom-up
// CT: tai doan i: ti - si + maxAmount[s[i]-1]
// voi i la doan thu 2, co j la doan thu 1: tj < si
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); // 100 point
    input();
    
    for (int i = 1; i <= n; i++) {
        // cac doan co diem cuoi t[i]
        maxAmount[t[i]] = max(maxAmount[t[i]], t[i] - s[i]);
        // tai sao phai dung ham max(,) ma chi can maxAmount[t[i]] = t[i]-s[i], ban dau maxAmount = 0? 
        // vi co TH co 2 period co cung t
    }

    // theo ct , tim maxAmount[si-1]
    int maxSi = 0;
    for (int i = 1; i <= n; ++i) {
        maxSi = max(maxSi, s[i]);
    }
    // bottom-up
    for (int i = 1; i <= maxSi; ++i) {
        // max se gối lên nhau, ko can duyet tu 1 toi i nua!
        maxAmount[i] = max(maxAmount[i], maxAmount[i-1]);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, maxAmount[s[i]-1] + (t[i] - s[i]));
    }
    cout << res;
    return 0;
}