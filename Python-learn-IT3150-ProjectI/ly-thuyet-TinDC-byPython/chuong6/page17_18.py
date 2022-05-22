import msvcrt
class toado:
    def __init__(self) -> None:
        self.ten = []
        self.x = 0
        self.y = 0
    
def main():
    t = toado()
    print('Nhap thong tin toa do: ')
    t.ten = input('Ten diem: ')
    t.x = int(input('Toa do x: '))
    t.y = int(input('Toa do y: '))
    print('Gia tri cua cac truong: ')
    print(f'{t.ten:<5}{t.x:>3}{t.y:>3}', end='', flush=True)
    msvcrt.getch()
main()