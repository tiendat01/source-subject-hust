#include <stdio.h>

int get_value(int x) {
    return 2*x*x + x;
}

int get_value(int x, int a) {
    return a*x*x + x;
}

int get_value(int x, int a, int b) {
    return a*x*x + b*x;
}

int get_value(int x, int a, int b, int c) {
    return a*x*x + b*x + c;
}

int main(){
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int x;
    scanf("%d", &x);
    
    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c
    
    scanf("%d%d%d", &a, &b, &c);
    
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    
    return 0;
}
