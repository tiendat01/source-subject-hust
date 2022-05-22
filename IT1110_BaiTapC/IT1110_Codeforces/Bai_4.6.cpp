#include <stdio.h>

int main()
{
	int n, i, heso = 1, giaiThua = 1;
	float x, S1 = 1, S2 = 1, S3 = 1, bigx = 1;

	do
	{
		scanf("%d", &n);
	} while(n < 1);
	scanf("%f", &x);
	
	for(i = 1; i <= n; i++)
	{
		bigx *= x;
		heso *= (-1);
		giaiThua *= i;
		S1 += bigx;
		S2 += heso * bigx;
		S3 += bigx / giaiThua;
	}
	printf("%f\n", S1);
	printf("%f\n", S2);
	printf("%f", S3);
}
