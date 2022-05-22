#include <bits/stdc++.h>
using namespace std;

// fibonacci đệ quy có nhớ
int iMem[1001];
void prepare() {
    // for (int i = 0; i <= 1000; i++) 
    //     iMem[i] = -1;
    memset(iMem, -1, sizeof(iMem));
}

int Fib(int n) {
    if (n <= 2) 
        return 1;
    else {
        if (iMem[n] != -1) 
            return iMem[n];
        else {
            iMem[n] = Fib(n-1) + Fib(n-2);
            return iMem[n];
        }
    }
}

int main() {
    prepare();
    cout << Fib(5);
    return 0;
}