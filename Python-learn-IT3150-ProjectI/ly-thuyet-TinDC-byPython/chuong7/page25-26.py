# #include <stdio.h>
# #include <conio.h>
# #include <stdlib.h>
# int main(int argc, char *argv[])
# {
# int i, j, k, n;
# printf("Danh sach cac tham so: \n");
# for (i = 0; i < argc; i++)
# printf("%s\n", argv[i]);
# n = atoi(argv[1]);
# printf("n = %d\n", n);
# for (i = 1; i <= n; i++)
# {
# for (k = 1; k <= n - i; k++)
# printf(" ");
# for (j = 1; j <= 2 * i - 1; j++)
# printf("*");
# printf("\n");
# }
# return 0;
# }

import sys
def main():
    args = sys.argv
    print('Danh sach cac tham so: ')
    for arg in args:
        print(arg)
    n = int(args[1])
    print(f'n = {n}')
    for i in range(1, n+1):
        for k in range(1, n-i+1):
            print(' ', end='')
        for j in range(1, 2*i):
            print('*', end='')
        print()

main()
# in commandline:
# python page25-26.py 10 nguyentiendat  => n = 10