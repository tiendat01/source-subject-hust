#include <bits/stdc++.h>
using namespace std;

bool myComparator(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

vector<pair<int, int>> earlies_finish_time_first(int n, vector<pair<int, int>> &schedule) {
  sort(schedule.begin(), schedule.end(), myComparator);
  vector<pair<int, int>> res;

  int last_finish = schedule[0].second;
  res.push_back(schedule[0]);
  for (int i = 0; i < n; i++) {
    if (schedule[i].first > last_finish) {
      res.push_back(schedule[i]);
      last_finish = schedule[i].second;
    }
  }

  return res;
}

int main() {
  vector<pair<int, int>> meetings;
  meetings.push_back({0,6});
  meetings.push_back({1,4});
  meetings.push_back({3,5});
  meetings.push_back({3,8});
  meetings.push_back({4,7});
  meetings.push_back({5,9});
  meetings.push_back({6,10});
  meetings.push_back({8,11});

  cout << earlies_finish_time_first(meetings.size(), meetings).size();


}