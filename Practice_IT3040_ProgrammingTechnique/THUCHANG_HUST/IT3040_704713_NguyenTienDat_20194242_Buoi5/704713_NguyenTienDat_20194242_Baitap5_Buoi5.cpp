// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     bool found = false;
//     while(n--){
//         int a;
//         cin >> a;
//         if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
//             found = true;
//     }
//     if (found) cout << "Yes";
//     else cout << "No";
// }

// tinh chinh, do phep toan % la phep toan cham nhat trong cac phep toan co ban
#include <bits/stdc++.h>
using namespace std;

bool isDivisible(const int &x) {
    return (x & 3) == 0; // vi 3 = 11 (bit)
}

int main(){
    printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int n;
    cin >> n;
    bool found = false;
    while(n--){
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
            cout << "Yes";
            return 0;
        }       
    }
    cout << "No";
}