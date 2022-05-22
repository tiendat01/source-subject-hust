#include <stdio.h>

#define MAX 1000 
// Ham sap xep mang theo thu tu tang dan
void Select_Sort(int n, int a[MAX]) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// ham tim kiem nhi phan dau ra: vi tri cua gia tri can tim
int BinarySearch(int n, int a_sorted[MAX], int x) {
    int i = 0, j = n-1;
    int k = 0;
    while (i <= j) {
        k = (i+j)/2;
        if (x < a_sorted[k]) j = k-1;
        if (x > a_sorted[k]) i = k+1;
        if (x == a_sorted[k]) return k;
        // ko dung else vi khi do thuat toan sai ngay!!!
    }
    return -1; // neu ko tim thay
}

// recursive:
int binary_search_recursive(int a_sorted[MAX], int left, int right, int x) {
    if (left > right) {
        printf("Error! Left index greater than right index!");
        return -1;
    }
    if (left == right) {
        if (x == a_sorted[left]) return left;
        else return -1;
    }
    int index = (right + left) / 2;
    if (a_sorted[index] == x) return index;
    else if (x < a_sorted[index]) return binary_search_recursive(a_sorted, left, index-1, x);
    else return binary_search_recursive(a_sorted, index+1, right, x);
}

int main() {
    int n = 7;
    //int a[MAX] = {9,8,7,6,5,4,3};
    // Select_Sort(7, a);
    // for (int i = 0; i < 7; i++) printf("%d ", a[i]);
    int a[MAX] = {3,4,5,6,7,8,9};
    printf("\n%d", BinarySearch(7, a, 7));
    printf("\n%d", binary_search_recursive(a, 0, 6, 7));
}


// cach 2 cho binary search
// #include <stdio.h>
// int iterativeBinarySearch(int array[], int start_index, int end_index, int element){
//    while (start_index <= end_index){
//       int middle = start_index + (end_index- start_index )/2;
//       if (array[middle] == element)
//          return middle;
//       if (array[middle] < element)
//          start_index = middle + 1;
//       else
//          end_index = middle - 1;
//    }
//    return -1;
// }
// int main(void){
//    int array[] = {1, 4, 7, 9, 16, 56, 70};
//    int n = 7;
//    int element = 16;
//    int found_index = iterativeBinarySearch(array, 0, n-1, element);
//    if(found_index == -1 ) {
//       printf("Element not found in the array ");
//    }
//    else {
//       printf("Element found at index : %d",found_index);
//    }
//    return 0;
// }
 