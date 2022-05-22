#include <stdio.h>
#include <string.h>

int main()
{
	int arr[10] = {9, 8, 7, 4, 5, 6, 3, 2, 1};
	int temp = 0;
	int n = 9;
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1 - i; j > 0; j--)
		{
			if (arr[n - i - j - 1] > arr[n - i -j])
			{
				temp = arr[n - i - j];
				arr[n - i - j] = arr[n - i - j - 1];
				arr[n - i - j - 1] = temp;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
}
