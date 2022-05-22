#include <stdio.h>

int cube(int x) {
    //# trả về lập phương của x
    return x*x*x;
}

//# viết hàm tính lập phương của một số kiểu double
double cube(double x) {
    return x*x*x;
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}
