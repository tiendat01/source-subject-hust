#include <iostream>
using namespace std;

template <typename T>

//# viết hàm arr_sum
T arr_sum (T *arr1, int n1, T *arr2, int n2) {
    T sum1 = 0, sum2 = 0;
    for (int i = 0; i < n1; i++) sum1 += arr1[i];
    for (int i = 0; i < n2; i++) sum2 += arr2[i];
    return sum1 + sum2;
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
