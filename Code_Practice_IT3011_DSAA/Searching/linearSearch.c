#include <stdio.h> 

int linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main() {
    int arr[100] = {0,1,2,3,4,5,6,7,8,9};
    printf("%d\n", linearSearch(arr, 10, 5));
}