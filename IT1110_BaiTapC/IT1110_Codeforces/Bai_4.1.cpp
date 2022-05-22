#include <stdio.h>
int main()
{
	int n, i, giaiThua;
	giaiThua = 1;
	do
	{
		scanf("%d", &n);
	} while (n < 1 || n > 7);
	for (i = 1; i < n + 1; i++)
		giaiThua *= i;
	printf("%d", giaiThua);
}
