#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# m?ng ghi nh? l?i gi?i các bài toán con dã du?c gi?i

void init(){
    memset(mem, -1, sizeof(mem));
}

//# Quy ho?ch d?ng, 
//# Hàm lis(i) tr? v? d? dài dãy con tang dài nh?t k?t thúc b?i a[i]
int lis(int i) {
	// code here
    int max_length = 0;
    for (int j = 0; j < i; j++) {
    	if (a[j] < a[i] && mem[j] > max_length) max_length = mem[j];
	}
	mem[i] = max_length + 1;
	// mem[i] = [ max(0<=j<=i-1 && a[j]<=a[i]) (mem[j]) ] + 1
	return mem[i];
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    // in ra phan tu lon nhat cuoi cung cua day
    cout << a[i] << " ";
}

int main(){
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int res = 0, pos = 0;
    
    for(int i = 0; i < n; i++){
    	// cout << lis(i) << ' ';
        if (res < lis(i)){
            res = lis(i);
            pos = i; // pos la vi tri cuoi cung cua day con tang dai nhat
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}


//// chua bai: 
//
//#include <bits/stdc++.h>
//using namespace std;
//int a[1000], n;
//int mem[1000]; //# m?ng ghi nh? l?i gi?i các bài toán con dã du?c gi?i
//
//void init(){
//    memset(mem, -1, sizeof(mem));
//}
//
////# Quy ho?ch d?ng, 
////# Hàm lis(i) tr? v? d? dài dãy con tang dài nh?t k?t thúc b?i a[i]
//int lis(int i) {
//	// code here
//    if (mem[i] == -1) {
//    	int max_length = 0;
//    	for (int j = 0; j < i; j++) {
//    		if (a[j] < a[i]) max_length = lis(j);
//		}
//		mem[i] = max_length + 1;
//	}
//	return mem[i];
//}
//
////# Truy vet loi giai
//void trace(int i){
//    for(int j = 0; j < i; j++){
//        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
//            trace(j);
//            break;
//        }
//    }
//    // in ra phan tu lon nhat cuoi cung cua day
//    cout << a[i] << " ";
//}
//
//int main(){
//    init();
//    cin >> n;
//    for(int i = 0; i < n; i++) cin >> a[i];
//    
//    int res = 0, pos = 0;
//    
//    for(int i = 0; i < n; i++){
//    	// cout << lis(i) << ' ';
//        if (res < lis(i)){
//            res = lis(i);
//            pos = i; // pos la vi tri cuoi cung cua day con tang dai nhat
//        }
//    }
//    cout << res << endl;
//    trace(pos);
//    return 0;
//}
