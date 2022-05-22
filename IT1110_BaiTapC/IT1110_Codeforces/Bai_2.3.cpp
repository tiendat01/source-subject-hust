#include<stdio.h>
int main()
{
	float x, y, min;
	scanf("%f", &x);
	scanf("%f", &y);
	if (x < y)
		min = x;
	else
		min = y;
	printf("%6.2f", min);
	return 0;
}
