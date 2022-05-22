#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x, y, z; // x,y quy dinh base cua block, z la chieu cao height
} block;
int n;
block a[100];
int maxh[100];

void input(){
    cin >> n;
    if (n == 0) exit(0);
    int x, y, z;
    // ban dau n <= n
    for (int i = 1; i <= n; i++){
        cin >> x >> y >> z;
        // cac vien gach co the lật lại / xoay 90 do (reoriented)
        // 2 trong 3 chieu (chon x,y) quy dinh base cua block, chieu con lai (z) la chieu cao cua block
        // 1 vien gach (block) chiem 3 phan tu trong a[]
        a[3 * i - 2].x = x;
        a[3 * i - 2].y = y;
        a[3 * i - 2].z = z;

        a[3 * i - 1].x = y;
        a[3 * i - 1].y = z;
        a[3 * i - 1].z = x;

        a[3 * i].x = z;
        a[3 * i].y = x;
        a[3 * i].z = y;
    }
    // ban dau chua khoi tao
    for(int i=0; i<100; i++) maxh[i] = 0;
}

// chieu cao cua toa thap voi dinh la vien i
int dp(int i){
    if (maxh[i] != 0) return maxh[i];
    
    // j la cac vien o duoi vien i => vien i nho hon ve 2 chieu x,y base so voi vien j
    // va vien i co the xoay 90 do
    for(int j = 1; j <= 3*n; j++){
        if (a[i].x < a[j].x && a[i].y < a[j].y || 
            a[i].x < a[j].y && a[i].y < a[j].x) {
            maxh[i] = max (maxh[i], dp(j));
        }
        // neu ko di vao if, vien gach nay la vien ở đáy tháp
    }
    maxh[i] += a[i].z;
    return maxh[i];
}
 
int main(){
    int cnt = 1;
    while(1){
        int res = 0;
        input();
        for(int i = 1; i <= 3 * n; i++){
            res = max(res, dp(i));
        }
        printf("Case %d: maximum height = %d\n", cnt++, res);
    }
    return 0;
}