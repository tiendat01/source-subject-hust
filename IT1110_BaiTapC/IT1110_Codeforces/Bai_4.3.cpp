#include <stdio.h>
int main()
{
	int n, i, tong = 0;
	do
	{
		scanf("%d", &n);
	} while(n < 1 || n > 999);
	// khong biet so lan lap cu the, su dung vong lap while
	while(n != 0)
	{
		i = n % 10;
		tong += i;
		n = (n - i) / 10;
	}
	printf("%d", tong);
}
