#include <bits/stdc++.h>
using namespace std;

int random(int L, int H){
	return (rand()<<16|rand()) % (H-L+1) + L;
}

int main(int argc, char** argv){
	if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
	freopen("LIS.inp", "w", stdout);
	int n = random(1, 10), amax = 1e9;
	cout << n << endl;
	for (int i = 1; i <= n; ++i) cout << random(-amax, amax) << " ";
}
