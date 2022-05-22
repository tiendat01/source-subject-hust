#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n; // số cây trông 
int t[N]; // thời gian thu hoạch - 1

bool my_compare(int a, int b) {
    return a > b;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    sort(t+1, t+n+1, my_compare);
    // trồng theo thứ tự hạt có t/g thu hoạch nhỏ nhất
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    input();

    int seeding_day = n;
    int thuhoach = 0;
    for (int i = 1; i <= n; i++) {
        thuhoach = max(thuhoach, i+t[i]);
    }

    int party_time = thuhoach + 1;

    cout << party_time;

}