#include <bits/stdc++.h>
using namespace std;

int n = 8;
int A[1001] = {0, -16, 7, -3, 0, -1, 5, -4000, 9 }; // bo qua chi so 0
int iMem[1001];
bool bMark[1001];
int sum;

// O(n)
// trọng số của đoạn có trong số lớn nhất từ 1,...,i mà kết thúc tại i
int maxSum(int i) {
    if (i == 1) {
        iMem[1] = A[1];
        return iMem[1];
    } 
    if (bMark[i]) 
        return iMem[i];
    int res = max(A[i], A[i] + maxSum(i-1)); // goi maxSum n lan
    iMem[i] = res;
    bMark[i] = true;
    return res;
}

void Trace(int i) {
    if (A[i] == iMem[i] || i == 1) {
        cout << A[i] << ' ';
        return;
    }
    if (iMem[i] == A[i] + iMem[i-1]) 
        Trace(i-1);
    cout << A[i] << ' ';
}

void TraceLoop(int i, int ans) {
    int first = i, last = i, sum = A[first];
    vector<int> trace; trace.push_back(A[first]);
    while (sum != ans) {
        first--;
        sum += A[first];
        trace.push_back(A[first]);
    }

    for (int i = trace.size()-1; i >= 0; i--) 
        cout << trace[i] << ' '; 
}

void TraceLoop(int i) {
    vector<int> trace;
    while (A[i] != iMem[i]) {
        trace.push_back(A[i]);
        i--;
    }
    trace.push_back(A[i]);

    for (int i = trace.size()-1; i >= 0; i--) 
        cout << trace[i] << ' '; 
}

int main() {
    // memset(bMark, false, sizeof(bMark));
    maxSum(n);
    int ans = 0;
    int index = 0; // last index of maxsubsequence
    for (int i = 1; i <= n; i++) {
        if (ans < iMem[i]) index = i;
        ans = max(ans, iMem[i]);  
    }
    
    cout << ans << endl;
    Trace(index);
    TraceLoop(index, ans);
    TraceLoop(index);
    return 0;
}