#include <stdio.h>

int binarySearch(int a[], int n, int x) {
    // dieu kien la mang a da duoc sap xep theo thu tu khong giam
    int lower = 0, upper = n-1;
    while (lower <= upper) {
        int mid = (lower + upper) / 2;
        if (a[mid] > x) upper = mid-1;
        else if (a[mid] < x) lower = mid+1;
        else return mid;
    }
    return -1;
}

int main() {
    int arr[100] = {0,1,2,3,4,5,6,7,8,9};
    printf("%d\n", binarySearch(arr, 10, 5));
}