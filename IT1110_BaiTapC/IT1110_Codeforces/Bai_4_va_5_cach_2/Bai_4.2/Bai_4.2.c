#include<stdio.h>
#include<math.h>

int main()
{
    int n, i;
    scanf("%d", &n);

    if (n < 2) printf("Khong phai la so nguyen to!");
    else
    {
        for (i = 2; i < sqrt(n); i++)
        {
            if (n % i == 0) 
            {
                printf("Khong la so nguyen to!");
                break;
            }
        }
        printf("La so nguyen to!");
        
    }
    
}
