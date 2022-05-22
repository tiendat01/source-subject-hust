



// Examples
// input
// 7 1
// 9400000 10000000
// 9500000 10000000
// 9600000 10000000
// 9700000 10000000
// 9800000 10000000
// 9900000 10000000
// 10000000 10000000
// output
// 1358000000000000
// inputCopy
// 4 10
// -7 5
// -2 3
// 5 7
// 9 5
// outputCopy
// 42


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct kh {
  ll x; // vị trí
  ll m; // số lượng
};

bool myComparator(kh a, kh b) {
  return a.x > b.x;
}

int n, k;
vector<kh> p_ls;
vector<kh> n_ls;

void input() {
  cin >> n >> k;
  kh tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp.x >> tmp.m;
    if (tmp.x >= 0) p_ls.push_back(tmp);
    else {
      tmp.x = -tmp.x;
      n_ls.push_back(tmp);
    }
  }
  sort(p_ls.begin(), p_ls.end(), myComparator);
  sort(n_ls.begin(), n_ls.end(), myComparator);
}

ll postman(vector<kh> ls) {
  ll n = ls.size(); ls.push_back({0,0});
  ll cur = k;
  ll sum_dist = ls[0].x;
  for (ll i = 0; i < n; i++) {
    if (cur > ls[i].m) {
      cur -= ls[i].m;
      sum_dist += (ls[i].x - ls[i+1].x);
    }
    else if (cur < ls[i].m) {
      ls[i].m -= cur; cur = 0;
      sum_dist += ls[i].x; cur = k; // quay về điểm xuất phát
      if (ls[i].m >= k) {
        ll thuong = ls[i].m / k;
        ll sodu = ls[i].m - thuong * k;
        // vừa khít
        if (sodu == 0) {
          sum_dist += 2 * ls[i].x * thuong; // vòng đi vòng lại và quay lại điểm đang dở dang
          cur = k;
          sum_dist += ls[i+1].x;
        }
        else {
          cur = (thuong+1)*k - ls[i].m;
          sum_dist += 2 * ls[i].x * thuong + ls[i].x;
          sum_dist += (ls[i].x - ls[i+1].x);
          // cout << "?" << endl;
        }  
        
      }
      else {
        sum_dist += ls[i].x; // từ điểm xuất phát quay lại
        cur -= ls[i].m;
        sum_dist += (ls[i].x - ls[i+1].x);
      }
    }
    else {
      cur = k;
      sum_dist += ls[i].x + ls[i+1].x;
    }
    // cout << "tiếp theo là " << i+1 << ' ' << sum_dist;
  }
  return sum_dist;
}

int main() {
  input();
  cout << postman(p_ls) + postman(n_ls);
}