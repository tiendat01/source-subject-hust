#include <stdio.h>
#include <string.h>

struct HocSinh
{
	char name[51];
};

void XoaKiTu(char s[], int viTriXoa)
{
	int n = strlen(s);
	for (int i = viTriXoa; i < n; i++)
		s[i] = s[i + 1];
	s[n - 1] = '\0'; 
	n--;
}

void ChuanHoa(char str[])
{
	int n = strlen(str);
	
	// Xoa khoang trang
	// Xoa khoang trang o dau cau
	while (str[0] == ' ')
	{
		XoaKiTu(str, 0);
		n--;
	}
	// Xoa khoang trang o cuoi cau
	while (str[n - 1] == ' ')
	{
		XoaKiTu(str, n - 1);
		n--;
	}
	// Xoa khoang trang o giua cau
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			XoaKiTu(str, i);
			i--;
			n--;
		}
	}
	
	// In hoa chu cai
	for (int i = 0; i < n; i++)
	{
		if (str[i] != ' ' && 'a' <= str[i] && 'z' >= str[i])
			str[i] -= 32;	
	}
}

int main()
{
	int n;
	int doDai[51];
	struct HocSinh list[101];
	do
	{
		scanf("%d", &n);
	} while (n < 0 || n > 101);
	getchar(); // Khu ki tu '\n'
	// Có 2 cách de khu ki tu '\n' bi chua ra cua ham scanf; 1 la dung getchar() (nhu tren), 2 la them \n sau %d trong scanf
	
	for (int i = 0; i < n; i++)
	{
		gets(list[i].name);
		ChuanHoa(list[i].name);
		doDai[i] = strlen(list[i].name);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s:%d\n", list[i].name, doDai[i]);
	}
	return 0;
}
