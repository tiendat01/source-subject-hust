#include <iostream>
#include <string>

using namespace std;

void abbreviation(string& s) {
    int n = s.size();
    s.erase(s.begin()+1, s.end()-1);
    s.insert(1, to_string(n-2));
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s; // 1 word
        unsigned long long s_size = s.size();
        if (s_size > 10)
            abbreviation(s);
        cout << s << endl;
    }
    return 0;
}