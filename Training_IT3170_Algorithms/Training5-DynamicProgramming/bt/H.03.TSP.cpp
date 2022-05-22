#include <bits/stdc++.h>
using namespace std;

const int N = 21;
const int INF = 1e8;
int c[N][N];
int mem[N][1<<N];
int n, m;

void prepare() {
    memset(mem, -1, sizeof(mem));
    memset(c, -1, sizeof(c));
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        c[from][to] = cost;
    }
}

// return mem[i][S] la chi phi nho nhat
// di qua toan bo cac dinh va quay ve 1
// neu hien tai dang o dinh i va da tham tat ca cac dinh trong S
// S la cac dinh da tham

// O(2^n * n^2)

// g/s thanh pho 1 la tp xuat phat
int TSP(int i , int S) {
    if ( S == ((1<<(n+1))-1) -1) { // 111...1110 => di het cac dinh, bit 0 cuoi cung bo qua vi chay chi so tu dinh 1
        if (c[i][1] > 0) {
            mem[i][S] = c[i][1];
            return c[i][1]; // S la tap tat ca cac dinh, co nghia la da di het => quay ve 1
        }
        else 
            return INF;
    }

    if (mem[i][S] != -1) return mem[i][S];

    int res = INF;
    for (int j = 1; j <= n; j++) {
        // check j thuoc S, nghia la da di qua dinh j chua?
        if (S & (1 << j))
            continue;
        if (c[i][j] > 0)
            res = min(res, c[i][j] + TSP(j, S | (1 << j))); // S hop j
    }
    mem[i][S] = res;
    return res;
}

int main() {
    prepare();
    input();

    int ans = TSP(1, 1 << 1); // 10 => di qua dinh 1 roi
    cout << ans << endl;
    return 0;
}

// 2 2
// 1 2 3
// 2 1 2

// 5
