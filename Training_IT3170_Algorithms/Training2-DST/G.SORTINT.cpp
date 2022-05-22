#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        a.push_back(input);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) 
        cout << a[i] << ' ';

    return 0;
}