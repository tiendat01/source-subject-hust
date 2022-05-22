#include <iostream>

using namespace std;

const unsigned long long c = 1000000007;

// a^b = (((a^i))^(b/i)) * a^(b%i) // b chưa chắc chia hết cho i
// a^i > c and a^(i-1) < c
unsigned long long expmod(unsigned long long a, unsigned long long b) {
    if (b == 0) return 1;
    if (b == 1) return a % c;
    else {
        unsigned long long i = 0, pow = 1;
        for (; i < b && pow < c; i++, pow *= a) 
            ;
        return (expmod(pow%c, b/i) * expmod(a, b%i)) % c;
    }
}

// cách 2: chữa:
long long f(long long a, long long b) {
    if (b==0) return 1;
    long long x = f(a, b/2);
    if (b % 2 == 1) return ((x * x) % c * (a % c)) % c;
    else return (x * x) % c;
}

int main() {
    unsigned long long a, b;
    cin >> a >> b;
    cout << expmod(a, b);
    cout << endl << f(a, b);
    return 0;
}