#include <stdio.h>

int GetNumber()
{
    int input;
    char c;
    while (1)
    {
        printf("\nEnter your positive integer number: ");
        fflush(stdin);
        if (scanf("%d%c", &input, &c) != 2 || c != '\n' || input > 256)
            printf("Systax error! Please try again!");
        else
            break;
    }
    return input;
}
int GetPosition()
{
    int input;
    char c;
    while (1)
    {
        printf("\nEnter your positive integer number: ");
        fflush(stdin);
        if (scanf("%d%c", &input, &c) != 2 || c != '\n' || input < -1 || input > 8)
            printf("Systax error! Please try again!");
        else
            break;
    }
    return input;
}
int main()
{
    printf("Enter your number and position of bit you want to know!!!");
    int a = GetNumber(), n = GetPosition();
    int bit[8];
    int digit;
    for (int i = 7; i > -1; i--)
    {
        digit = a % 2;
        bit[i] = digit;
        a /= 2;
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%d", bit[i]);
    }
    printf("\n%d", bit[n - 1]);
    
    
}