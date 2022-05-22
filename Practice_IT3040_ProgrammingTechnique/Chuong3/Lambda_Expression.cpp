#include <iostream>
using namespace std;

// void stdio_doing(int n) {
//     n = n + 10;
//     cout << n << " ";
// }

// void for_each(int *arr, int n, void (*func) (int a)) {
//     for (int i = 0; i < n; i++) {
//         func(*(arr + i));
//     }
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 5}, n = 5;
//     // goi ham dung con tro ham
//     // for_each(arr, n, stdio_doing);

//     // ham nac danh:
//     // khi do ko can khai bao + dinh nghia 1 ham stdio_doing
//     for_each(arr, n, [] (int a) {
//         a = a + 10;
//         cout << a << " ";
//     });
//     return 0;
// }

int main() {
    // auto y = [] (auto first, auto second)
    // {
    // return first + second;
    // };

    int m = 0;
    int n = 0;
    // neu muon lambda truy cap bien m la tham chieu, n la tham tri
    // cac cach khai bao sau la tuong duong:
    // auto func = [&m, n] (auto a) mutable {}
    // auto func = [n, &m] (auto a) mutable {}
    // chu y: '&' va '=' o dau tien:
    // auto func = [=, &m] (auto a) mutable { 
    auto func = [&, n] (auto a) mutable {
        m = ++n + a;
    };
    func(4);
    cout << m << endl << n << endl;
}