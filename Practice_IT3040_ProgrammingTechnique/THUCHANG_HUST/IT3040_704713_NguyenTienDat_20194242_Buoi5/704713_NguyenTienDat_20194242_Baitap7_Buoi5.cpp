// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int ans = 0, sum = 0;
//     while(n--){
//         int k, t;
//         cin >> k >> t;
//         while(k--){
//             int a;
//             cin >> a;
//             if (t == 1) sum += a;
//             if (t == -1) sum -= a;
//             ans = max(ans, -sum);
//         }
//     }
//     cout << ans;
// }


// tinh chinh
#include <bits/stdc++.h>
using namespace std;
int main() {
    printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--) {
        int k, t;
        cin >> k >> t;
        if (t == 1) {
            while(k--) {
                int a;
                cin >> a;
                sum += a;
            }
        }
        else {
            while(k--) {
                int a;
                cin >> a;
                sum -= a;
            }
        }
        
        ans = max(ans, -sum);
    }
    cout << ans;
}