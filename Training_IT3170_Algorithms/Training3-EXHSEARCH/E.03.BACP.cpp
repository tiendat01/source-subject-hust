#include <bits/stdc++.h>
using namespace std;

const int N = 17; // 2<=N<=16
const int M = 6; // 2<=M<=5
int n, m; // n courses, m periods
int credits[N];
int A[N][N];

vector<int> ccredits_period;
int period_of_course[N];
bool cur_course[M][N]; // ds course cua cac periods
int mincredit = INT_MAX;
int maxload = 0;
int minimal_maxload = INT_MAX;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> credits[i];
        mincredit = min(mincredit, credits[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }
    ccredits_period.resize(m+1);
    for (int i = 1; i <= m; i++)
        ccredits_period[i] = 0;
}

void updateBest() {
    minimal_maxload = min(maxload, minimal_maxload);
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ' ' << period_of_course[i] << endl;
    // }
}

bool check(int course, int period) {
    for (int i = 1; i <= n; i++) {
        // theo de bai
        // course i se duoc gan vao period sau period ma course duoc gan, neu course[i] da duoc gan vao period nao do (period_of_course[i] > 0)
        // => period_of_course[i] > period_of_course[course], nguoc lai, se false
        if (A[course][i] && period_of_course[i] > 0) {
            if (period_of_course[i] <= period)
                return false;
        }
    }
    return true;
}

// k la course , i la period
void Try(int k) {
    for (int i = 1; i <= m; i++) {
        if (check(k, i)) {
            ccredits_period[i] += credits[k];
            period_of_course[k] = i;
            int gtribandau = maxload;
            maxload = maxload < ccredits_period[i] ? ccredits_period[i] : maxload;

            if (k == n) updateBest();
            else {
                if (maxload < minimal_maxload)
                    Try(k+1);
            }

            ccredits_period[i] -= credits[k];
            period_of_course[k] = 0;
            maxload = gtribandau;
        }
    }
}

int main() {
    input();
    Try(1);
    cout << minimal_maxload;
    return 0;
}