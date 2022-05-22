#include <bits/stdc++.h>

using namespace std;

const string ROOT = "";
const string CD = "cd";
const string PWD = "pwd";


deque<string> absolute_dir;

void cd() {
    cin.ignore(); // discard charater ' '
    string dir = "";
    char c = getchar();
    // absolute path
    if (c == '/') {
        absolute_dir.erase(absolute_dir.begin(), absolute_dir.end());
        absolute_dir.push_back(ROOT);
    }
    // relative path
    else if (c == '.' && getchar() == '.') {
        absolute_dir.pop_back();
    }
    else {
        dir += c;
    }
    while ((c = getchar()) != '\n')
    {
        if (c == '/') {
            if (!dir.empty()) {
                absolute_dir.push_back(dir);
                dir.erase();
            }
        }
        else if (c == '.' && getchar() == '.') {
            absolute_dir.pop_back();
        }
        else {
            dir += c;
        }
    }
    if (!dir.empty())
        absolute_dir.push_back(dir);
}

void pwd() {
    for (int i = 0; i < absolute_dir.size(); i++) {
        cout << absolute_dir.at(i) << '/';
    }
    cout << endl;
}

int main() {
    // home
    absolute_dir.push_back(ROOT);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // cin.ignore();
        if (!s.compare(CD)) {
            cd();
        }
        else if (!s.compare(PWD)) {
            pwd();
        }
        else {
            cout << "System is upgrading! COME BACK SOON";
        }
    }
    return 0;
}


// c2 string.split() '/'