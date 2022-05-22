#include <stdio.h>

#define MAX 1000

void merge(int a[], int first, int mid, int last) { // cac chi so cua mang
    int tempA[MAX];
    int first1 = first, last1 = mid; // mang 1
    int first2 = mid+1, last2 = last; // mang 2
    int index = first1; // chi so cua mang trung gian tempA
    while (first1 <= last1 && first2 <= last2) {
        if (a[first1] < a[first2]) {
            tempA[index] = a[first1];
            first1++;
        }
        else {
            tempA[index]  = a[first2];
            first2++;
        }
        index++;
    }
    // neu mang 1 conf phan tu:
    while (first1 <= last1) {
        tempA[index] = a[first1];
        first1++;
        index++;
    }
    // neu mang 2 conf phan tu:
    while (first2 <= last2) {
        tempA[index] = a[first2];
        first2++;
        index++;
    } 

    // luu mang trung gian sang mang A
    for (index = first; index <= last; index++) a[index] = tempA[index];

}

void mergeSort(int a[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(a, first, mid);
        mergeSort(a, mid+1, last);
        merge(a, first, mid, last);
    }    
}

int main() {
    int a[30] = {1,2,3,8,7,9,10,12,23,18,15,16,17,14};
    mergeSort(a, 0, 13);
    for (int i = 0; i < 14; i++) {
        printf("%d ", a[i]);
    }
}