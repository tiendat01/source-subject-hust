// Longest Common String
#include<bits/stdc++.h>
using namespace std;

string X = "abcb";
string Y = "dbcab";
int iMem[1001][1001]; // luu do dai cua day con dai nhat X[0->i] va Y[0->j]

void prepare() {
    memset(iMem, -1, sizeof(iMem));
}

// O(m*n)
int LCS(int i, int j) {
    if (i == -1 || j == -1) return 0;
    if (iMem[i][j] != -1) return iMem[i][j];

    int res = 0;
    // neu X[i] va Y[j] khac nhau
    res = max(res, LCS(i-1, j)); 
    res = max(res, LCS(i, j-1));
    // neu X[i] va Y[j] giong nhau, chung
    if (X[i] == Y[j]) 
        res = max(res, 1 + LCS(i-1, j-1));
    iMem[i][j] = res;
    return res;
}

// O(n+m)
// co the dung return thay cho else if
void Trace(int i , int j) {
    if (i == -1 || j == -1) return ;
    if (iMem[i][j] == iMem[i-1][j]) 
        Trace(i-1, j);
    else if (iMem[i][j] == iMem[i][j-1]) 
        Trace(i, j-1);
    else if (X[i] == Y[j] && iMem[i][j] == 1 + iMem[i-1][j-1]) {
        cout << X[i] << ' ';
        Trace(i-1, j-1);
    }
    else    
        return;
}

void TraceLoop(int i, int j, int ans) {
    stack<char> S;
    string reverse;
    for (int k = 1; k <= ans; k++) {
        if (X[i] == Y[i] && iMem[i][j] == 1 + iMem[i-1][j-1]) {
            S.push(X[i]); i--, j--;
        }
        else if (iMem[i][j] == iMem[i-1][j]) {
            i--;
        }
        else if (iMem[i][j] == iMem[i][j-1]) {
            j--;
        }
        else ;
    }
    while (!S.empty()) {
        reverse.push_back(S.top());
        S.pop();
    }
    // in nguoc
    for (int k = reverse.size()-1; k >= 0; k--) 
        cout << k << ' ';
}

int main() {
    prepare();
    int ans = LCS(X.length()-1, Y.size()-1); cout << ans << endl;
    Trace(X.size()-1, Y.size()-1); cout << endl;
    TraceLoop(X.size()-1, Y.size()-1, ans);
    return 0;
}