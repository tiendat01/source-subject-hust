#include <stdio.h>
#include <math.h>
int main()
{
	double x, y, z;
	scanf("%lf", &x);
	scanf("%lf", &y);
	scanf("%lf", &z);
	printf("%f", ((x + y + z)/(x*x + y*y + 1) - fabs(x - z*cos(y))));
	return 0;
}
