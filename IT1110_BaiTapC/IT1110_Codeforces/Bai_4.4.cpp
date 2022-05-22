#include <stdio.h>
int main()
{
	int a, b, ucln, tich;
	do
	{
		scanf("%d", &a);
		scanf("%d", &b);
	} while(a < 1 || b < 1);
	tich = a * b;
	
	while(a != 0 && b != 0)
	{
		if(a > b)
			a %= b;
		else
			b %= a;
	}
	ucln = a + b;
	
	printf("%d\n", ucln); // do a hoac b bang 0 roi!!!
	printf("%d", tich / ucln);
	
	
	// tim ucln cach 2
	/*
	while(a != b)
	{
		if(a > b)
			a -= b;
		else
			b -= a;
	}
	ucln = a; // do a = b
	printf("%d", ucln);
	*/
}
