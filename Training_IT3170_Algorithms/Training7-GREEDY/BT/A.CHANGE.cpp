// CASHIER.cpp

#include <bits/stdc++.h>
using namespace std;

int X; // số lượng tiền phải đổi X cents
vector<int> c = {1, 5, 10, 50, 100, 500}; // đồng xu mệnh giá c[0] < c[1] < c[2] < ...
vector<int> solution(6, 0); // solution[i] = số luọng đồng xu mệnh giá c[i] sẽ dùng để trả X cents

void Cashier() {
  int n = c.size();
  // duyệt theo chiều giảm dần của mệnh giá đồng xu trong mảng c đã sắp xếp
  for (int i = n-1; i >= 0; i--) {
    if (X >= c[i]) {
      solution[i] = X / c[i];
      X = X % c[i];
    }
  }
}

int main() {
  int taken_items; cin >> taken_items;
  X = 1000 - taken_items;
  Cashier();
  int sum = 0;
  for (vector<int>::iterator it = solution.begin(); it != solution.end(); it++) {
    sum += *it;
  }
  cout << sum;
}