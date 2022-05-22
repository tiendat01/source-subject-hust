# void tamgiac(int n)
# {
# int i, j, k;
# for (i=1; i<=n; i++)
# {
# for (k=1; k<=n-i; k++)
# printf(" ");
# for (j=1;j<=2*i-1;j++)
# printf("*");
# printf("\n");
# }
# }

def tamgiac(n):
    for i in range(1, n+1):
        for k in range(1, n-i+1):
            print(' ', end='')
        for j in range(1, 2*i):
            print('*',end='')
        print()

# ghi de ham tamgiac(n) co tham so
def tamgiac():
    n = 10
    for i in range(1, n+1):
        for k in range(1, n-i+1):
            print(' ', end='')
        for j in range(1, 2*i):
            print('*',end='')
        print()

def main():
    # tamgiac(5)
    tamgiac()
main()