#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int demhoanvi(int n) {
    if (n == 1) return 1;
    return demhoanvi(n-1) * n; 
}

// backtrack liet ke
int a[1000];
int res[1000]; 
int n;
bool state[1000];
int dem = 0;

void print_sol(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << (i == n-1 ? '\n' : ' ');
}

bool isUCV(int j) {
    if (state[j]) return false;
    return true;
}

void attempt(int k) {
    for (int j = 0; j < n; j++) {
        if (isUCV(j)) {
            res[k] = a[j];
            state[j] = true;
            if (k == n-1) {
                print_sol(res, n);
                dem++;
            } 
            else attempt(k+1);
            state[j] = false;
        }
    }
}

int main() {
    n = 4;
    cout << demhoanvi(n) << endl;

    srand(time(NULL)); 
    for (int i = 0; i < n; i++) {
        a[i] = rand() % (50-3+1) + 3; // random tu [3,50]
        a[i] = i;
        state[i] = false;
    }
    attempt(0);
    cout << dem;
	return 0;
}
