#include <iostream>
using namespace std;

int f(int n) {
    if (n < 3) return 1;
    if (n < 12) return f(n-1) + f(n-2);
    if (n == 12) return f(n-1) + f(n-2) - f(1);
    if (n == 13) return f(n-1) + f(n-2) - f(1) - (f(n-11) - f(n-12));
    if (n > 13) return f(n-1) + f(n-2) - (f(n-11) - f(n-12)) - (f(n-12) - f(n-13));
}

int main() {
    int m, n;
    cin >> n >> m;
    cout << "So cap tho trong thang n = " << n << ": " << m * f(n) << endl;
    cout << "So tien ban tho trong thang n = " << n << ": " << (m * f(n-11) * 10); // tong so tho da ban sau thang thu n, 10d/cap, m cap ban dau.
}