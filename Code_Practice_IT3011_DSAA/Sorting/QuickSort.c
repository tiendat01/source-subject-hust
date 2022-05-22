#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int leftPartition(int a[], int l, int r) {
    int i = l, j = r+1, pivot = a[l];
    while (i < j) {
        i++; // sau khi swap
        while (i <= r && a[i] < pivot) i++; // chi so i tien tu dau mang den cuoi mang
        j--; // sau khi swap
        while (j >= l && a[j] > pivot) j--; // chi so j lui tu cuoi mang den dau mang
        swap(a+i, a+j);
    }
    swap(a+i, a+j); // swap bi thuwaf 1 laanf nen phai swap lai
    swap(a+j, a+l);
    return j; // chi so cua a[pivot]
}

int leftPartition_cach2(int a[], int l, int r) {
    int pivot = a[l];
    int j = r+1;
    for (int i = r; i > l; i--) {
        if (a[i] >= pivot) {
            j--;
            swap(&a[i], &a[j]);
        }
    }
    j--;
    swap(&a[l], &a[j]);
    return j;
}

int rightPartition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l-1, j = r;
    while (i < j) {
        i++;
        while (i <= r && a[i] < pivot) i++;
        j--;
        while (j >= l && a[j] > pivot) j--;
        swap(&a[i], &a[j]);
    }
    swap(&a[i], &a[j]);
    swap(&a[r], &a[i]);
    return i;
}

int rightPartition_cach2(int a[], int l, int r) {
    int pivot = a[r];
    int j = l-1;
    for (int i = l; i < r; i++) {
        if (a[i] <= pivot) {  
            j++;
            swap(&a[i], &a[j]);
        }
    }
    j++;
    swap(&a[r], &a[j]);
    return j;
}

void quickSort(int a[], int first, int last) {
    if (first < last) {
        int pivot = leftPartition(a, first, last);
        quickSort(a, first, pivot-1);
        quickSort(a, pivot+1, last);
        //printf("%d\n", pivot);
    }
}

void quickSort_midpivot(int arr[], int left, int right) {

      int i = left, j = right;

      int pivot = arr[(left + right) / 2];

      /* partition */

      while (i < j) {

            while (arr[i] < pivot)

                  i++;

            while (arr[j] > pivot)

                  j--;

            if (i <= j) {
                  swap(&arr[i], &arr[j]);
                  i++;
                  j--;
            }

      };

      /* recursion */

      if (left < j)

            quickSort(arr, left, j);

      if (i < right)

            quickSort(arr, i, right);

}

int main() {
    int a[30] = {7,2,8,3,5,9,6};
    // quickSort_midpivot(a, 0, 6);
    // quickSort(a, 0, 6);
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }   
}