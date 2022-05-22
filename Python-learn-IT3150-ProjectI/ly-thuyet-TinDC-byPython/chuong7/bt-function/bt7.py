# 7. Viết hàm tính khoảng cách giữa 2 điểm trong
# không gian 3 chiều.

import math
class point3D:
    def __init__(self, x, y, z) -> None:
        self.x = x
        self.y = y
        self.z = z
    def distance(self, other):
        return math.sqrt((self.x - other.x)**2 + (self.y- other.y)**2 + (self.z - other.z)**2)
    def mid(self, other):
        return point3D((self.x + other.x)/2, (self.y + other.y)/2, (self.z + other.z)/2)
    def display(self):
        toado = (self.x, self.y, self.z)
        print(f'{toado}')

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
if __name__ == '__main__':
    main()