# 1. Lập trình nhập vào N số, tính tổng các số
# chẵn và tổng các số lẻ.
# 2. Lập trình nhập vào N số, tính trung bình
# cộng của các số dương.

def main():
    m = []
    even_sum = 0
    odd_sum = 0
    positive_sum = 0
    dem = 0
    dem_odd = 0
    dem_even = 0
    n = int(input('Cho biet so phan tu cua mang: '))
    for i in range(0, n):
        m.append(int(input(f'Nhap gia tri cua m[{i}] = ')))
        if m[i] % 2 == 0:
            even_sum += m[i]
            dem_even += 1
        else:
            odd_sum += m[i]
            dem_odd += 1
        if m[i] > 0:
            dem += 1
            positive_sum += m[i]
    
    print(f'Tong cac so chan: {even_sum}')
    print(f'So cac phan tu chan: {dem_even}')
    print(f'So cac phan tu le: {dem_odd}')
    print(f'Tong cac so le: {odd_sum}')
    print(f'Trung binh cong cua cac so duong: {positive_sum / dem}')

main()