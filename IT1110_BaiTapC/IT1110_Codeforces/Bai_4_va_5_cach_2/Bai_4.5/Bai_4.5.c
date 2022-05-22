#include <stdio.h>
#include <math.h>

// Giai phuong trinh bac hai ax^2 + bx + c = 0
int main()
{
    float a, b, c, delta;
    scanf("%f%f%f", &a, &b, &c);

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                printf("Phuong trinh vo so nghiem1");
            else 
                printf("Phuong trinh vo nghiem!");
        }
        else 
            printf("%f", -c / b);
    }
    else
    {
        if (a < 0)
        {
            a = -a; b = -b; c = -c;
        }
        delta = b*b - 4*a*c;
        if (delta == 0) 
            printf("%f", -b / (2*a));
        else if (delta > 0)
            printf("%f\n%f", (-b + sqrt(delta)) / (2*a), (-b - sqrt(delta) / (2*a)));
        else
        {
            delta = -delta;
            float x = -b / (2*a), y = sqrt(delta) / (2*a);
            printf("%f + %fi\n%f - %fi", x, y, x, y);
        }
        
    }
}