/*
Có bao nhieu cach chia m keo cho n em be
s/c em nao cung co keo => x1+x2+x3+...+xn = m
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 30;

int n = 9, m = 20;
int f = 0; // so keo da chia
int m_conlai; // so keo con lai sau khi chia cho k em
int x[N]; // x[i] : so keo chia cho em be i
int res = 0;

bool isUCV() {
    return true;
}

void Try(int k) {
    if (k == n) {
        x[k] = m_conlai - f;
        res++;
        return ;
    }
    m_conlai = m - f - (n-k); // do moi em be co it nhat 1 keo, ma con n-k em nua
    for (int v = 1; v <= m_conlai; ++v) {
        x[k] = v;
        f = f+v;
        Try(k+1); // em tiep theo
        f = f-v;
    }
    return ;
}


int main() {
    Try(1);
    cout << res;
}