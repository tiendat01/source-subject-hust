# Ví dụ 3: In ra biểu diễn nhị phân của số
# nguyên dương n.
# #include <stdio.h>
# void bin(int k) {
# if (k > 0) bin(k / 2);
# printf(“%d”, k % 2);
# }
# void main() {
# int n;
# printf("Nhap n: ");
# scanf("%d", &n);
# printf(“Bieu dien nhi phan:");
# bin(n);
# }

def bin(k):
    if (k > 0):
        bin(k // 2)
    print(f'{k % 2}', end='')
def main():
    n = int(input('Nhap n: '))
    print('Bieu dien nhi phan:')
    bin(n)
main()