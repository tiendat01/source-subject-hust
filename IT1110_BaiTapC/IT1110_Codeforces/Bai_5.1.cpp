#include <stdio.h>

int main()
{
	int n, i, x = 0, countX = 0, countY = 0;
	float am = 0, duong = 0;
	int mang[99];
	
	do
	{
		scanf("%d", &n);
	} while(n < 1 || n > 99);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &mang[i]);
	}
	
	for(i = 0; i < n; i++)
	{
		if(mang[i] < 0)
		{
			x += mang[i];
			++countX;
		}
		else
		{
			duong += mang[i];
			++countY;
		}
	}
	//printf("%d\n%f\n%d\n%d\n", x, duong, countX, countY);
	if (countX == 0)
		am = 0;
	else
		am = (float) x / countX;
	
	printf("%f %f", am, duong);
	
	
	
	
	
}
	

