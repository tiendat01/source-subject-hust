#include <iostream>

using namespace std;

int lucas(int n) {
    if (n == 0) return 2;
    if (n == 1) return 1;
    return lucas(n-1) + lucas(n-2);
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
	int n = 5;
	cout << lucas(n);
}
