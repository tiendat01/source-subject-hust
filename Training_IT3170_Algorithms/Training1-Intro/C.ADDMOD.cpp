#include <iostream>

using namespace std;

int main() {
    unsigned long long a, b, sum_mod;
    const unsigned long long c = 1000000007;
    cin >> a >> b;
    unsigned long long a1, b1;
    a1 = a % c;
    b1 = b % c;
    sum_mod = a1 + b1;
    cout << ((sum_mod < c) ? sum_mod : (sum_mod % c));
    return 0;
}