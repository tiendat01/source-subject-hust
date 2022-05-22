// y tuong giong bai warehouse

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n, b; // tong khoi luong ko vuot qua b
int a[N], c[N]; // a la khoi luong , c la giatri s/d
int f[31][N];

void input() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= b; k++) {
            f[i][k] = 0;
        }
    }
}

/*
f(i, k) la gtri s/d lon nhat ma su dung cac do vat 1..i, do vat i phai duoc dung
voi k la khoi luong da dung
f(i,k) = max(f(j, k-a[i])) voi 1 <= j <= i-1
*/

// 95 points: O(n*b*b) // i:1->n and k:1->b
// int knapsac(int i, int k) {
//     if (k < a[i]) {
//         f[i][k] = 0;
//         return 0;
//     }
//     if (f[i][k] != -1) return f[i][k];

//     f[i][k] = 0;
//     for (int j = 1; j <= i-1; j++) {
//         f[i][k] = max(f[i][k], knapsac(j, k-a[i]));
//     }
//     f[i][k] += c[i];
//     return f[i][k];
// }



// O(n*b): 100 point
// f(i, k) la gtri s/d lon nhat ma su dung cac do vat tu 1..i, i ko nhat thiet phai dung
// voi k la khoi luong da dung
int knapsac(int i , int k) {
    if (i < 1 || k < 1) return 0;
    if (f[i][k] != 0) return f[i][k];

    if (k < a[i]) { 
        f[i][k] = knapsac(i-1, k); // do vat i ko duoc s/d
        return f[i][k];
    }

    else {
        f[i][k] = max(knapsac(i-1, k) , knapsac(i-1, k-a[i]) + c[i]);
        return f[i][k];
    }

}

int main() {
    input();
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= b; k++) {
            res = max(res, knapsac(i, k));
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= b; k++) {
            cout << f[i][k] << ' ';
        }
        cout << endl;
    }
    cout << res;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int KnapSack(int val[], int wt[], int n, int W) {
//   int dp[W + 1];
//   memset(dp, 0, sizeof(dp));
//   for (int i = 0; i < n; i++)
//     for (int j = W; j >= wt[i]; j--)
//       dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
//   return dp[W];
// }
// int main() {
//   int n, W;
//   cin >> n >> W;
//   int val[n], wt[n];
//   for (int i = 0; i < n; i++) {
//     cin >> wt[i] >> val[i];
//   }
//   cout << KnapSack(val, wt, n, W) << "\n";
//   return 0;
// }