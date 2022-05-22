#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int a[], int pos, int n) {
    // cai cay nhi phan bang array, ta co cong thuc:
    int l = 2*pos+1; // chi so cua cay con trai cua nut pos
    int r = 2*pos+2; // chi so cua cay con phai cua nut pos
    int largest = pos;

    if (l < n && a[l] > a[pos]) largest = l; // neu con trai lon hon 
    if (r < n && a[r] > a[pos]) largest = r; // 

    if (largest != pos) {
        swap(&a[pos], &a[largest]);
        // recursion
        maxHeapify(a, largest, n);
    }
}

// ham nay tao ra mot cay nhi phan ma goc la max va tat ca cay con cua no deu thoa man
// tc cua mot dong max
void buildMaxHeap(int a, int n) {
    for (int i = n/2-1; i >= 0; i--) maxHeapify(a, i, n);
}

void heapSort(int a[], int n) {
    buildMaxHeap(a, n);
    // duyet tung phan tu tu cuoi len, ko duyet ptu goc
    for (int i = n-1; i >= 1; i--) {
        swap(&a[0], &a[i]); // doi goc lon nhat xuong duoi cung
        maxHeapify(a, 0, i);
    }
}

int main() {
    int a[30] = {7,2,8,3,5,9,6};
    heapSort(a, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }   
}