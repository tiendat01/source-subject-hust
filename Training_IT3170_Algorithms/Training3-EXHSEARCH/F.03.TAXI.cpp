// CBUS: with maxload = 1

#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int n;
int d[N][N];
int maxload = 1;

int x[N];
int f = 0, f_best = INT_MAX;
int load = 0;
bool visited[N];
int dm = INT_MAX;

bool check(int v) {
    if (visited[v]) return false;
    if (v <= n) {// v la diem don
        if (load >= maxload) return false;
    } else { // v la diem tra
        if (!visited[v-n]) return false;
    }
    return true;
}

void input() {
    cin >> n;
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> d[i][j];
            if (d[i][j] < dm && i != j) 
                dm = d[i][j]; // dmin để tính nhánh cận
        }
    }
}

void updateBest() {
    // when k = 2*n. quay về điểm xuất phát 0
    if (f_best > f + d[x[2*n]][0]) 
        f_best = f + d[x[2*n]][0];
}

// thu tat ca cac gia tri cho x[k] khi da biet x[0], x[1],... x[k-1]
void Try(int k) {
    for (int v = 1; v <= 2*n; v++) {
        if (check(v)) {
            x[k] = v;

            f = f + d[x[k-1]][x[k]];
            if (v <= n) load+=1; // diem don
            else load-=1; // diem tra
            visited[v] = true;

            if (k == 2*n) updateBest();
            else {
                if ( f + dm * (2*n+1-k) < f_best) 
                    Try(k+1);
            }

            visited[v] = false;
            if (v <= n) load -= 1; else load += 1;
            f = f - d[x[k-1]][x[k]];
        }
    }
}

int main() {
    input();
    Try(1);
    cout << f_best;
}