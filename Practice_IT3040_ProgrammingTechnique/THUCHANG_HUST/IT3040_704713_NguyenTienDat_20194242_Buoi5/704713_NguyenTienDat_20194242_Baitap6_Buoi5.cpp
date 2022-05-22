// #include <bits/stdc++.h>
// using namespace std;

// char cal(double a){
//     if (a < 4) return 'F';
//     if (4 <= a && a < 5.5) return 'D';
//     if (5.5 <= a && a < 7) return 'C';
//     if (7 <= a && a < 8.5) return 'B';
//     if (8.5 <= a) return 'A';
// }

// int main(){
//     int n;
//     cin >> n;
//     int A = 0, B = 0, C = 0, D = 0, F = 0;
//     while(n--){
//         int a;
//         cin >> a;
//         if (cal(a) == 'A') ++A;
//         if (cal(a) == 'B') ++B;
//         if (cal(a) == 'C') ++C;
//         if (cal(a) == 'D') ++D;
//         if (cal(a) == 'F') ++F;
//     }
//     cout << A << " " << B << " " << C << " " << D << " " << F;
// }


// tinh chinh: goi ham va chuyen if thanh switch case
#include <bits/stdc++.h>
using namespace std;

char cal(double a){
    if (a < 4) return 'F';
    else if (4 <= a && a < 5.5) return 'D';
    else if (5.5 <= a && a < 7) return 'C';
    else if (7 <= a && a < 8.5) return 'B';
    else return 'A';
}

int main() {
    printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while(n--){
        int a;
        cin >> a;
        char calA = cal(a);
        if (calA == 'A') ++A;
        if (calA == 'B') ++B;
        if (calA == 'C') ++C;
        if (calA == 'D') ++D;
        if (calA == 'F') ++F;
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}