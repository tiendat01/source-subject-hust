#include <bits/stdc++.h>
using namespace std;

const int N = 3001;
int n, k;
int c[N], a[N];
int f[N][N];
// f[i][j] = so luong hang lon nhat ma may bay dung tai diem i,
// voi j la so dia diem da dung lai : 2 <= j <= k+1 , (it nhat phai dung lai tai 1 diem bat dau)
// ct: f[z][j] = max(f[z][j], f[z][j-1] + c[z]) voi z la diem dung: z = i+1,...,i+a[i]

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k+1; ++j) {
            f[i][j] = INT_MIN;
        }
    }
}

int main() {
    input();

    f[1][1] = c[1];

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= k+1; j++) {
        // z la diem dung tiep theo sau diem dung i
            for (int z = i+1; z <= i+a[i]; z++) {
                if (z > n) break; // diem dung z vuot qua diem n
                
                // diem f[i][j-1] la diem lien truoc f[z][j]
                f[z][j] = max(f[z][j], f[i][j-1] + c[z]);
            }
        }
    }

    // diem cuoi cung la diem n
    if (f[n][k+1] == INT_MIN) cout << -1;
    else cout << f[n][k+1];
    return 0;
}


// cach de quy
// Created by DINH CHI CONG on 12/6/2021.
//

// #include <bits/stdc++.h>
// using namespace std;

// long long n, k;
// long long c[3001], a[3001];

// void input(){
//     cin>>n>>k;
//     for(long long i = 1 ; i<=n;i++){
//         cin>>c[i];
//     }
//     for(long long i = 1 ; i<=n;i++){
//         cin>>a[i];
//     }
// }

// bool check[3001];
// long long max_c[3001];
// long long solution(long long point, long long k_tmp){
//     // danh dau da tinh
//     if (check[point]) return max_c[point];
//     else check[point] = true;

//     //Diem dung
//     if (k_tmp == k+1){
//         if (point != n) {
//             max_c[point]= 0;
//         }
//         else{
//             max_c[point] = c[point];
//         }
//         return max_c[point];
//     }

//     if (point == n) {
//         max_c[point]= c[point];
//         return max_c[point];
//     }

//     //Tinh toan
//     max_c[point] = 0;
//     for (int i=1;i<=a[point];i++){
//         if (point+i>n) break;
//         max_c[point] = max(max_c[point], solution(point + i, k_tmp+1));
//     }

//     if(max_c[point] != 0) max_c[point]+=c[point];

//     return max_c[point];
// }

// int main(){
//     input();
//     cout<<solution(1,1);
// }
/* test case
6 3
2 3 4 56 7 8
1 2 1 2  1 1 */