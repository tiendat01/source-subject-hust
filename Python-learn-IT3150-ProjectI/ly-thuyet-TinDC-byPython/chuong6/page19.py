# Lập trình nhập vào 2 điểm trong không gian 3 chiều.
# Tính khoảng cách giữa 2 điểm đó.

import math
class point3D:
    def __init__(self, x, y, z) -> None:
        self.x = x
        self.y = y
        self.z = z
    def distance(self, other):
        return math.sqrt((self.x - other.x)**2 + (self.y- other.y)**2 + (self.z - other.z)**2)


def input_point():
    point = point3D(0,0,0)
    point.x = float(input('Nhap toa do x: '))
    point.y = float(input('Nhap toa do y: '))
    point.z = float(input('Nhap toa do z: '))
    return point


def main():
    p1 = point3D(0,0,0)
    p2 = input_point()
    
    print(f'Khoang cach giua hai diem la: {p1.distance(p2)}')

main()