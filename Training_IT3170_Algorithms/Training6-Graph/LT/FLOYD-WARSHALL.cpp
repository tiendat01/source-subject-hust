// QHĐ: 

// O(V^3)

#include <bits/stdc++.h>
using namespace std;

int iDist[1001][1001];
int Weight[1001][1001];

void prepare() {
    memset(Weight, 1e9, sizeof(Weight));
}

void FloydWarshall(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            iDist[i][j] = (i == j ? 0 : Weight[i][j]);
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                iDist[i][j] = min(iDist[i][j], iDist[i][k] + iDist[k][j]);
            }
        }
    }
}


int main() {
    prepare();

    
}