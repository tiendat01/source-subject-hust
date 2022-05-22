#include <stdio.h>
#include <math.h>
int main()
{
	double X, Y;
	scanf("%lf", &X);
	scanf("%lf", &Y);
	printf("%f", pow(Y, 6) + X*pow(Y, 5) + pow(X, 2)*pow(Y, 4) + pow(X, 3)*pow(Y, 3) + pow(X, 4)*pow(Y, 2) + pow(X, 5)*Y + pow(X, 6));
	return 0;
}
