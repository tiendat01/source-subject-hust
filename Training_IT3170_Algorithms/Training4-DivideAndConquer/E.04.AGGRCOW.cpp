#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull N, C; // N chuồng và C con bò
vector<ull> x; // vị trí x[i]
ull ans = 0;

void input() {
    cin >> N >> C;
    x.assign(N, 0);
    for (ull i = 0; i < N; i++) {
        cin >> x[i];
    }
    ans = 0;
    sort(x.begin(), x.end());
}

bool check(int min_distance) {
    ull ccows = 1; // con bò đầu tiên cho vào chuồng x[0]
    ull cur_pos = x[0];
    for (ull i = 1; i < N; i++) {
        if (x[i] - cur_pos >= min_distance) {
            cur_pos = x[i];
            ccows++;
        }
    }
    return ccows >= C; // đúng nếu với min_distance, các con bò phải vào hết chuồng
}

// tim largest
ull ans_binary_search(ull low, ull high) {
    if (low >= high) 
        return ans;
    else {
        ull mid = (low + high) >> 1;
            // cout << low << ' ' << high << ' ' << mid << endl;
        if (check(mid)) {
            ans = mid;
            return ans_binary_search(mid+1, high);
        }
        else 
            return ans_binary_search(low, mid);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ull T;
    cin >> T;
    for (ull i = 0; i < T; i++) {
        input();
        cout << ans_binary_search(0, 1e9+1) << endl;
    }
    return 0;
}