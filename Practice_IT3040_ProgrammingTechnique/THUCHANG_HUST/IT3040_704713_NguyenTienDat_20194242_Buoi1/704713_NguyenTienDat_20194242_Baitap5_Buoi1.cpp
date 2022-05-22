#include <stdio.h> 

double* maximum(double* a, int size){
    double *max;
    max = a;
    if (a==NULL) return NULL;
	for (int i = 1; i < size; i++) {
		if (*max < a[i]) max = a+i;
	}
    return max;
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n\n");
	double arr[] = {1., 10., 2., -7., 25., 3.};
	double* max = maximum(arr, 6);
	printf("Gia tri lon nhat cua mang: ");
	printf("%.0f", *max);
	return 0;
}
