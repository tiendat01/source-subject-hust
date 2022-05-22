#include <bits/stdc++.h>
using namespace std;
const int N = 31;
const int M = 11;
int m; // teacher
int n; // course
bool can_teach[M][N];
bool conflict[N][N];
int ksl;

bool cur_course[M][N]; // ds course cua cac teacher hien tai
// bool mark[N];
vector<int> ccourse_teacher; // số lượng khoá học của mỗi teacher
int minimal_maxload = INT_MAX;
int maxload = 0;

void input() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int course;
            cin >> course;
            can_teach[i][course] = true; // teacher i co the day course j
        }
    }
    cin >> ksl;
    for (int i = 1; i <= ksl; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != c2) {
            conflict[c1][c2] = true;
            conflict[c2][c1] = true;
        }
    }
    // khoi tao so luong course ban dau cua moi giao vien la 0
    ccourse_teacher.push_back(0);
    for (int i = 1; i <= m; i++) {
        ccourse_teacher.push_back(0);
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j<= n; j++) {
    //         cout<<conflict[i][j]<< ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

void updateBest() {
    minimal_maxload = min(maxload, minimal_maxload);
    // cout << endl;
    // for (int i = 1; i <= m; i++) {
    //     cout << ccourse_teacher[i] << ' ';
    //     for (int j = 1; j <= n; j++) {
    //         cout << cur_course[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}

bool check(int course, int teacher) {
    // if (mark[course]) return false;
    if (!can_teach[teacher][course]) return false;
    // xet cac course da gan tu truoc cho teacher:
    for (int i = 1; i < course; i++) {
        if (cur_course[teacher][i] && conflict[course][i]) {
            return false;
        }
    }
    return true;
}

// k la course
void Try(int k) {
    for (int i = 1; i <= m; i++) {
        if (check(k, i)) {
            // mark[k] = true;
            cur_course[i][k] = true;
            ccourse_teacher[i]++;
            int gtribandau = maxload;
            maxload = (maxload < ccourse_teacher[i] ? ccourse_teacher[i] : maxload);

            if (k == n) updateBest();
            else 
                if (maxload < minimal_maxload)  // maxload + (int) ((n-k)/m) < minimal_maxload ??? sai
                    Try(k+1);
                    
            maxload = gtribandau;
            // mark[k] = false;
            cur_course[i][k] = false;
            ccourse_teacher[i]--;
        }
    }
}

int main() {
    input();
    Try(1);
    if (minimal_maxload > INT_MAX - 1) cout << -1;
    else cout << minimal_maxload;
    return 0;
}

// 4 12
// 5 1 3 5 10 12
// 5 9 3 4 8 12
// 6 1 2 3 4 9 7
// 7 1 2 3 5 6 10 11
// 25
// 1 2
// 1 3
// 1 5
// 2 4
// 2 5
// 2 6
// 3 5
// 3 7
// 3 10
// 4 6
// 4 9
// 5 6
// 5 7
// 5 8
// 6 8
// 6 9
// 7 8
// 7 10
// 7 11
// 8 9
// 8 11
// 8 12
// 9 12
// 10 11
// 11 12


// => 3