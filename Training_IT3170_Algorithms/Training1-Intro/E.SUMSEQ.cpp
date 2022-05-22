#include <iostream>

using namespace std;

int main() {
    int n;
    const unsigned long long c = 1000000007;
    unsigned long long in, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> in;
        in %= c;
        sum += in;
        if (sum > c) sum %= c;
    }

    cout << sum;
    return 0;

}