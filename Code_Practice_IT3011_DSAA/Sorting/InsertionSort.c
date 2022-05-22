#include <stdio.h>

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int last = a[i];
        int j = i;
        while (j >= 0 && a[j-1] > last) { // chay tu cuoi mang lui ve trc
            a[j] = a[j-1];
            j--;
        } 
        a[j] = last;
    }
}

int main() {
    int a[30] = {1,2,3,8,7,9,10,12,23,18,15,16,17,14};
    insertionSort(a, 14);
    for (int i = 0; i < 14; i++) {
        printf("%d ", a[i]);
    }
}
