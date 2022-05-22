#include <stdio.h>
int main(){
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    int a[7]= {13, -355, 235, 47, 67, 943, 1222}; 
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5;i++)  printf("\t\ta[%d] ",i);
    printf("\n");
    
    int *ptr = a;
    for (int i = 0; i < 5; i++) printf("%20p", ptr+i);
           
    return 0;
}
