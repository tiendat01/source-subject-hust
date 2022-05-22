# 1. Viết các hàm tính diện tích và chu vi hình
# tròn.

import math
def area(r):
    return r * r * math.pi
def perimeter(r):
    return 2 * r * math.pi
    
def main():
    r = float(input('Nhap ban kinh hinh tron: '))
    print(f'Dien tich hinh tron: {area(r)}')
    print(f'Chu vi duong tron: {perimeter(r)}')
main()
