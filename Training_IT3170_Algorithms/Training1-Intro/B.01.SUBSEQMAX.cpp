#include <iostream>

using namespace std;

// cách 2: QHĐ
long long algo(long long a[], int n) {
    long long max = a[0];
    long long *s = new long long[n];
    s[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (s[i-1] > 0) s[i] = s[i-1] + a[i];
        else s[i] = a[i];
        // update cho ket qua cuoi
        max = max > s[i] ? max : a[i];
    }
    return max;
}
             
int main() {
    long long *a;
    long long n;

    cin >> n;
    a = new long long[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    long long maxsum = 0;
    long long maxsum_tmp = a[0];
    long long i_start = 0, i_end;

    for (long long i = 1; i < n; i++) {
        long long case1 = maxsum_tmp + a[i];
        long long case2 = a[i];
        if (case1 < case2) {
            maxsum_tmp = case2;
            i_start = i;
        }
        else {
            maxsum_tmp = case1;
        }
        // update cho ket qua cuoi
        if (maxsum < maxsum_tmp) {
            maxsum = maxsum_tmp;
            i_end = i;
        }
    }

    cout << maxsum << endl;

    cout << algo(a, n);
    return 0;
}