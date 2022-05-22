# #include <stdio.h>
# #include <conio.h>
# int a, b, c;
# int tich()
# {
# printf("\n Gia tri cac bien tong the
# a, b, c: ");
# printf(" a = %-5d b = %-5d c = %-
# 5d“,a,b,c);
# return a*b*c;
# }
# int main()
# {
# printf("\n Nhap gia tri cho 3
# so nguyen a, b, c: ");
# scanf("%d %d %d",&a,&b,&c);
# printf("\n Tich cua 3 so la
# %d",tich());
# return 0;
# }

import sys
import re

def tich():
    # global a, b, c
    print('Gia tri cac bien tong the a, b, c: ')
    print(f'a = {a:<5} b = {b:<5} c = {c:<5}')
    return a*b*c

def main():
    global a, b, c
    print('Nhap gia tri cho 3 so nguyen a, b, c: ')
    inp = sys.stdin.read() # In Windows, Ctrl+Z to stop input
    inp = re.split('\n| ', inp) # split inp by multiple delimiters: '\n' and ' ' => inp is now a list
    i= 0
    while i < len(inp):
        if (len(inp[i]) == 0):
            inp.pop(i)
        else: 
            i += 1
    # print(inp)
    a = int(inp[0])
    b = int(inp[1])
    c = int(inp[2])
    print(f'Tich cua 3 so la {tich()}')

main()