#include <bits/stdc++.h>

using namespace std;

bool is_respective(const char& open, const char& close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}

// O(n)
bool parentheses_check(const string& s) {
    int n = s.length();
    if (n % 2) return false;
    stack<char> st; // luu cac dau mo ngoac
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else {
            if (st.empty()) return false;  // thua dau dong ngoac
            if (!is_respective(st.top(), s[i])) return false; // khong tuong ung
            st.pop();
        }
    }
    if (!st.empty()) return false; // thua dau mo ngoac
    return true;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        string input;
        cin >> input;
        cout << parentheses_check(input) << endl;
    }
    return 0;
}