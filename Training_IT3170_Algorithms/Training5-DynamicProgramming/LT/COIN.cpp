#include <bits/stdc++.h>
using namespace std;

int n;
int D[11];
const int INF = 1e6;
int iMem[11][10001];

int minCoin[10001];

void prepare() {
    memset(iMem, -1, sizeof(iMem));
    for (int i = n; i >= 0; i--) iMem[i][0] = 0; // het x
}

void input() {
    cin >> n; // 3
    for (int i = 1; i <= n; i++) cin >> D[i]; // 1 3 5
}

// O(n*x)
// i la chi so cuoi cung cua D (co i menh gia), so tien can doi x
int MinCoin(int i, int x) { 
    // neo de quy co so:
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (i == 0) return INF; // ko co dong xu nao

    if (iMem[i][x] != -1) return iMem[i][x];
    int res = INF;
    res = min(res, 1 + MinCoin(i, x - D[i])); // dung dong tien D[i]
    res = min(res, MinCoin(i-1, x)); // ko dung dong tien D[i], chuyen sang dong tien D[i-1]
    iMem[i][x] = res;
    return res;
}

// phu thuoc vao thu tu cua D[]
void Trace(int i, int x) {
    if (x < 0) 
        return ;
    if (x == 0) {
        return ;
    }
    if (i == 0) {
        return ;
    }

    if (x >= D[i] && iMem[i][x] == 1 + iMem[i][x - D[i]]) {
        cout << D[i] << ' ';
        Trace(i, x-D[i]);
    }
    else 
        Trace(i-1, x);
}

void TraceLoop(int x) {
    int ans = iMem[n][x];
    int i = n;
    while (x != 0) {
        if (x >= D[i] && iMem[i][x] == 1 + iMem[i][x - D[i]]) {
            cout << D[i] << ' ';
            x -= D[i];
        } else {
            i--;
        }
    }
}

int main() {
    input();
    prepare();
    int x = 13;
    cout << MinCoin(n, x) << endl;    
    Trace(n, x);
    cout << endl;

    // in 
    // cout  << endl << "iMem:" << endl;
    // for (int i = n; i>=1; i--) {
    //     cout << D[i] << endl;
    //     for (int j = 0; j<=x; j++) {
    //         cout << iMem[i][j] << "   ";
    //     }
    //     cout << endl;
    // }
    TraceLoop(x);
    cout << endl << "Cach 2: ";



    // c2: loop
    for (int i = 1; i <= x; i++) {
        minCoin[i] = INT_MAX;
    }
    // menh gia i: bai toan con
    for (int i = 1; i <= x; i++) { 
        // dong tien co chi so j
        for (int j = 1; j <= n; j++) {
            if (i >= D[j] && minCoin[i] > 1 + minCoin[i-D[j]]) {
                minCoin[i] = 1 + minCoin[i-D[j]];
            }
        }
    }

    cout << minCoin[x];



    return 0;
}