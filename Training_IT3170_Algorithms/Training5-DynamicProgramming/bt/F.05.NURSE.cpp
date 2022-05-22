#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int n, k1, k2;
int f[N];
int res = 0;

void input() {
    cin >> n >> k1 >> k2;
    memset(f, 0, sizeof(f));
}

// chua tim ra loi giai qhd?


// duyệt toàn bộ ko phải qhd
void nurse(int i) {
    for (int j = k1; j <= k2; j++) {
        i += j;
        // nếu i là ngày cuối cùng 
        // hoặc i là gần cuối (ngày cuối là ngày nghỉ)
        if (i == n || i == n-1) res++;
        else {
            // nhánh cận
            if (i + k1 <= n) nurse(i+1); // +1 là ngày nghỉ
        }
        i-=j;
    }
}

int main() {
    input();
    nurse(0); // ngày đầu tiên là ngày đi làm
    nurse(1); // ngày đầu tiên là ngày nghỉ
    cout << res;
    return 0;
}




// #include <bits/stdc++.h>
// using namespace std;

// const int MAX = 1001;
// int n, k1, k2, f[MAX][MAX], cnt = 0;
// const int mod = 1e9 + 7;

// int main() {
//   cin >> n >> k1 >> k2;
//   memset(f, 0, sizeof(f));
//   f[1][0] = f[1][1] = 1;
//   for (int i = 2; i <= n; i++) {
//     for (int j = k1; j <= k2; j++) {
//       f[i][0] += f[i - 1][j];
//     }
//     for (int j = 1; j <= k2; j++) {
//       f[i][j] = f[i - 1][j - 1];
//     }
//   }
//   for (int i = k1; i <= k2; i++) {
//     cnt = (cnt + f[n][i]) % mod;
//   }
//   cnt = (cnt + f[n][0]) % mod;
//   cout << cnt;
//   return 0;
// }




// #include <algorithm>
// #include <cstring>
// #include <iostream>
// #include <stdlib.h>

// #include <queue>
// #include <stack>
// typedef long long ll;

// using namespace std;

// int N, K1, K2;
// int result = 0;

// // is_holiday indicate that nurse in in holiday
// void set_shift(int remain_days, bool is_holiday) {
//   if (is_holiday) {
//     for (int i = K1; i <= K2; i++) {
//       if (remain_days == i) {
//         result += 1;
//       }

//       if (remain_days < i) {
//         break;
//       }

//       if (remain_days > i) {
//         remain_days -= i;
//         set_shift(remain_days, false);
//         remain_days += i;
//       }
//     }
//   } else {
//     if (remain_days == 0) {
//       result += 1;
//     } else if (remain_days == 1) {
//       result += 1;
//     } else {
//       remain_days -= 1;
//       set_shift(remain_days, true);
//     }
//   }
// }

// int main(int argc, const char *argv[]) {

//   cin >> N >> K1 >> K2;

//   set_shift(N, false);
//   set_shift(N, true);
//   cout << result;
// }