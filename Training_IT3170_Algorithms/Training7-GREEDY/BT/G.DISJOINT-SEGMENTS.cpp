#include <bits/stdc++.h>
using namespace std;

bool myComparator(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

int earlies_finish_time_first(int n, vector<pair<int, int>> &schedule) {
  sort(schedule.begin(), schedule.end(), myComparator);
  int res = 0;

  int last_finish = schedule[0].second;
  res++;
  for (int i = 1; i < n; i++) {
    if (schedule[i].first > last_finish) {
      res++;
      last_finish = schedule[i].second;
    }
  }

  return res;
}

int main() {
  vector<pair<int, int>> meetings;
  int n;
  cin >> n;
  int s, f;
  for (int i = 0; i < n; i++) {
    cin >> s >> f;
    meetings.push_back({s,f});
  }

  cout << earlies_finish_time_first(meetings.size(), meetings);


}