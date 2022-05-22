# • Lập trình in ra màn hình kết quả như sau
# (chiều cao n được nhập từ bàn phím)
# *
# **
# ***
# ****
# *****
# ******
# *******
# ********
# *********
# **********
# *
# **
# ***
# ****
# *****
# ******
# *******
# ********
# *********
# **********
# *
# ***
# *****
# *******
# *********
# ***********
# *************
# ***************
# *****************
# *******************
# Hình 1 Hình 2 Hình 3


def left(h):
    for i in range(0, h):
        for j in range(0, i+1):
            print('*', end='')
        print()

def right(h):
    for i in range(0, h):
        for j in range(0, h):
            if (j < h-i-1): print(' ', end='')
            else: print('*', end='')
        print()

def center(h):
    for i in range(0, h):
        for j in range(0, 2*h):
            if h+i - (2*i+2) < j and j < h+i: print('*', end='')
            else: print(' ', end='')
        print()

def main():
    n = int(input('Nhap chieu cao n: '))
    left(n)
    right(n)
    center(n)

main()