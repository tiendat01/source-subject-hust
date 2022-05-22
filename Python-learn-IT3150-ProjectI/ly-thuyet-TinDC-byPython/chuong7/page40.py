# #include <stdio.h>
# int giaithua(int k) {
# return k == 1 ? 1 : k * giaithua(k - 1);
# }
# int main() {
# int n;
# printf("Nhap n: ");
# scanf("%d", &n);
# printf("%d! = %d", n, giaithua(n));
# return 0;
# }

def giaithua(k):
    return 1 if k == 1 else k * giaithua(k-1)

def main():
    n = int(input('Nhap n: '))
    print(f'{n}! = {giaithua(n)}')

main()