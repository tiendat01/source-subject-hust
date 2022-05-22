/*
iMem[i]: so luong vang lon nhat, s/d nha kho a[1...i],
s/c nhà kho a[i] duoc s/d
L1 <= i - j <= L2 => i-L2 <= j <= i-L1
iMem[i] = a[i] + max(f(j)) 


Độ phức tạp: O(N * (L2 - L1))
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n;
int L1, L2;
int a[N];
int iMem[N]; 

void input() {
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(iMem, -1, sizeof(iMem));
}

// top-down
//  so luong vang lon nhat, su dung a[1...i], a[i] duoc s/d 
int gold_mining(int i) {
    if (i < 1) {
        return 0;
    } 
    if (iMem[i] != -1) return iMem[i];

    int res = 0;

    for (int j = i-L2; j <= i-L1; j++) {
        res = max(res , gold_mining(j));
    }
    res += a[i];
    iMem[i] = res;
    return res;
}

// bottom-up
int gold_mining_loop() {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        iMem[i] = 0; // max của f(j) với i-L2 <= j <= i-L1
        for (int j = i-L1; j>=i-L2 && j > 0; j--) {
            iMem[i] = max(iMem[i], iMem[j]);
        }
        iMem[i] += a[i];
        result = max(result, iMem[i]);
    }
    return result;
}

int main() {
    input();
    
    // loop
    cout << gold_mining_loop();

    int res = 0;
    for (int i = n; i >= 1; i--) 
        res = max(res, gold_mining(i));
    cout << res;

    
    return 0;
}


// 6 2 3
// 3 5 9 6 7 4


// 19