#include <stdio.h>
#include <math.h>
int main()
{
	int a,b;
	a = b++ = 10; //sai, vi b++ thuc hien truoc (++ uu tien hon =) se tra ve mot gia tri, ma gia tri thi khong dung ben trai toan tu gan =
	a = ++b = 10;
}
