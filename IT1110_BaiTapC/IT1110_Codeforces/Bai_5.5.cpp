#include <stdio.h>
#include <string.h>

void XoaKiTu(char str[], int viTriXoa)
{
	int n = strlen(str);
	for (int i = viTriXoa; i < n; i++)
	{
		str[i] = str[i + 1];
	}
	str[n - 1] = '\0';
	n--;
}

void ChuanHoa(char str[])
{
	int n = strlen(str);
	// Xoa ki tu dau cau
	while (str[0] == ' ')
	{
		XoaKiTu(str, 0);
	}
	// Xoa ki tu cuoi cau
	while (str[n - 1] == ' ')
	{
		XoaKiTu(str, n - 1);
	}
	// Xoa ki tu giua cau
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			XoaKiTu(str, i);
			i--;
		}
	}
	
	// In hoa chu cai dau
	char last = ' ';
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' && last == ' ')
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z' && last != ' ')
			str[i] += 32;
		last = str[i];
	}
}

int main()
{
	char list[1000][1000];
	char temp[1000];
	int n;
	do
	{
		scanf("%d", &n);
	} while (n < 0 || n > 101);
	getchar(); // Khu ki tu '\n' cua scanf
	
	for (int i = 0; i < n; i++)
	{
		gets(list[i]);
		ChuanHoa(list[i]);
	}
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (strcmp(list[j - 1], list[j]) > 0)
			{
				strcpy(temp, list[j - 1]);
				strcpy(list[j - 1], list[j]);
				strcpy(list[j], temp);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("(%d)%s\n", i + 1, list[i]);
	}
}
