#include <stdio.h>
#include <math.h>

int GetNumber()
{
    int input;
    char c;
    while (1)
    {
        printf("\nEnter your positive integer number: ");
        fflush(stdin);
        if (scanf("%d%c", &input, &c) != 2 || c != '\n' || input > 1000 || input < 99)
            printf("Systax error! Please try again!");
        else
            break;
    }
    return input;
}
int main()
{
    int number = GetNumber();
    int result = 0, remain;
    for (int i = 2; i > -1; i--)
    {
        remain = number % 10;
        number = (number - remain)/10;
        result += (remain * pow(10, i));
    }

    printf("\nKet qua la: %d", result);
}