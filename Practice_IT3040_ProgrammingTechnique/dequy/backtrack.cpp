#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 20;
int a[MAX], n; // gia su a[i] la gia tri cot cua hang thu i de xep quan Hau

void print_solution() {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << (i == n ? '\n' : ' ');
	}
}

// check xem cot j co thoa man t/c cua de bai
// neu dung se add j vao loi giai cap k, hang thu k: a[k]
bool isUCV(int j, int k) {
	for (int i = 1; i < k; i++) {
		if (j == a[i] || fabs(j - a[i]) == fabs(k-i)) return false;
	}
	return true;
}

void attempt(int k) {
	// co n kha nang dat quan hau vao 1 hang
	for (int j = 1; j <= n; j++) {
		if (isUCV(j, k)) {
			a[k] = j; // neu dung thi cap nhat loi giai cap k
			if (k == n) print_solution(); // neu cap nhat den loi giai cap n => hoan thanh loi giai
			else attempt(k+1);
		}
	}
}

int main() {
	n = 4;
	attempt(1);
	return 0;
}
