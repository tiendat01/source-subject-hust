#include <iostream>

using namespace std;

// loi nhg van chay?
auto maxval(auto x, auto y) {
    return (x > y) ? x : y;
}

int main() {
    auto i = maxval(3,'a'); // ko tuong minh!!!
    cout << i << endl;
}