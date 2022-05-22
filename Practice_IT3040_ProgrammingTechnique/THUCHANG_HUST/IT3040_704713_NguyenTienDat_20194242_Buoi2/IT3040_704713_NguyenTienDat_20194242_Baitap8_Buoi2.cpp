#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdio.h>

using namespace std;

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    sort(a.begin(), a.end(), [=] (vector<int> left, vector<int>right) {
        int sum_left = 0, sum_right = 0;
        for (unsigned int i = 0; i < left.size(); i++) sum_left += left[i];
        for (unsigned int i = 0; i < right.size(); i++) sum_right += right[i];
        return sum_left > sum_right;
    }
    );

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
    getchar();
}
