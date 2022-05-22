#include <iostream>

using namespace std;

int n, k1, k2;
// so ngay lam viec lien tiep khi chua cap nhat loi giai thu k
int res[1000]; // loi giai


void print_sol() {
	for (int i = 1; i <= n; i++) {
		cout << res[i];
	}
	cout << endl;
}

bool isUCV(int j, int k, int old_state) {
	if (j == 0 && res[k-1] == 0) return false;
	if (j == 0 && old_state < k1 && old_state != 0) return false;
	if (j == 1 && old_state + 1 > k2) return false; 
	if (j == 1 && old_state + 1 < k1 && k==n) return false;	
	return true;
}

// old_state = so ngay lam viec lien tiep khi chua cap nhat loi giai thu k
void TRY(int k, int old_state) {
	for (int j = 0; j <= 1; j++) {
		if (isUCV(j, k, old_state)) {
			res[k] = j;
			int curr_state = j ? ++old_state : 0;
			
			if (k==n) {
				print_sol();
			}
			else TRY(k+1, curr_state);
		}
	}
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
	res[0] = -1;
	cin >> n;
	cin >> k1 >> k2;
	TRY(1,0);
}
