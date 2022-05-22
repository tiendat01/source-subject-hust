// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1000001;
// int n;
// int A[N]; // bo qua chi so 0
// int iMem[N];
// bool bMark[N];

// // O(n)
// // trọng số của đoạn có trong số lớn nhất từ 1,...,i mà kết thúc tại i
// // f(i) = a[i] + max(f(i-1))
// int maxSum(int i) {
//     if (i == 1) {
//         iMem[1] = A[1];
//         return iMem[1];
//     }
//     if (bMark[i]) 
//         return iMem[i];
//     int res = 0;
//     res = max(res , maxSum(i-1)); // goi maxSum n lan
//     res += A[i];
//     iMem[i] = res;
//     bMark[i] = true;
//     return res;
// }

// void input() {
//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> A[i]; 
//     A[0] = 0;
// }

// int main() {
//     input();
//     int ans = 0;
//     maxSum(n);
//     for (int i = 1; i <= n; i++) {
//         ans = max(ans, iMem[i]);
//     }
    
//     cout << ans;
//     return 0;
// }

// // 10
// // 3 -1 -3 5 2 5 0 -1 5 4 




#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n;
int A[N]; // bo qua chi so 0
int iMem[N];
bool bMark[N];

// O(n)
// trọng số của đoạn có trong số lớn nhất từ 1,...,i mà kết thúc tại i
// f(i) = a[i] + max(f(i-1))
int maxSum(int i) {
    if (i == 1) {
        iMem[1] = A[1];
        return iMem[1];
    }
    if (bMark[i]) 
        return iMem[i];
    int res = 0;
    res = max(res , maxSum(i-1)); // goi maxSum n lan
    res += A[i];
    iMem[i] = res;
    bMark[i] = true;
    return res;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
         cin >> x; 
         A[i] = x*x*x;
    }
    A[0] = 0;
}

int main() {
    input();
    int ans = 0;
    maxSum(n);
    for (int i = 1; i <= n; i++) {
        ans = max(ans, iMem[i]);
    }
    
    cout << ans;
    return 0;
}

// 10
// 3 -1 -3 5 2 5 0 -1 5 4 

