#include <bits/stdc++.h>
using namespace std;

// output random mot so nguyen trong khoang L -> H
int random(int L, int H){
	return (rand()<<16|rand()) % (H-L+1) + L;
}

int main(int argc, char** argv){
	if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
	freopen("LIS.inp", "w", stdout);

    int n = random(1, 16), m = random(1, n*n), amax = 1e1;
    cout << n << " " << m << endl;
    for (int i = 0; i < m; i++) {
        int a = random(1,n), b = random(1,n);
        if (a != b) cout << a << " " << b << " " << random(0, amax) << endl;
    }
}