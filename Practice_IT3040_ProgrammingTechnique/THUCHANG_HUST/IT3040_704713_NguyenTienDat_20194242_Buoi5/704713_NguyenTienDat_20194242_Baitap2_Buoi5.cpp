#include <iostream>
using namespace std;

int n, M, m[100], v[100];
int x[100], best, sumV, sumM, All[100];

void init(){
    for (int i = n; i >= 1; --i){
        All[i] = All[i+1] + v[i];
        cout << All[i] <<  ' ';
    }
    cout << endl;
}

void print() {
    cout << best;
}

void process(int i){
    if (sumV + All[i] <= best || sumM > M) return ; // void ko tra ve gia tri nao
    if (i > n){
        best = sumV; // thieu dau ; (da sua)
        return ; // void ko tra ve gia tri nao
    }
    process(i+1);
    sumM += m[i];
    sumV += v[i];
    process(i+1); // check lai gia tri cho sumM va sumV, neu thoa man cap nhap sumV vao best
    sumM -= m[i];
    sumV -= v[i];
}

int main() {
    printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> m[i] >> v[i];
    init();
    process(1);
    print();
    return 0;
}

// #include <iostream> 
// using namespace std;

// int n, M, m[100], v[100];
// int sumM, sumV, best;
// bool mark[100];

// bool isUCV(int j) {
//     if (sumM + m[j] > M || mark[j]) return false;
//     return true;
// }

// void process(int i) {
//     for (int j = 1; j <= n; j++) {
//         if (isUCV(j)) {
//             mark[j] = true;
//             sumM += m[j];
//             sumV += v[j];
//             if (sumV > best) best = sumV;
//             if (i >= n) return;
//             else process(i+1);
//             mark[j] = false;
//             sumM -= m[j];
//             sumV -= v[j];
//         }
//     }
// }

// int main() {
//     cin >> n >> M;
//     for (int i = 1; i <= n; ++i)
//         cin >> m[i] >> v[i];
//     process(1);
//     cout << best;
// }