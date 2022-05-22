#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull a, b;
const ull mod = 1e9 + 7;

ull ans_binary(ull a, ull b) {
    if (b <= 0) 
        return 1;
    else {
        if (b % 2 == 0) {
            ull tmp = ans_binary(a, b/2);
            return (tmp * tmp) % mod;
        }
        else {
            return ((ans_binary(a, b-1)%mod) * (a%mod)) % mod;
        }
    }
}

int main() {
    cin >> a >> b;
    cout << ans_binary(a, b);
    return 0;
}