# 3. Viết hàm nhập/xuất mảng a các số nguyên
# có n phần tử từ bàn phím.

def input_arr(a):
    n = int(input('Nhap so luong phan tu cua mang a: '))
    for i in range(0, n):
        element = int(input(f'Nhap a[{i}] = '))
        a.append(element)
    return a
def print_arr(a):
    print('Cac phan tu cua mang so nguyen a: ')
    for element in a:
        print(f'{element:<5d}', end='')
def main():
    a = []
    input_arr(a)
    print_arr(a)
    
main()
