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

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) 
    //         cout << c[i][j] << ' ';
    //     cout << endl;
    // }
}

// return mem[i][S] la chi phi nho nhat
// di qua toan bo cac dinh va quay ve 1
// neu hien tai dang o dinh i va da tham tat ca cac dinh trong S

// g/s thanh pho 1 la tp xuat phat
int TSP(int i , int S) {
    if ( S == ((1<<(n+1))-1) -1) {
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

void Trace(int i, int S) {
    cout << i << ' ';
    if (S == ((1<<(n+1))-1) -1) return ;

    int res = mem[i][S];
    for (int j = 1; j <= n; ++j) {
        if (S & (1 << j))
            continue;
        if (res == c[i][j] + mem[j][S | (1 << j)]) {
            Trace(j, S | (1 << j));
            break;
        }
    }
}

void TraceLoop (int ans) {
    stack<int> st;
    st.push(1);
    int i = 1, S = 1 << 1;
    for (int k = 2; k <= n; k++) {

        for (int j = 1; j <= n; ++j) {
            if (S & (1 << j)) {
                ;
            }
            else {
                if (mem[i][S] == c[i][j] + mem[j][S | (1 << j)]) {
                    st.push(j);
                    i = j;
                    S = S | (1 << j);
                    break;
                }
            }
        }
    }

    vector<int> reverse;
    while (!st.empty()) {
        reverse.push_back(st.top());
        st.pop();
    }
    // in
    for (vector<int>::reverse_iterator rit = reverse.rbegin(); rit != reverse.rend(); ++rit )
        cout << *rit << ' ';
    cout << "quay ve 1";
}

int main() {
    prepare();
    input();

    int ans = TSP(1, 1 << 1);
    cout << ans << endl; // xp tu dinh 1, S chua dinh 1 => S = 1 << 1 = 10 (bit)
    // Trace(1, 1 << 1); cout << "quay ve 1";
    TraceLoop(ans);
    return 0;

}


// 4 12
// 1 2 10
// 1 3 15
// 1 4 20
// 2 1 10
// 2 3 35
// 2 4 25
// 3 1 15
// 3 2 35
// 3 4 30
// 4 1 20
// 4 2 25
// 4 3 30

// ==> 80