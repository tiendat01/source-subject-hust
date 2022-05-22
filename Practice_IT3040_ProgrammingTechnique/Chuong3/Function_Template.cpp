#include <iostream>

using namespace std;

// x, y cung kieu du lieu
// template <typename T>
// T maxval (T x, T y) {
//     return (x > y) ? x : y;
// }

// int main() {
//     int i = maxval(4, 3); // return 4
//     cout << i;
// }

// khac phuc: x, y khac kieu du lieu
// co the dung class hay typename cg dc??
// template <class temp , class temp1>
// void sum(temp intVal , temp1 doubleVal) 
// {
// 	cout<<int1+double1;
// }

// int main()
// {
// 	int intVal = 1;
// 	double doubleVal = 1.1;
// 	sum(intVal , doubleVal);
//  return 0;
//  }


// function_templates2.cpp
template<class T> void f(T) {}
int main(int j) {
   f<char>(j);   // Generate the specialization f(char).
   // If not explicitly specified, f(int) would be deduced.
}