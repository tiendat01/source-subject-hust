class sinhvien:
    def __init__(self) -> None:
        self.hoten = ''
        self.diem = 0
    
def main():
    a = sinhvien()
    print('Nhap thong tin sinh vien')
    a.hoten = input('Ho ten: ')
    a.diem = int(input('Diem: '))    
    b = a
    c = sinhvien()
    c.hoten = a.hoten
    c.diem = a.diem
    print(f'Bien a: {a.hoten:>20} {a.diem:<3}')
    print(f'Bien b: {b.hoten:>20} {b.diem:<3}')
    print(f'Bien c: {c.hoten:>20} {c.diem:<3}')

main()