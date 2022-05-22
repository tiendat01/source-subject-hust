// ver 1: co ban O(n^3)
// #include <iostream>
// using namespace std;
// int res = 0;

// bool check(string s) {
//     int n = s.size();
//     if (n % 2 != 0 || n == 0) return false;
//     int count = 0;
//     for (unsigned int i = 0; i < n; i++) {
//         if (s[i] == '0') count++;
//     }
//     if (count == n/2) return true;
//     else return false;
// }

// int solve(string s) {
//     int n = s.size();
//     for (unsigned int i = 0; i < n; i++) {
//         for (unsigned int j = i; j < n; j++) {
//             string tmp = s.substr(i,(j-i+1));
//             //cout << tmp << endl;
//             if (check(tmp)) res++;
//         }
//     }
//     return res;
// }

// int main() {
//     string s;
//     cin >> s;
//     // cout << check(s);
//     cout << solve(s);

// }

// ver2 : O(n^2)
// #include <iostream>
// #include <vector>
// using namespace std;

// int res = 0;
// int count0[1000], count1[1000];
// string s;

// void input() {
//     cin >> s;
//     if (s[0] == '0') {
//         count0[0] = 1; count1[0] = 0;
//     } else {
//         count0[0] = 0; count1[0] = 1;
//     }
//     int n = s.size(); 
//     for (unsigned int i = 1; i < n; i++) {
//         if (s[i] == '0') {
//             count0[i] = count0[i-1] + 1;
//             count1[i] = count1[i-1];
//         } else {
//             count1[i] = count1[i-1] + 1;
//             count0[i] = count0[i-1];
//         }
//     }
// }

// void solve(string s) {
//     int n = s.size();
//     for (int i = 0; i < n; i++) {
//         for (int j = i+1; j < n; j++) {
//             if (i == 0 && count1[j] == count0[j]) res++;
//             else if (count0[j] - count0[i-1] == count1[j] - count1[i-1]) res++;
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     input();
//     solve(s);
//     cout << res;
//     return 0;
// }


// ver 3: quy hoach dong O(n)
// y tuong: duyet string i: 0...n-1
// dua vao su thay doi cua do chenh lech sum_difference cua bit 0 va 1 tai thoi diem i
// moi lan them 1 bit, cap nhat trang thai sum_difference, 
// map<?,?> F[sum_difference] la so lan xuat hien trang thai sum_difference, chinh la so vi tri bat dau hop le (thoa man tc de bai) cua xau con
// moi lan trang thai sum_difference xh thi update F[sum_difference]

// vd: 1001011, ban dau F[0] khoi tao la 1.
// i = 0: sum_di = 1, count = 0 => F[1] = 1.
// i = 1: sum_di = 0, count = 0 + F[0] = 1 (vi co 1 vi tri bat dau hop le voi sum_di 0: i = 0) => F[0] = 2. 
// i = 2: sum_di = -1, count = 1 + F[-1] = 0 (vi co 0 vi tri bat dau hop le voi sum_di -1) => F[-1] = 1 
// i = 3: sum_di = 0, count = 1 + F[0] = 3 (vi co 2 vi tri bat dau hop le voi sum_di 0: i = 0, i = 2 den i = 3) => F[0] = 3 
// i = 4: sum_di = -1, count = 3 + F[-1] = 4 (vi co 1 vi tri bat dau hop le voi sum_di -1: i = 3 den i = 4) => F[-1] = 2 
// i = 5: sum_di = 0, count = 4 + F[0] = 7 (vi co 3 vi tri bat dau hop le voi sum_di 0: i = 0, i = 2, i = 4 den i = 5) => F[0] = 4
// i = 6: sum_di = 1, count = 7 + F[1] = 8 (vi co 1 vi tri bat dau hop le voi sum_di 1: i = 1 den i = 6) => F[1] = 2

#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

// sum_difference la do chech lech giua 0 va 1 tai thoi diem i
// F[sum_difference] la so lan xuat hien do chech lech sum_difference do
map<int, unsigned int> F;
int sum_differenece = 0;

int solve(string s) {
    unsigned int count = 0;
    int n = s.size();
    for (int i = -n-1; i < n+1; i++) {
        F.insert({i,0});
    }
    F[0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            sum_differenece--;
        }
        else sum_differenece++;

        count += F[sum_differenece];
        ++F[sum_differenece];
    }
    return count;
}

int main() {
	cout << "Ho ten: Nguyen Tien Dat\n" << "MSSV: 20194242\n";
    string s; cin >> s;
    cout << solve(s);
}
