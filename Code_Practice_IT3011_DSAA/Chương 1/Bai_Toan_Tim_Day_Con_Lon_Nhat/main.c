#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Thuật toán 1: độ phức tạp O(n^3)

// int main()
// {
//     int a[1000] = {-2, 11, -4, 13, -5, 2};
//     int n = 6;
//     int maxSum;
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             int sum = 0;
//             for (int k = i; k <= j; k++) {
//                 sum += a[k];
//             }
//             if (maxSum < sum) maxSum = sum;
//         }
//     }
//     printf("%d", maxSum);
//     return 0;
// }


//Thuat toan nhanh hon:

// int main() {
//     int a[1000] = {-2, 11, -4, 13, -5, 2};
//     int n = 6;
//     int maxSum;
//     for (int i = 0; i < n; i++) {
//         int sum = 0;
//         for (int j = i; j < n; j++) {
//             sum += a[j];
//             if (sum > maxSum) maxSum = sum;
//         }
//     }
//     printf("%d", maxSum);
//     return 0;
// }


// Thuat toan de quy: O(nlog(n))

// ham max nay dac biet???
// neu a=11, b=-4, c=7 => max=7
int Max(int a, int b, int c) {
        int max = a;
        if (a < b) max = b;
        if (b < c) max = c; // neu a>c thi sao???
        return max;
    }

// j là điểm giữa cua mảng ban đầu
int MaxLeft(int a[1000], int i, int j) {
        int maxSum = INT_MIN, sum = 0;
        for (int k = j; k >= i; k--) {
            sum += a[k];
            maxSum = (maxSum < sum ? sum : maxSum);
        }
        return maxSum;
    }

// i là điểm giữa của mảng ban đầu
int MaxRight(int a[1000], int i, int j) {
        int maxSum = INT_MIN, sum = 0;
        for (int k = i; k <= j; k++) {
            sum += a[k];
            maxSum = (maxSum < sum ? sum : maxSum);
        }
        return maxSum;
    }

int MaxSub(int a[1000], int i, int j) {
        if (i == j) 
            return a[i];
        else {
            int m = (i + j) / 2;
            int wL = MaxSub(a, i, m);
            int wR = MaxSub(a, m+1, j);
            int wM = MaxLeft(a, i, m) + MaxRight(a, m+1, j);
            printf("i=%d j=%d wL=%d, wR=%d, wM=%d max=%d\n", i, j, wL, wR, wM, Max(wL,wR,wM));
            return Max(wL, wR, wM);
        }
    }

int main() {
    int a[1000] = {-2, 11, -4, 13, -5, 2};
    int res = MaxSub(a, 0, 5);
    printf("%d", res);
}


// // Thuat toan quy hoach dong:
// int MaxSub(int a[1000], int n) {
//     int smax = a[0]; // trong luong cua day lon nhat
//     int max_end_here = a[0]; // tam thoi
//     int istart = 0; // vi tri dau tien cua day lon nhat
//     int iend = 0; // vi tri ket thuc cua day lon nhat
//     for (int i = 1; i < n; i++) {
//         int u = max_end_here + a[i];
//         int v = a[i];

//         if (u > v) max_end_here = u;
//         else {
//             max_end_here = v;
//             istart = i;
//         }

//         if (max_end_here > smax) {
//             smax = max_end_here;
//             iend = i;
//         }

//     }
//     for (int i = istart; i <= iend; i++) printf("%d ", a[i]);

//     return smax;
// }
// int main() {
//     int a[1000] = {-2, 11, -4, 13, -5, 2};
//     int n = 6;
//     //printf("%d", MaxSub(a, 6));
//     MaxSub(a,6);
// }



// ===>>> Thuat toan quy hoach dong hieu qua hon 3 thuat
// toan con lai !!! tinh toan it hon tuy nhien quy hoach dong
// ton bo nho hon vi phai luu ket qua vao 1 mang roi tong hop ket qua.

