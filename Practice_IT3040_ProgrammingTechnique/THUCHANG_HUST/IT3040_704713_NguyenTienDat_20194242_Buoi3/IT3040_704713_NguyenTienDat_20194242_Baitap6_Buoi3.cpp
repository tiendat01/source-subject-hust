#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){
    //# Kh? d? quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    int tmp;
    while (b != 0) {
    	tmp = a % b;
    	a = b;
    	b = tmp; 
    	// khi do a > b do b > tmp
	}
	return a;
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
