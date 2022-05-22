# 1. Viết chương trình tính diện tích và chu vi
# hình tròn.

import math

def main():
    radius = float(input('Nhap ban kinh hinh tron: '))
    print(f'Dien tich hinh tron: {radius * radius * math.pi}')
    print(f'Chu vi duong tron: {2 * radius * math.pi}')

if __name__ == '__main__':
    main()