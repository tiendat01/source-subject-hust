#include <iostream>

using namespace std;

bool search(long long *a, int n, const long long b) {
    a[n] = b;
    int i = 0;
    while (a[i] != b)
    {
        i++;
    }
    if (i >= n) return false;
    else return true;
}

int main() {
    int n, m;
    long long a[32], b[32];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int j = 0; j < m; j++) 
        cin >> b[j];

    for (int j = 0; j < m; j++) {
        if (!search(a, n, b[j])) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}