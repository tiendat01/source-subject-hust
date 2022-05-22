// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e6+1;

// int n, m;
// long long h[N];
// vector<long long> tong;
// long long tong_lanluot = 0;

// int maxh;

// void input() {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++) {
//         cin >> h[i];
//     }
//     sort(h, h+n);
//     for (int i = n-1; i >= 0; i--) {
//         tong_lanluot += h[i];
//         tong.push_back(tong_lanluot);
//     }
// }


// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(); // them dong nay la 100 đ ???

//     input();
//     int i = n-1;
//     while (i >= 0) {
//         if ((maxh = (tong[n-i-1] - m) / (n-i)) >= h[i-1] )
//             break;
//         i--;
//     }
//     cout << maxh;
//     return 0;
// }


// O(log(max(ai)) * n)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M;
vector<ll> tree_height;
ll ans = LLONG_MIN;
 
void input() {
    cin >> N >> M;
    for (ll i = 0; i < N; i++) {
        ll data;
        cin >> data;
        tree_height.push_back(data);
    }
}

// H la chieu dai luoi cua
ll sum_of_woodcut(ll H) {
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
        if (tree_height[i] > H) {
            sum += (tree_height[i] - H);
        }
    }
    return sum;
}

ll ans_binary_search(ll low, ll high) {
    if (low >= high) 
        return ans;
    else {
        ll mid = (low + high) >> 1;
        ll sum = sum_of_woodcut(mid);

        //  tim chieu dai luoi cua cao nhat co the
        // sum_of_woodcut at least M
        if (sum >= M) {
            ans = mid;
            return ans_binary_search(mid+1, high); // bo +1 o mid => tle ?

        } else {
            return ans_binary_search(low, mid);
        }
    }
} 


// loop
bool check(ll h) {
    ll S = 0; 
    for (ll i = 0; i < N; ++i)
        if (tree_height[i] > h) S += (tree_height[i] - h);
        // else S += tree_height[i];
    if (S >= M) return true;
    return false;
}

int chatnhiphan() {
    ll l = 0, r = LLONG_MAX, mid , res = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid + 1, res = mid;
        else r = mid - 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    input();
    // cout << ans_binary_search(0, LLONG_MAX);
    cout << chatnhiphan();
    return 0;
}