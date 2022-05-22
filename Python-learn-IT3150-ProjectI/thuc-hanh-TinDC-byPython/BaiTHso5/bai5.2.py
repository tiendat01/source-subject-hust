# Bài 5.2 Nhập mảng số nguyên từ bàn phím. Tính trung bình cộng các số âm, tổng
# các số dương và đưa kết quả ra màn hình.

def main():
    n = int(input('Nhap so nguyen duong N: '))
    if n <= 0:
        print('ERROR')
        return None
    a = []
    sum_pos = 0
    sum_neg = 0
    count_neg = 0
    count_pos = 0
    print('Nhap n so nguyen cach nhau boi enter:')
    mang_strform = input()
    inp = mang_strform.split(' ')
    for i in range(0, n):
        tmp = int(inp[i])
        if tmp < 0: sum_neg += tmp; count_neg += 1
        else: sum_pos += tmp
    if sum_pos == 0:
        print('Mang ko co so duong!')
        print(f'Gia tri trung binh cong cac so am: {sum_neg/count_neg}')
    else:
        print(f'Tong các số dương: {sum_pos}')
        if count_neg == 0: print('Mang ko co so am')
        else: print(f'Gia tri trung binh cong cac so am: {sum_neg/count_neg}')

main()