# from tkinter import Y


# print('{x:^10}'.format(x='dat'))

# print('{x: 3.899f}'.format(x = 452.0/3))

# print(1)
# try:
#   x = int( input())
#   print(x/3)
# except:
#   print("lỗi")

# print(id(x))

# z = complex(1,2)
# y = z
# y += 1
# print(y, z)

# a = [1]
# b = [1]
# print(id(a), id(b))


# def add(x, y, *args, z):
#     return x + y + sum(args) + z
# add(10, 20, 30, 40, 50) # lỗi
# add(10, 20, 30, 40, z=50) # ok

# palindrome = input("Nhập xâu ký tự cần kiểm tra palindrome: ")
# list = palindrome.split()
# for i in range(0, len(list)):
#     tmp = ''
#     for c in list[i]:
#         if c.isalnum():
#             tmp += c
#     list[i] = tmp.lower()
# new_str = ''.join(list)
# reverse_str = new_str[::-1]
# print (new_str)
# if new_str == reverse_str:
#     print('Là chuỗi palindrome')
# else:
#     print('Không là chuỗi palindrome')


# quote = '成功を収める人とは人が投げてきたレンガでしっかりした基盤を築くことができる人のことである。'
# print(quote)
# with open('quotes.txt', 'w', encoding='utf-8') as f:
#     f.write(quote)


# try:
#     # get input net sales
#     print('Enter the net sales for')

#     previous = float(input('- Prior period:'))
#     current = float(input('- Current period:'))

#     # calculate the change in percentage
#     change = (current - previous) * 100 / previous

#     # show the result
#     if change > 0:
#         result = f'Sales increase {abs(change)}%'
#     else:
#         result = f'Sales decrease {abs(change)}%'

#     print(result)
# except Exception as error:
#     print(error)
# except ValueError:
#     print('Error! Please enter a number for net sales.')
# except ZeroDivisionError:
#     print('Error! The prior net sales cannot be zero.')

import sys
import time
f = None
try:
    f = open('poem.txt')
    while True:
        line = f.readline()
        if (len(line) == 0):
            break # reach EOF
        print(line, end='')
        sys.stdout.flush()
        print('Press ctrl+c now')
        time.sleep(2) # to make sure it runs for a while
except IOError:
    print('Could not find file poem.txt')
except KeyboardInterrupt:
    print('!! You cancelled the reading from the file.')
finally:
    if f: f.close()
    print('(Cleaning up: Closed the file)')