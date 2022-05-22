#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> a;
// tim bo 3 so trong mảng a có tổng bằng K
// O(n^2log(n))

void input() {
    cin >> N >> K;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
}

int count_binary_search(int i_low, int i_high, int k) {
    if (i_low > i_high) return 0;
    else {
        int mid = (i_low + i_high) >> 1;
        if (a[mid] == k) {
            return 1 + count_binary_search(i_low, mid-1, k)
                     + count_binary_search(mid+1, i_high, k);
                     // nếu có số thứ 3 trùng nhau
        }
        else if (a[mid] < k) {
            return count_binary_search(mid+1, i_high, k);
        }
        else {
            return count_binary_search(i_low, mid-1, k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input(); // a đã sort
    int ans = 0;
    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            if (a[i] + a[j] > K) continue;
            ans += count_binary_search(j+1, N-1, K-a[i]-a[j]);
        }
    }
    cout << ans;
    return 0;
}