//#include <bits/stdc++.h>
//using namespace std;
//
//struct state{
//    int i, j;
//    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
//};
//
//int main() {
//    int n, M;
//    cin >> n >> M;
//    int m[n+1];
//    for (int i = 1; i <= n; ++i) cin >> m[i];
//    int x[n+1];
//    stack<state> s;
//    //# sum of selected weights
//    int sum = 0;
//    s.push(state(1, -1));
//    while (!s.empty()){
//        state &top = s.top();
//        if (top.i > n){
//            if (sum == M){
//                for (int i = 1; i <= n; ++i){
//                    if (x[i] == -1) cout << '-' << m[i];
//                    if (x[i] == 1) cout << '+' << m[i];
//                }
//                cout << "=" << M;
//                exit(0);
//            }
//            s.pop();
//            continue;
//        }
//        
//        //# Kh? d? quy
//        /*****************
//        # YOUR CODE HERE #
//        *****************/
//    }
//    cout << -1;
//
//    return 0;
//}

// backtrack bai 8
#include <iostream>
using namespace std;

int M; // dat qua can ben phai
int n;
int m[1000];

int mark[1000]; // dau + hoac -
int curr = 0; // khoi luong dia can hien tai ben trai
int loi_giai_thu_may = 0; // loi giai thu n, neu bang 0 => ko co cach can nao

void print_sol() {
	if (loi_giai_thu_may == 1) cout << "Cac cach can:" << endl;
	cout << "Loi giai thu " << loi_giai_thu_may << ": ";
	for (int i = 1; i <= n; i++) {
		if (mark[i] == -1) cout << "-" << m[i];
		if (mark[i] == 1) cout << "+" << m[i];
	}
	cout << "=" << M << endl;
}

bool isUCV(int k) {
	if (k > n) return false;
	return true;
}

void TRY(int k) {
	if (isUCV(k)) {
		for (int j = -1; j <= 1; j++) {
			mark[k] = j;
			curr += m[k] * mark[k];
			
			if (curr == M) {
				loi_giai_thu_may++;
				print_sol();	
			}
			else TRY(k+1);
			
			curr -= m[k] * mark[k];
			mark[k] = 0;
		}
	}
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
	cin >> n >> M;
    for (int i = 1; i <= n; ++i) cin >> m[i];
    TRY(1);
    if (loi_giai_thu_may == 0) cout << "Khong co loi giai nao";
}
