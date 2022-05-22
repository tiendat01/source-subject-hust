# Bài 3.3 Lập chương trình thực hiện các công việc sau:
# - Nhập 2 số thực x,y
# - Tính các giá trị biểu thức sau:
# A = x^2 + y^2
# B = (x+y)^2
# C = (x-y)^2

def main():
    x = float(input('Nhap so thuc x: '))
    y = float(input('Nhap so thuc y: '))
    print(f'Gia tri cua A = {x**2 + y**2}')
    print(f'Gia tri cua B = {(x + y)**2}')
    print(f'Gia tri cua C = {(x - y)**2}')
main()