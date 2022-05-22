#include <stdio.h>

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int a[], int n) {
    int min;
    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        swap(&a[i], &a[min]);
    }
}

int main() {
    int a[30] = {1,2,3,8,7,9,10,12,23,18,15,16,17,14};
    selectionSort(a, 14);
    for (int i = 0; i < 14; i++) {
        printf("%d ", a[i]);
    }
}