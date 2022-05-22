#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

int binom2(int n, int k){
    //# Kh? d? quy
    // code here
    if (k > n) return 0;
    int binom = 1;
    for (int i = 1; i <= k; i++) {
    	binom = binom * n / i;
    	n--;
	}
    return binom;
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}



//// chua bai
//#include <iostream>
//using namespace std;
//
//int binom(int n, int k) {
//    if (k > n) return 0;
//    if (k == 0) return 1;
//    return binom(n-1, k) + binom(n-1, k-1);
//}
//int c[50][50];
//
//void initialize() {
//	c[0][1] = c[1][1] = 1;
//	for (int n = 2; n < 50; n++) {
//		for (int k = 0; k <= n; k++) {
//			if (k == 0) c[k][n] = c[k][n-1];
//			else c[k][n] = c[k][n-1] + c[k-1][n-1];
//		}
//	}
//}
//
//int binom2(int n, int k){
//    return c[k][n];
//    //# Kh? d? quy
//    /*****************
//    # YOUR CODE HERE #
//    *****************/
//    
//}
//
//int main() {
//    int m;
//    cin >> m;
//    initialize();
//    for (int n = 1; n <= m; ++n){
//        for (int k = 0; k <= n; ++k)
//            printf("%d ", binom(n, k));
//        printf("\n");
//    }
//    for (int n = 1; n <= m; ++n){
//        for (int k = 0; k <= n; ++k)
//            printf("%d ", binom2(n, k));
//        printf("\n");
//    }
//    return 0;
//}
