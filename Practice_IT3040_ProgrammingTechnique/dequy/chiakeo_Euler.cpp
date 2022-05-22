#include <iostream>
using namespace std;

// co bao nhieu cach chia m keo cho n hoc sinh
// m,n >= 0
int chiakeo(int m, int n) {
    if (n == 0) return 0;
    if (m == 0) return 1; // 1 cach duy nhat la moi hs deu co 0 cai keo
    
    if (m < n) return chiakeo(m, m); // khi do chi co m hs dau tien co keo, con n-m hs cuoi cung co 0 keo
    // voi m>=n co 2 TH xay ra
    // TH1: hs cuoi cung ko co keo => n-1 hs dau tien co keo
    // TH2: hs cuoi cung co it nhat 1 keo => chia cho n keo cho n hs, moi hs co 1 keo
    else {
        return chiakeo(m, n-1) + chiakeo(m-n, n);
    }
}



// backtrack liet ke loi giai
int res[1000];
int m, n, state; // state so keo con lai

void print_sol(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << (i == n-1 ? '\n' : ' ');
}

bool isUCV(int j, int state, int k) {
    if (j > state) return false;
    if (k == n-1 && j != state) return false;
    return true;
}

void attempt(int k) {
    for (int j = 0; j <= m; j++) {
        if (isUCV(j, state, k)) {
            res[k] = j;
            state = state - j;
            if (k == n-1) print_sol(res, n);
            else attempt(k+1);
            state = state + j;
        }
    }
}

int main() {
    cout << chiakeo(20,9);
    // m = state = 5;
    // n = 3;
    // attempt(0);
}