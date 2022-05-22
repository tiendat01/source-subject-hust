#include <stdio.h>
#include <conio.h>
int main()
{
 	int a, b, c, tong;
 	printf("Nhap a:"); scanf("%d",&a);
	printf("Nhap b:"); scanf("%d",&b);
  	printf("Nhap c:"); scanf("%d",&c);
  	tong=a+b+c;
  	printf("%d",tong);
  	printf("\n%f",(float)tong/3);
  	getch();
  	return 0;
}
