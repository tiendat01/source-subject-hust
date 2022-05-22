// Function Templates
// CPP code for bubble sort
// using template function
#include <iostream>
using namespace std;
  
// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it.
template <class T>

void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
              swap(a[j], a[j - 1]);
}
  
// Driver Code
int main() {
    // uses int type
    int a[5] = {10, 50, 30, 40, 20};
    int n = sizeof(a) / sizeof(a[0]);
  
    // calls template function
    bubbleSort<int>(a, n);
  
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;


    // uses double type
    double b[5] = {10.1, 50.2, 30.3, 40.4, 20.5};
    int m = sizeof(b) / sizeof(b[0]);
  
    // calls template function
    bubbleSort<double>(b, m);
  
    cout << " Sorted array : ";
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
    cout << endl;
  
  return 0;
}