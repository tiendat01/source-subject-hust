#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b;
    vector<int> a;
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        a.push_back(input);
    }

    // index of max element in vector
    int imax = max_element(a.begin(), a.end()) - a.begin();
    int max = a[imax];
    // phan tu max chac chan phai la cua 1 doi tuong, co the la left hoac right
    // => tim max cua doi tuong con lai
    // a[i] la diem cat tin hieu => duyet tung ptu cua a[]: 1=>n-2

    int res = -1;

    // case 1:
    // neu max la cua doi tuong right => tim a[i] va max o ben left
    int max_right_case1 = max;
    int max_left_case1 = a[0];
    for (int i = 1; i < imax; i++) {
        max_left_case1 = max_left_case1 < a[i] ? a[i] : max_left_case1;
        // check
        if (max_right_case1 - a[i] >= b && max_left_case1 - a[i] >= b) {
            int tmp = max_right_case1 + max_left_case1 - (a[i] << 1);
            res = res < tmp ? tmp : res;
        }
    }


    // case 2:
    // neu max la cua doi tuong left => tim a[i] va max o ben right
    int max_left_case2 = max;
    int max_right_case2 = a[n-1];
    for (int i = n-2; i > imax; i--) {
        max_right_case2 = max_right_case2 < a[i] ? a[i] : max_right_case2;
        // check
        if (max_right_case2 - a[i] >= b && max_left_case2 - a[i] >= b) {
            int tmp = max_right_case2 + max_left_case2 - (a[i] << 1);
            res = res < tmp ? tmp : res;
        }
    }

    cout << res;

    return 0;
}