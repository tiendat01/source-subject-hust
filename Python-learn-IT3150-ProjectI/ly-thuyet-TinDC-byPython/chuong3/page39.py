# #include <conio.h>
# #include <stdio.h>
# void main()
# {
# char str[30];
# puts(“Hay cho biet ho ten ban:”);
# fflush(stdin); gets(str);
# printf(“Xin chao ”);
# puts(str);
# puts(“An phim bat ki de ket thuc...”);
# getch();
# }

import msvcrt

def main():
    str = input('Hay cho biet ho ten ban: ')
    print('Xin chao ' + str)
    print('An phim bat ky de ket thuc...', end='', flush=True)
    msvcrt.getch()

if __name__ == '__main__':
    main()