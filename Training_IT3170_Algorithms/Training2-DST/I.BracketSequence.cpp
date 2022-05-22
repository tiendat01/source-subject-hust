#include <bits/stdc++.h>

using namespace std;

bool is_respective(const char& open, const char& close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

int main() {
    string sq;
    cin >> sq;
    int n = sq.length();
    int max = 0, i_start_optimal = 0, i_end_optimal = 0;
    int count = 0, i_start = 0, i_end = 0;
    stack<int> st_index;
    vector<bool> check (n, false);

    // lay cac day con dung
    // la day lien tuc ma co check[i] == true
    for (int i = 0; i < n; i++) {
        if (sq[i] == '[' || sq[i] == '(') {
            st_index.push(i);
        } 

        else {
            if (!st_index.empty()) {
                if (is_respective(sq[st_index.top()], sq[i])) {
                    check[st_index.top()] = true;
                    check[i] = true;
                    st_index.pop();
                }
                else {
                    while (!st_index.empty()) 
                        st_index.pop();
                }
            }  
        }
    }


    // for (int i = 0; i < n; i++) cout << check[i] << ' ';
    // cout << endl;

    // tu cac day true, tim day true co count_']' lon nhat, luu i_start va i_end
    for (int i = 0; i < n; ) {
        if (check[i] == true) {
            int j = i+1;
            for (; j < n && check[j] == true; j++) {
                if (sq[j] == ']') count++;
            }
            if (max < count) {
                max = count;
                i_start = i;
                i_end = j-1;
            }
            count = 0;
            i = j;
        }
        else 
            i++;
    }


    cout << max << endl;
    if (max <= 0) {
        cout << endl;
        return 0;
    } 
    for (int i = i_start; i <= i_end; i++) cout << sq[i];

    return 0;
}