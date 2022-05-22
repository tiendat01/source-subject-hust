#include <bits/stdc++.h>

using namespace std;

int count_rugged_road(const vector<long long>& t) {
    int n = t.size();
    long long cur = t[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (cur != t[i]) {
            cur = t[i];
            count++;
        }
    }
    return count;
}

void change(long long left, long long right, long long mid, long long new_mid, int& rugged_roads) {
    if (left == right) {
        if (mid == left) rugged_roads += 2;
        else {
            if (new_mid == left) rugged_roads -= 2;
        }
    }
    else {
        if (mid == left || mid == right) {
            if (new_mid != left && new_mid != right) rugged_roads++;
        }
        else {
            if (new_mid == left || new_mid == right) rugged_roads--;
        }
    }
}

int main() {
    int N;  // so doan duong
    vector<long long> t; // ds nhua duong ban dau
    int Q; // so luong thong bao

    cin >> N;
    for (int i = 0; i < N; i++) {
        long long input;
        cin >> input;
        t.push_back(input);
    }

    int rugged_roads = count_rugged_road(t);
    // cout << rugged_roads << endl;

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int index;  // p: so thu tu doan duong can sua
        long long value; // c: ma nhua duong moi
        cin >> index >> value;
        index--;
        // algorithm here:
        if (value == t[index]) {
            cout << rugged_roads << endl;
            continue;
        }

        if (index == 0) {
            if (t[0] == t[1]) {
                rugged_roads++;
            }
            else {
                if (value == t[1])
                    rugged_roads--;
            }
        }
        else if (index == N-1) {
            if (t[N-1] == t[N-2]) {
                rugged_roads++;
            }
            else {
                if (value == t[N-2])
                    rugged_roads--;
            }
        }
        else {
            change(t[index-1], t[index+1], t[index], value, rugged_roads);
        }
        t[index] = value;
        cout << rugged_roads << endl;
    }

    return 0;
}