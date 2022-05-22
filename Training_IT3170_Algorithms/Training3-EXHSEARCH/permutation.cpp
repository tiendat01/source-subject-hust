#include <bits/stdc++.h>

using namespace std;

#define N 10008

long fact[16];
int permute[16];

bool greaterFunc(int i, int j) { return i > j; }

int main() {
  int n, k;
  cin >> n >> k;

  long product = 1;
  int countBack = 0;

  // As k <= 10^9, k < 13!
  for (int i = 1; i <= n; i++) {
    product *= i;
    permute[i] = i;
    fact[i] = product;
    if (product >= k) {
      countBack = i;
      break;
    }
  }

  if (product < k) { // If k is out of permutation
    cout << -1;
    return 0;
  }

  // In case of n is first element, there are (n-1)! of that case.
  int u = 1;
  int v = countBack;
  while (k != 0) {
    int first = k / fact[v - 1];
    k = k % fact[v - 1];
    if (k != 0)
      first++;
    int temp;
    temp = permute[u];
    permute[u] = permute[u + first - 1];
    permute[u + first - 1] = temp;
    u++;
    v--;
    sort(permute + u, permute + countBack + 1);
  }

  sort(permute + u, permute + countBack + 1, greaterFunc);

  for (int i = 1; i <= n - countBack; i++) {
    cout << i << " ";
  }

  for (int i = 1; i <= countBack; i++) {
    cout << n - countBack + permute[i] << " ";
  }
}