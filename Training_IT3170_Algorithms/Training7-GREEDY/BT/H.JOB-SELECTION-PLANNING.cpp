#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;

bool checked[N];
int n;
int max_d = 0;
vector<int> mydata[N];
int res = 0;

void input() {
  cin >> n; 
  int d, p; // d deadline = end
  for (int i = 0; i < n; i++) {
    cin >> d >> p;
    max_d = max(max_d, d);
    checked[d] = true;
    mydata[d].push_back(p);
  }
}

void my_sort() {
  for (int i = 0; i < n; i++) {
    if (checked[i]) {
      sort(mydata[i].begin(), mydata[i].end());
    }
  }
}

void job_selection() {
  for (int i = max_d; i >= 1; i--) {
    int tmp = 0;
    int index = 0;
    for (int j = max_d; j >= i ; j--) {
      if ( checked[j]) {
      if (tmp < mydata[j][mydata[j].size()-1]) {
        tmp = mydata[j][mydata[j].size()-1];
        index = j;
      }
    }}
    mydata[index].pop_back();
    if (mydata[index].size() < 1) checked[index] = false;
    res += tmp;
  }
}

int main() {
  input();
  my_sort();
  job_selection();
  cout << res;
}
