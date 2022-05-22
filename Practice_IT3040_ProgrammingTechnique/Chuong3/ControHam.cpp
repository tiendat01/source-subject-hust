#include <iostream>

using namespace std;

// int foo() {
//     return 0;
// }

// int main() {
//     int (*p) () = foo;
//     printf("%p\n", foo);
//     printf("%p\n", p);
//     return 0;
// }




// void SwapValue (int &value1, int &value2) {
//     int tmp = value1;
//     value1 = value2;
//     value2 = tmp;
// }

// int main() {
//     void (*pSwap) (int&, int&) = SwapValue;
//     int a = 1, b = 5;
//     cout << "Before swap: a = " << a << ", b = " << b;
//     // do do uu tien cua * thap hon nen phai co () doi voi *pSwap
//     (*pSwap) (a,b);
//     // hoac goi dia chi nhu nay cung dc
//     pSwap(a,b);
//     cout << "Before swap: a = " << a << ", b = " << b;
// }


bool ascending(int left, int right) {
    return left > right;
}

bool descending(int left, int right) {
    return right < left;
}
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int *arr, int length, bool 
(*comparisonFunc) (int, int), void (*pswap) (int*, int*)) {
    for (int i = 0; i < length; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (comparisonFunc(arr[minIndex], arr[j])) {
                minIndex = j;
            }
        }
        pswap(arr+minIndex, arr+i);
    }
}
void printArray(int *arr, int length) {
    for (int i = 0; i < length; i++) cout << arr[i] << " ";
}

int main() {
    int arr[] = {1,4,2,3,6,5,8,9,7};
    int length = sizeof(arr) / sizeof(int);
    cout << "Before sorted: ";
    printArray(arr,length);
    cout << endl;
    selectionSort(arr,length, ascending, swap);
    cout << "After sorted: ";
    printArray(arr,length); 
}