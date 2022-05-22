#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> pos;
    vector<int> neg;
    vector<int> zero;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (input > 0) pos.push_back(input);
        else if (input == 0) zero.push_back(input);
        else neg.push_back(input);
    }
    int count_pos = pos.size();
    int count_neg = neg.size();
    
    if (count_pos == 0) {
        pos.push_back(neg.back());
        neg.pop_back();
        pos.push_back(neg.back());
        neg.pop_back();
        // so luong so am  la chan
        if (!(count_neg % 2)) {
            zero.push_back(neg.back());
            neg.pop_back();
        }
    }
    else {
        // so luong so am la chan
        if (!(count_neg % 2)) {
            zero.push_back(neg.back());
            neg.pop_back();
        }
    }

    cout << neg.size();
    for (int val : neg) cout << ' ' << val;
    cout << endl;

    cout << pos.size();
    for (int val : pos) cout << ' ' << val;
    cout << endl;

    cout << zero.size();
    for (int val : zero) cout << ' ' << val;

    return 0;
}