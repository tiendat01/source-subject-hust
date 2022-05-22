#include <stdio.h>

int Giai_Thua(int number)
{
    if (number == 1) return 1;
    else return number * Giai_Thua(number - 1);
}

int main()
{
    int n, i, giaiThua = 1;
    do 
        scanf("%d", &n);
    while (n < 1 || n > 7);

    // Cach 1: dung vong lap for 
    // for (i = 1; i <= n; i++)
    //     giaiThua *= i;
     
    // Cach 2: dung vong lap while
    // i = 1;
    // while (i <= n)
    // {
    //     giaiThua *= i;
    //     i++;
    // }

    //Cach 3: De quy
    giaiThua = Giai_Thua(n);

    printf("%d", giaiThua);
}