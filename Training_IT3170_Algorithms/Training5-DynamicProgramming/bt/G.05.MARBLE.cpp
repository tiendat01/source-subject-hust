/*
cat het hang het cot
iMem[i][j]: dien tich lon nhat cat ra tu hcn ixj
iMem[i][j] = max(
    iMem[i1][j] + iMem[i2][j] voi i1+i2=i,
    iMem[i][j1] + iMem[i][j2] voi j1+j2=j,
    i*j neu tồn tại phiến đá ixj // neo de quy
)

O(W * H * (W+H))
*/

#include <bits/stdc++.h>
using namespace std;

const int L = 601;
int n; 
int W, H;
int iMem[L][L];

void input() {
    memset(iMem, 0, sizeof(iMem));
    cin >> W >> H;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int w, h;
        cin >> w >> h;
        iMem[w][h] = w * h;
    }
}

int main() {
    input();
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            // chia theo chieu ngang
            for (int i1 = 1; i1 < i; i1++) {
                int i2 = i - i1;
                iMem[i][j] = max(iMem[i][j] , iMem[i1][j] + iMem[i2][j]);
            }
            // chia theo chieu doc
            for (int j1 = 1; j1 < j; j1++) {
                int j2 = j - j1;
                iMem[i][j] = max(iMem[i][j] , iMem[i][j1] + iMem[i][j2]);
            }
        }
    }

    cout << W*H - iMem[W][H];

}

// 21 11
// 4
// 10 4
// 6 2
// 7 5
// 15 10
