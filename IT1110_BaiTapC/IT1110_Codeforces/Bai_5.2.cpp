#include <stdio.h>
int main()
{
	int m[9999];
	int n, i, j;
	do
	{
		scanf("%d", &n);
	} while (n < 1 || n > 9999);
	for(i = 0; i < n; i++)
	{
		//int temp;
		scanf("%d", &m[i]);
		//m[i] = temp;
	}
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(m[j] < m[i])
			{
				int temp;
				temp = m[j]; m[j] = m[i]; m[i] = temp;
			}
		}
	}
	for(i = 0; i < n; i++)
		printf("%d ", m[i]);
	
}
