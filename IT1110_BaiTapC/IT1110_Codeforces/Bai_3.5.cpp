#include <stdio.h>
int main()
{
	float X, Y, A, B, C;
	scanf("%f", &X);
	scanf("%f", &Y);
	A = X * X + Y * Y;
	B = (X + Y) * (X + Y);
	C = (X - Y) * (X - Y);
	printf("%f\n", A);
	printf("%f\n", B);
	printf("%f", C);
	return 0;
}
