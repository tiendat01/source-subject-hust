
// 50 points ???
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll unit[16]; // 1, 10, 100, 1000 ... => lấy chữ số hàng ...

void prepare() {
  unit[0] = 1; // 10 ^ 0
  for (int i = 1; i <= 15; i++) {
    unit[i] = unit[i-1] * 10; // 10 ^ i
  }
}

void atm(ll W, ll c) {
  if (W % 1000) {
    cout << 0 << endl; return ;
  }

  ll N = 0, S = 1; // N là số tờ tiền nhỏ nhất, S là số cách để đổi đc N tờ tiền 
  W /= 1000;
  // 5 * unit[c]: mệnh giá lớn nhất
  // nếu 1, 2, 3, 4, 5, 6, 7, 8, 9  * unit[c] có thể tính đc số cách đổi
  // nều >= 10 * unit[c] 
  if (W >= 10 * unit[c]) {
    N += (W - 10*unit[c]) / (5 * unit[c]) + 1;
    W -= N * 5 * unit[c];
  }

  while (W > 0) {
    ll chuso = W / (unit[c]);
    cout << chuso << ' ';
    W -= (chuso * unit[c]);
    c--;

    if (chuso == 1 || chuso == 2 
     || chuso == 3 || chuso == 5) N += 1;
    if (chuso == 4 || chuso == 7 
     || chuso == 8 || chuso == 6) N += 2;
    if (chuso == 9) N += 3;

    if (chuso == 0 || chuso == 1 || chuso == 2 
    || chuso == 3 || chuso == 5 
    || chuso == 7 || chuso == 8) S *= 1; // chỉ có 1 cách đổi tiền
    if (chuso == 4 || chuso == 6) S *= 2; // có 2 cách
    if (chuso == 9) S *= 3;

  }

  cout << N << ' ' << S << endl;
}

int main() {
  prepare();
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    int W, c;
    cin >> W >> c;
    atm(W, c);
  }
}


// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long ;
// ll w, c;
// int cnt[10] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};
// int s[10] =   {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};

// ll mu10(int c) {
//   if (c == 0) {
//     return 1;
//   } else {
//     return 10 * mu10(c-1);
//   }
// }

// void solve() {
//   cin >> w >> c;
//   if (w % 1000) {
//     cout << "0\n";
//     return ;
//   }
//     w /= 1000;
//   unsigned long long m = (10 * mu10(c));
//   // cach 1:
//   // ll r = w / m;
//   // ll sototien = r * 2;
//   // ll socach = 1;
//   // w %= m;
//   // if (sototien > 0 && m/2 + w < m) {
//   //   sototien--;
//   //   w += m/2;
//   // }

//   ll sototien = 0;
//   ll socach = 1;
//   if (w >= m) {
//     sototien += (w - m) / (m/2) + 1;
//     w -= sototien * 5 * mu10(c);
//   }

//   while(w > 0) {
//     int d = w % 10;
//     sototien += cnt[d];
//     socach *= s[d];
//     w /= 10;
//   }

//   cout << sototien << " " << socach << "\n";
// }

// int main() {
//   int T;
//   cin >> T;
//   while (T--) {
//     solve();
//   }
// }
