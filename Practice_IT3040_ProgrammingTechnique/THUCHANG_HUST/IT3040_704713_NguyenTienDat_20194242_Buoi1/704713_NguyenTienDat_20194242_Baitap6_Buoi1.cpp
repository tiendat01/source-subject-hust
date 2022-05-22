#include <stdio.h> 
#include <iostream>
using namespace std;
void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
	while (l <= r) {
		tmp = arr[l];
		arr[l] = arr[r];
		arr[r] = tmp;
		l++; r--;
	}
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
	while (l <= r) {
		tmp = *(arr+l);
		*(arr+l) = *(arr+r);
		*(arr+r) = tmp;
		l++; r--;
	}
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n\n");
	int arr[] = {9, 3, 5, 6, 2, 5};
	cout << "Before reverse: " << endl;
	for(int i = 0; i < 6; i++) cout << arr[i] << " ";
	reversearray(arr, 6);
	cout << endl << "After reverse:" << endl;
	for(int i = 0; i < 6; i++) cout << arr[i] << " ";
	int arr2[] = {4, -1, 5, 9};
	cout << endl << "Before ptr_reverse: " << endl;
	for(int i = 0; i < 4; i++) cout << arr2[i] << " ";
	ptr_reversearray(arr2, 4);
	cout << endl << "After ptr_reverse:" << endl;
	for(int i = 0; i < 4; i++) cout << arr2[i] << " ";
	return 0;
}
