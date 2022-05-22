#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string list[12] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", "", " ", ""};
const int n = 12;

int main() {
    long long T;
    cin >> T;
    cin.ignore();
    vector<int> res;

    for (int t = 0; t < T; t++) {
        string sLine;
        getline(cin, sLine);
        int sum_click = 0;
        for (int i = 0; sLine[i] != '\0'; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < list[j].size(); k++) {
                    if (sLine[i] == list[j][k]) {
                        count = k+1;
                    }
                }
            }
            sum_click += count;
        }
        // cout << "Case #" << (t+1) << ": " << sum_click;
        res.push_back(sum_click);

    }

    for (int t = 0; t < T; t++) {
        cout << "Case #" << (t+1) << ": " << res[t];
    }
    return 0;
}