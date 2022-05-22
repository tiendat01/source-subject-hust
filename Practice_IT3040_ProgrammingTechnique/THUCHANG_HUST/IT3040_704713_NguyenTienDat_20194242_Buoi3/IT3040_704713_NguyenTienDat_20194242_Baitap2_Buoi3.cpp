#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# Luu t?a d? các bu?c di chuy?n c?a quân mã
int mark[100][100]; //# Ðánh d?u v? trí các ô mà quân mã dã di chuy?n qua

//# M?ng hx, hy mô t? 8 v? trí quân mã có th? di chuy?n k? t? v? trí hi?n t?i
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuy?n tìm du?c
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

bool isUCV(int xx, int yy) {
	if (xx < 1 || xx > n || yy < 1 || yy > n || mark[xx][yy] == 1) return false;
	return true;
}

//# Thu?t toán quay lui
void TRY(int k){
	// chay tat ca loi giai bo phan co the xay ra
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        // code here
        // check xem co phai UCV
        if (isUCV(xx, yy)){
        	// cap nhat trang thai moi
        	X[k] = xx;
        	Y[k] = yy;
        	mark[xx][yy] = 1;
        	// neu hoan thanh 1 loi giai day du, buoc neo de quy
        	if (k == n*n) print_sol();
        	else TRY(k+1);
        	// sau khi hoan thanh 1 loi giai day du phai khoi phuc trang thai ban dau cua cac o
        	mark[xx][yy] = 0;
		}
    }
}

int main(){
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}



// chua bai
//#include <iostream>
//using namespace std;
//
//int n;
//int X[100], Y[100]; //# Luu t?a d? các bu?c di chuy?n c?a quân mã
//int mark[100][100]; //# Ðánh d?u v? trí các ô mà quân mã dã di chuy?n qua
//
////# M?ng hx, hy mô t? 8 v? trí quân mã có th? di chuy?n k? t? v? trí hi?n t?i
//const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
//const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};
//
////# In ra dãy các di chuy?n tìm du?c
//void print_sol(){
//    for (int j = 1; j <= n * n; ++j)
//        printf("(%d %d)\n", X[j], Y[j]);
//    exit(0);
//}
//
////# Thu?t toán quay lui
//void TRY(int k){
//	// buoc neo de quy
//	if (k>n*n) {
//		print_sol();
//		return ;
//	}
//	
//    for(int i = 0; i < 8; i++){
//        int xx = X[k-1] + hx[i];
//        int yy = Y[k-1] + hy[i];
//        /*****************
//        # YOUR CODE HERE #
//        *****************/
//        if (xx < 1 || xx > n || yy < 1 || yy > n || mark[xx][yy] == 1) continue;
//		X[k] = xx;
//		Y[k] = yy;
//		mark[xx][yy] = 1;
//		
//		TRY(k+1);
//		
//		mark[xx][yy] = 0;
//    }
//}
//
//int main(){
//    cin >> n;
//    mark[1][1] = 1;
//    X[1] = Y[1] = 1;
//    TRY(2);
//    return 0;
//}
