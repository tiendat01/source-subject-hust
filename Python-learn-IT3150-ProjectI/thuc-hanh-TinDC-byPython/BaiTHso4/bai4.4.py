# Bài 4.4 Viết chương trình thực hiện các công việc sau:
# - Nhập 2 số nguyên dương bất kỳ
# - Tìm ước số chung lớn nhất và bội số chung nhỏ nhất của 2 số đó
# - Hiển thị kết quả ra màn hìnhTÀI LIỆU HƯỚNG DẪN THỰC HÀNH
# TIN HỌC ĐẠI CƯƠNG - IT1110
# © 2021 – HUST – SOICT
# 34
# Chú ý:
# - Sử dụng vòng lặp while để làm
# - Kiểm tra dữ liệu đầu vào của chương trình, nếu không đúng thì kết thúc chương
# trình và in ra màn hình ERROR.

def UCLN(a, b):
    c = min(a, b)
    if a != b:
        for i in range(c, 0, -1):
            if b % i == 0 and a % i == 0:
                return i
    else: return a

def UCLN_while(a, b):
    while a == 0 or b == 0:
        if a < b:
            b %= a
        else:
            a %= b
    return a + b

def UCLN_dequy(a, b):
    if a < b:
        return UCLN_dequy(a, b-a)
    elif a > b:
        return UCLN_dequy(a-b, b)
    else:
        return a 

def BCNN(a, b):
    c = max(a, b)
    tich = a*b
    for i in range(c, tich, c):
        if (i % a == 0 and i % b == 0):
            return i
    # or
    return a*b/UCLN(a, b)
    

def main():
    a = int(input('Nhap so nguyen duong a: '))
    b = int(input('Nhap so nguyen duong b: '))
    print(f'UCLN cua {a} va {b} la: {UCLN_dequy(a, b)}')
    print(f'BCNN cua {a} va {b} la: {BCNN(a, b)}')


main()