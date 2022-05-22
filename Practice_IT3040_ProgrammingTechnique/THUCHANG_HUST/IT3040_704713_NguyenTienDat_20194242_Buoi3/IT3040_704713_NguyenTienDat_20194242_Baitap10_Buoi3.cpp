#include <iostream> 
using namespace std;

int n, H;
int res[1000];


void print_sol() {
	for (int i = 1; i <= n; i++) {
		cout << res[i];
	}
	cout << endl;
}

bool isUCV(int j, int k, int old_state) {
	if (j == 1 && old_state + 1 > H) return false;
	return true;
}

void TRY(int k, int old_state) {
	for (int j = 0; j <= 1; j++) {
		if (isUCV(j, k, old_state)) {
			res[k] = j;
			if (j == 1) ++old_state;
			if (k==n) {
				if (old_state == H) print_sol();
			}
			else TRY(k+1, old_state);
		}
	}
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
	int t;
	cin >> t;
	while (t>0) {
		cin >> n >> H;
		TRY(1,0);
		t--;
	}
	
}

