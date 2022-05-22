#include <stdio.h>

int StrLength(char s[])
{
    int count = 0, i = 0;
    while (s[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

void XoaKiTu(char s[], int viTriXoa)
{
	int n = StrLength(s);
	for (int i = viTriXoa; i < n; i++)
		s[i] = s[i + 1];
	s[n - 1] = '\0'; 
	n--;
}
void XoaKhoangTrang(char s[])
{	
	int n = StrLength(s);
	// Xoa khoang trang o dau cau
	while (s[0] == ' ')
	{
		XoaKiTu(s, 0);
		n--;
	}
	// Xoa khoang trang o cuoi cau	
	while (s[n - 1] == ' ')
	{
		XoaKiTu(s, n - 1);
		n--;
	}
	// Xoa khoang trang o giua cau
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			XoaKiTu(s, i);
			i--;	
		}		
	}
}

char InChuHoa (char c)
{
	if (96 < c && c < 123) // a = 97 ===> z = 97 + 25
		c -= 32;		   // A = 65 ===> Z = 65 + 25
	return c;
}

int main()
{
	char str[150];
	fflush(stdin); gets(str);
	XoaKhoangTrang(str);
	for (int i = 0; i < StrLength(str); i++)
	{
		if(str[i] != ' ')
			str[i] = InChuHoa(str[i]);
	}
	printf("%s:%d", str, StrLength(str));
}
