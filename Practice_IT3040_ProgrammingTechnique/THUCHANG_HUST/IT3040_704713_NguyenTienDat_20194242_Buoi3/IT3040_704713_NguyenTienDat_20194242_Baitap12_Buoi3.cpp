#include <iostream> 
#include <vector>
using namespace std;

int n, m;
vector<int> a[1000];
int k;
int mark[1000];
int x[1000]; // luu dinh da di qua

int result = 0;

void input() {
	cin >> n >> k;
	cin >> m;
	for (int i = 1; i <= n; i++)  {
		mark[i] = 0;
		a[i].push_back(-1);
	}
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		a[tmp1].push_back(tmp2);
		a[tmp2].push_back(tmp1);
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j < a[i].size(); j++) cout << a[i][j] << " ";
//		cout << endl;
//	}	
}

bool isUCV(int i, int j) {
	if (i==1) return true;
	if (mark[j] == 1) return false;
	// chech co duong di tu x[i-1] den x[i] ko?
	int check_path = 0;
	for (int l = 1; l < a[x[i-1]].size(); l++) {
		if (j == a[x[i-1]][l]) check_path = 1;
	}
	if (check_path == 0) return false;
	return true;
}

void print_sol() {
//	for (int i = 1; i <= k; i++) cout << x[i] << " ";
//	cout << endl;
	result++;
}

void TRY(int i) {
	for (int j = 1; j <= n; j++) {
		if (isUCV(i,j)) {
			x[i] = j;
			mark[j] = 1;
			
			if (i - 1 == k) { // i la so dinh , k la so canh
				print_sol();
			}
			else TRY(i+1);
			
			mark[j] = 0;
		}
	}
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
	input();
	TRY(1);
	cout << result/2;
}

