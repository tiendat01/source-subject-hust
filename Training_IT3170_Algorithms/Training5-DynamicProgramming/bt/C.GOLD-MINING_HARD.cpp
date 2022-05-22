

// O(n)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n, L1, L2;
int a[N];
int f[N];

void input() {
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

int main() {
    int res = 0;
    input();
    deque<int> q; // luu chi so
    // i-L2 <= q.front() <= i-L1
    for (int i = 1; i <= n; i++) {
        if (i > L1) {
            // xoa den khi q.front() >= i-L2
            while (!q.empty() && q.front() < i - L2) {
                q.pop_front();
            }
            // f[q.back()] > f[i-L1] => add i-L1 vao sau deque
            // => thu tu cac phan tu (index) trong deque tu front -> back
            // s/c f[index] la giam dan
            while (!q.empty() && f[q.back()] <= f[i-L1]) {
                q.pop_back();
            }
            q.push_back(i-L1);

            f[i] = a[i] + f[q.front()];
        } 
        else {
            f[i] = a[i];
        }
        res = max(res, f[i]);
    }
    cout << res;
    return 0;
}

// 6 2 3
// 3 5 9 6 7 4

// => 19