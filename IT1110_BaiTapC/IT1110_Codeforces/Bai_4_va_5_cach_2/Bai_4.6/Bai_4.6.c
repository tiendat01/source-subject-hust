#include <stdio.h>

float Pow(float x, int k)
{
    if (k == 0) return 1;
    else return x * Pow(x, k-1);
}

int GiaiThua(int n)
{
    if (n == 1 || n == 0) return 1;
    else return n * GiaiThua(n - 1);
}

int main()
{
    float x, s1 = 1, s2 = 1, s3 = 1;
    int n, i;
    do scanf("%d", &n);
    while (n < 1);
    scanf("%f", &x);

    for (i = 1; i <= n; i++)
    {
        s1 += Pow(x, i);;
        s2 += Pow(-1, i) * Pow(x, i);
        s3 += Pow(x, i) / GiaiThua(i);
    }

    printf("%f\n%f\n%f", s1, s2, s3);
}