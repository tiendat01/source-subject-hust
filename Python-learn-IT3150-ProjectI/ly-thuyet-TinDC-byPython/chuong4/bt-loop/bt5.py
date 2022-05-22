# Bài 5. Viết chương trình yêu cầu người sử dụng nhập
# vào các số nguyên từ bàn phím cho đến khi nhập số 0
# thì kết thúc. Tính tổng các số chẵn và tổng các số lẻ
# đã được nhập.

def main():
    n = int(input('Nhap vao so nguyen, nhap 0 de ket thuc: '))
    odd_sum = 0
    even_sum = 0
    while n != 0:
        if n % 2 == 0:
            even_sum += n
        else:
            odd_sum += n
        n = int(input())
    print(f'Tong cac so chan: {even_sum}')
    print(f'Tong cac so le: {odd_sum}')

main()

