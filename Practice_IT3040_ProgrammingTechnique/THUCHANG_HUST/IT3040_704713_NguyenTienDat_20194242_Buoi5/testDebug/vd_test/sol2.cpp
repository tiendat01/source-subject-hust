#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    freopen("LIS.inp", "r", stdin);
    freopen("sol2.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> f(n); // luu ket qua
    for (int i = 0; i < f.size(); ++i){
        int &ans = f[i] = 1;
        for (int j = 0; j < i; ++j){
            if (a[j] < a[i]) ans = max(ans, f[j]+1);
        }
    }
    cout << *max_element(f.begin(), f.end());
}