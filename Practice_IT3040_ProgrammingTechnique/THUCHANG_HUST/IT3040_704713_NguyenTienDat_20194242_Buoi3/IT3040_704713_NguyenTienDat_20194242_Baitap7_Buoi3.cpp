#include <bits/stdc++.h>
using namespace std;
// Gi? s? l?i gi?i du?c luu b?i xâu x1, x2, ..., xn
// i : bieu dien loi giai bo phan cap i, truoc dó x1, x2, ..., x[i-1] dã duoc gán giá tr? => i bat dau tu 1
// j : giá tri ung cu viên dang xét cho vi trí x[i] // j la 0 hoac 1
// old_L: so ký tu 1 liên tiep o cuoi dãy x1, x2, ..., x[i-1]
struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0, 0));
    while (!s.empty()){
        state &top = s.top();
        // cout << top.i << top.j << top.old_L << endl;
        //# if a new binary sequence is found
        if (top.i > n){
        	
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        
        //# Kh? d? quy
        // code here
        if (top.j >= 1) L = top.old_L;
        if (top.j > 1) { // top.j chi co the = 0 hoac 1
			s.pop();
			continue;
		}
        
        // L la trang thai htai tu x[1]...x[top.i]
        // top.old_L la trang thai truoc cua L tu x[1]...x[top.i - 1]
        if (top.j == 0 || L + 1 < k) {
        	x[top.i] = top.j;
        	top.old_L = L;
        	L = top.j ? L+1 : 0;
        	s.push(state(top.i+1, 0, 0));
		}
		top.j++;
//		cout << "sau vong lap" << endl;
//		cout << top.i << top.j << top.old_L << endl;
    }
    return 0;
}


// chua bai
//#include <bits/stdc++.h>
//using namespace std;
//
//struct state{
//    int i, j, old_L;
//    //# constructor
//    state(int _i = 0, int _j = 0, int _L = 0):
//        i(_i), j(_j), old_L(_L){}
//};
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//    int x[n+1];
//    stack<state> s;
//    //# number of consecutive suffix 1
//    int L = 0;
//    // TRY (1,0,0)
//    
//    s.push(state(1,0,0)); 
//    s.push(state(1,1,0));
//    while (!s.empty()){
//        state top = s.top();
//        s.pop();
//        x[top.i] = top.j;
//        //# if a new binary sequence is found
//        if (top.i == n){
//            for (int i = 1; i <= n; ++i)
//                cout << x[i] << " \n"[i == n];
//            continue;
//        }
//        
//        //# Kh? d? quy
//        /*****************
//        # YOUR CODE HERE #
//        *****************/
//        
//        
//        int L = top.j ? ++top.old_L : 0;
//        s.push(state(top.i+1,0,L));
//        if (L+1 < k) s.push(state(top.i+1,1,L));
//    }
//    return 0;
//}





// backtrack b7 c1
//#include <iostream> 
//using namespace std;
//
//int n, m; // do dai n,  ko co m bit 1 nao lien tiep
//int x[1000]; // xau nhi phan
//
//void print_sol() {
//	for (int i = 0; i < n; i++) cout << x[i] << (i == n-1 ? '\n' : ' ');
//}
//
//// co hai kha nang cho loi giai nen ko can ham isUCV()
//void TRY(int j, int k, int old_L) {
//	x[k] = j;
//	if (k == n-1) print_sol();
//	else {
//		int L = j ? ++old_L : 0;
//		
//		TRY(0,k+1,L);
//		if (L+1 < m) TRY(1,k+1,L);
//	}
//}
//
//int main() {
//	n = 4, m = 2;
//	TRY(0,0,0);
//	TRY(1,0,0);
//	return 1;
//}



// backtrack C2
//#include <iostream> 
//using namespace std;
//
//int n, m; // do dai n,  ko co m bit 1 nao lien tiep
//int x[1000]; // xau nhi phan
//
//void print_sol() {
//	for (int i = 0; i < n; i++) cout << x[i] << (i == n-1 ? '\n' : ' ');
//}
//
//bool isUCV(int j, int old_L) {
//	if (j==1 && old_L + 1 >= m) return false;
//	return true;
//}
//
//void TRY(int k, int old_L) {
//	for (int j = 0; j <= 1; j++) {
//		if (isUCV(j, old_L)) {
//			x[k] = j;
//			int L = j ? ++old_L : 0;
//			if (k==n-1) print_sol();
//			else TRY(k+1, L);		
//		}
//		
//	}
//}
//int main() {
//	n = 7, m = 3;
//	TRY(0,0);
//	return 1;
//}
