#include <bits/stdc++.h>
using namespace std;

void Cashier(int X, int c[], vector<int> &solution, int n) {
  // duyệt theo chiều giảm dần của mệnh giá đồng xu trong mảng c đã sắp xếp
  for (int i = n-1; i >= 0; i--) {
    if (X >= c[i]) {
      solution[i] = X / c[i];
      X = X % c[i];
    }
  }
}

int main() {

  int X = 289; // số lượng tiền phải đổi X cents
  int c[] = {1, 5, 10, 25, 100}; // đồng xu mệnh giá c[0] < c[1] < c[2] < ...
  int n = 5;
  vector<int> solution(5, 0); // solution[i] = số luọng đồng xu mệnh giá c[i] sẽ dùng để trả X cents
  Cashier(X, c, solution, n);

  int sum = 0;
  for (vector<int>::iterator it = solution.begin(); it != solution.end(); it++) {
    sum += *it;
  }
  cout << sum;
}