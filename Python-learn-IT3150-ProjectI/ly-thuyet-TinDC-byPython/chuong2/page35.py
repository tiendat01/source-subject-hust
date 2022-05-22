#include <stdio.h>
#include <conio.h>
# void main()
# {
# long int li; 
# int i; 
# float f; 
# clrscr();
# li = 0x123456; 
# f = 123.456;
# i = (int) li;  
# printf(“\n li = %ld; i = %d”, li, i);
# i = (int) f;
# printf(“\n f = %f; i = %d”, f, i);
# getch();
# }


# import only system from os
from os import system, name
  
# # import sleep to show output for some time period
# from time import sleep
  
# define our clear function
def clear():
  
    # for windows
    if name == 'nt':
        _ = system('cls')
  
    # for mac and linux(here, os.name is 'posix')
    else:
        _ = system('clear')
  
# # print out some text
# print('hello geeks\n'*10)
  
# # sleep for 2 seconds after printing output
# sleep(2)
  
# # now call function we defined above
# clear()

import msvcrt
import numpy as np

def main():
    clear()
    li, f = 0x123456, 123.456
    i = np.int16(li)
    print('\n li = %(li)d; i = %(i)d' % {'li': li, 'i': i}) # using dictionary in print()
    i = int(f)
    print('\n f = %(f)f; i = %(i)d' % {'f': f, 'i': i}, end='', flush=True)
    msvcrt.getch()

if __name__ == '__main__':
    main()

    