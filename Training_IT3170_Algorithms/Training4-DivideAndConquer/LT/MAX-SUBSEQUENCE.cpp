#include<bits/stdc++.h>

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
    int n = 20;
    int a[1000] = {-9, 17, -16, -50, 19, -26, 28, 8, 12, 14, -45, -5, 31, -23, 11, 41, 45, -8, -23, -14};
    for (int i = 0; i < n; i++) {
        a[i] = a[i]*a[i]*a[i];
    }
    int res = MaxSub(a, 0, n);
    printf("%d", res);
}