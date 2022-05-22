# #include <conio.h>
# #include <stdio.h>
# void main()
# { int a = 5;
# float x = 1.234;
# printf(“Hien thi mot so nguyen %d và mot so thuc %f”, a, x);
# getch();
# }


import msvcrt

def main():
    a, x = 5, 1.234
    print('Hien thi mot so nguyen {int} va mot so thuc {float}'.format(int = a, float = x), end='', flush=True)
    msvcrt.getch()

if __name__ == '__main__':
    main()

 