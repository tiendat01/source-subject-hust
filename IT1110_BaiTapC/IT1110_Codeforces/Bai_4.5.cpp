#include<stdio.h>
#include<math.h>
int main(){
	float a,b,c,d,x,y;
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	if(a==0){
		if (b!=0){
		x=-c/b;
		printf("%f",x);
	}else{
		if(c!=0){
			printf("Phuong trinh vo nghiem");
		}else{
			printf("Phuong trinh vo so nghiem");
		}
	}
	}else{
		d=b*b-4*a*c;
		if(d>=0){
			if(d>0){
			x=(-b+sqrt(d))/(2*a);
			y=(-b-sqrt(d))/(2*a);
			printf("%f",x);
			printf("\n%f",y);
			}else{
				x=-b/(2*a);
				printf("%f",x);
			}
		}else{
			d=-d;
			x=-b/(2*a);
			y=sqrt(d)/(2*a);
			printf("%f+%fi",x,y);
			printf("\n%f-%fi",x,y);
		}
		
	}
	return 0;
}
