#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
ull C(ull k, ull n) {
    if (k == n || k == 0) return 1;
    else return C(k-1,n-1) + C(k,n-1);
}
// 5 point
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T ; cin >> T;
    ull n, k, m;
    for (int i = 0; i < T; i++) {
        cin >> n >> k >> m;
        cout << C(k, n) % m << endl;
    }
    return 0;
}