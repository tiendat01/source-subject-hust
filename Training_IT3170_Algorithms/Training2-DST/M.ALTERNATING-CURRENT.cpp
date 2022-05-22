#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<char> st;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        }
        else 
            st.pop();
    }
    if (st.empty()) cout << "Yes";
    else cout << "No";
    return 0;
}