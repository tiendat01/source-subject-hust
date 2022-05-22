#include <bits/stdc++.h>
using namespace std;
const int N = 32;
const int K = 1000005;
long long a[N], c[N];
long long dp[31][K];

inline void knapsac() {
  int n, b;
  cin >> n >> b;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> c[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= b; j++) {
      if (a[i] > j)
        dp[i][j] = dp[i - 1][j];
      else {
        dp[i][j] = max (dp[i - 1][j] , c[i] + dp[i - 1][j - a[i]]);
      }
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << "\n";
}

int main() { knapsac(); }

// 2 6
// 4 2
// 3 2

// => 2