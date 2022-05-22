// Longest Increase String
#include <bits/stdc++.h>
using namespace std;

// do dai day con (ko lien tiep nhg theo thu tu) tang lon nhat 
int n = 7;
int A[10001] = {0, 2, 0, 6, 1, 2 , 9, 1}; // bat dau tu A[1]
int iMem[10001];

void prepare() {
    memset(iMem, -1, sizeof(iMem));
}

// O(n^2)
// do dai day con tang lon nhat cua mang A[1] -> A[i] ma ket thuc tai i
int LIS(int i) {
    if (iMem[i] != -1)
        return iMem[i];
    int res = 1;
    for (int j = 1; j < i; j++) {
        if (A[j] < A[i]) {
            res = max(res, 1 + LIS(j));
        }
    }
    iMem[i] = res;
    return res;
}

void Trace(int i) {
    for (int j = 1; j < i; j++) {
        if (A[j] < A[i] && iMem[i] == iMem[j] + 1) {
            Trace(j);
            break;
        }
    }
    cout << A[i] << ' '; // phan tu lon nhat cua day ket thuc tai i
}

int luuvitri[10001];
void Trace_caitien(int i) {
    if (luuvitri[i] != 0) {
        cout << A[i] << ' ';
        return ;
    }
    for (int j = i-1; j >= 1; j--) {
        if (A[j] < A[i] && iMem[i] == 1 + iMem[j]) {
            Trace_caitien(j);
            luuvitri[i] = j;
        }
    }
    cout << A[i] << ' ';
}


void TraceLoop(int i, int ans) {
    stack<int> S;
    vector<int> reverse; reverse.push_back(-1);
    for (int k = 1; k <= ans; k++) {
        S.push(i);
        for (int j = i-1; j >= 1; j--) {
            if (A[i] > A[j] && iMem[i] == 1 + iMem[j]) {
                i = j;
                break;
            }
        }
        reverse.push_back(S.top());
        S.pop();
    }
    // in nguoc
    for (int k = ans; k >= 1; k--) 
        cout << A[reverse[k]] << ' ';
    
}

int main() {
    prepare();
    int ans = 0; 
    int index = 1;
    for (int i = 1; i <= n; i++) {
        LIS(i);
        cout << iMem[i] << ' ';
        ans = max(ans, iMem[i]);
        if (ans == iMem[i]) index = i;
    }
    
    cout << endl << ans << endl;
    Trace(index); cout << endl;
    Trace_caitien(index); cout << endl;
    TraceLoop(index, ans);
    return 0;
}


// QHD ko de quy
// #include <bits/stdc++.h>
// using namespace std;

// // do dai day con (ko lien tiep nhg theo thu tu) tang lon nhat 
// int n = 7;
// int A[10001] = {0, 2, 0, 6, 1, 2 , 9, 1}; // bat dau tu A[1]
// int iMem[10001];

// void prepare() {
//     memset(iMem, -1, sizeof(iMem));
// }

// int lis(int i) {
// 	// code here
//     int max_length = 0;
//     for (int j = 1; j < i; j++) {
//     	if (A[j] < A[i] && iMem[j] > max_length) max_length = iMem[j];
// 	}
// 	iMem[i] = max_length + 1;
// 	return iMem[i];
// }

// void trace(int i) {
//     for (int j = 1; j < i; j++) {
//         if (A[j] < A[i] && iMem[i] == iMem[j] + 1) {
//             trace(j);
//             break;
//         }
//     }
//     cout << A[i] << ' ';


// }

// int main() {
//     prepare();
//     int ans = 0; 
//     int index = 1;
//     for (int i = 1; i <= n; i++) {
//         lis(i);
//         cout << iMem[i] << ' ';
//         ans = max(ans, iMem[i]);
//         if (ans == iMem[i]) index = i;
//     }
    
//     cout << endl << ans << endl;
//     trace(index);
//     return 0;
// }