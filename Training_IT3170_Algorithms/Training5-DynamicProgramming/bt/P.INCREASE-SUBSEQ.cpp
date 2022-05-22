#include <bits/stdc++.h>
using namespace std;

// do dai day con (ko lien tiep nhg theo thu tu) tang lon nhat 
int n;
int A[10001]; // bat dau tu A[1]
int iMem[10001];

void prepare() {
    memset(iMem, -1, sizeof(iMem));
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    A[0] = 0; // bo qua chi so 0
}

// O(n^2)
// do dai day con tang lon nhat cua mang A[1] -> A[i] ma ket thuc tai i
int LIS(int i) {
    if (iMem[i] != -1)
        return iMem[i];
    int res = 1;
    for (int j = 1; j < i; j++) {
        if (A[j] < A[i]) {
            res = max(res, 1 + LIS(j));
        }
    }
    iMem[i] = res;
    return res;
}

int main() {
    input();
    prepare();
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
        LIS(i);
        ans = max(ans, iMem[i]);
    }
    cout << ans << endl;
    return 0;
}