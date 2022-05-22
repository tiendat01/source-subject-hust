#include <stdio.h>

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int a[], int n) {
    for (int i = n-1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) 
        {
            if (a[j-1] > a[j]) swap(&a[j-1], &a[j]);
        }
    }
}

int main() {
    int a[30] = {1,2,3,8,7,9,10,12,23,18,15,16,17,14};
    bubbleSort(a, 14);
    for (int i = 0; i < 14; i++) {
        printf("%d ", a[i]);
    }
}