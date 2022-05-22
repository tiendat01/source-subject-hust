#include <bits/stdc++.h>

using namespace std;

int random(int L, int H){
	return (rand()<<16|rand()) % (H-L+1) + L;
}

int main() {
    srand(time(NULL));
    ofstream os ("testcase.txt");
    int n = random(1,20);
    int m = random(1,10);
    os << m << ' ' << n << endl;
    for (int i = 0; i < m; i++) {
        int sl = random(1,n);
        os << sl << ' ';
        set<int> myset;
        while (myset.size() != sl) {
            myset.insert(random(1, n));
        }
        for (set<int>::iterator it = myset.begin(); it!=myset.end(); it++) {
            os << *it << ' ';
            cout << 'p' ;
        } os << endl;
    }
    int k = random(1, n*3);
    os << k << endl;
    for (int i = 0; i < k; i++) {
        os << random(1,n) << ' ' << random(1, n) << endl;
    } 
    os.close();
    return 0;
}