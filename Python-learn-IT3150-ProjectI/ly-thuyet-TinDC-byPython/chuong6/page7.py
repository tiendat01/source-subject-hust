class sinh_vien:
    def __init__(self, ma_so, ho_va_ten, diem_tinDC):
        self.ma_so = ma_so
        self.ho_va_ten = ho_va_ten
        self.diem_tinDC = diem_tinDC

class point_3D:
    def __init__(self) -> None:
        self.x = 0
        self.y = 0
        self.z = 0

class point_2D:
    def __init__(self) -> None:
        self.x = 0
        self.y = 0

from page7 import point_2D as p_2D
def main():
    sv = sinh_vien('20194242', 'nguyen tien dat', 10)
    pnt = point_3D()
    pnt2 = p_2D()
    print(sv.ho_va_ten)
    print(pnt.x)
    print(pnt2.x)
if __name__ == '__main__':
    main()