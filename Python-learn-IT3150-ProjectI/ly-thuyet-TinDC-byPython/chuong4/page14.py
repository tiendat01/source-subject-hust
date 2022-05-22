# Nhập 3 số thực a, b, c từ bàn phím. Tìm và in
# ra số lớn nhất và nhỏ nhất


def my_max(a, b, c):
    max = a
    if max < b:
        max = b
    if max < c:
        max = c
    return max

def my_min(a, b, c):
    min = a
    if min > b:
        min = b
    if min > c:
        min = c
    return min

def main():
    a = float(input('Nhap so a: '))
    b = float(input('Nhap so b: '))
    c = float(input('Nhap so c: '))
    print(f'So lon nhat: {my_max(a, b, c)}')
    print(f'So nho nhat: {my_min(a, b, c)}')
    
main()