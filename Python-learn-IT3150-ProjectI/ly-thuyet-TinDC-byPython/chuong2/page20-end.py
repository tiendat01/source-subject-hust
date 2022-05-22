# algorithmetic operators
print(5 + 8)
print(3.6 + 2.9)
print(3 - 1.6)
print(2.6 * 1.7)
print(10.0 / 3.0)
print(10 / 3.0)
print(10.0 / 3)
print(10 / 3)
print(10 // 3) # floor divide
print(10 % 3)
# bitwise operators
print(5 & 6)
print('{:b} & {:b} == {:b}'.format(5, 6, 5 & 6))

print(5 | 6)
print('{0:5b} & {1:5b} == {2:5b}'.format(5, 6, 5 & 6))

print(5 ^ 6)
print('{first:5b} & {second:5b} == {res:5b}'.format(first = 5, second = 6, res = 5 & 6))

print('{:b}'.format(5 << 2))
print(bin(5 >> 2)) # 0b la ky hieu so nhi phan
print('{:b}'.format(~6))

# comparison operators
bool(2>3)
bool(6>4)
bool(5<3)
bool(6>=4)
bool(5<=5)
bool(2<=9)
bool(3==4)
bool(5!= 6)
bool(6!=6)

# logical operators
bool(3<5 and 4<6)
bool(2<1 and 2<3)
bool(6 or 0)
bool(3<2 or 3<3)
bool(not 3)
bool(not (2>5))

# assign operators
a = b = 2007
a = 20
c = a * b
a < 10 and 2 * b < c

a,b,c,d = 35,14,5,6
print(f'{a} {b} {c} {d}')
e = (a + b) * c / d
e = ((a + b) * c) / d 
e = (a + b) * (c / d) 
e = a + (b * c) / d

a, b = 10, 15
c = a & 0x0F + b | 0x0E
print(c)

# python doesn't support ++ and -- operators

a = 2006
print('a = ' + oct(a))
print('a = ' + hex(a))
print('Địa chỉ a: ' + hex(id(a)))


# ternary operator:
x, y, z = 3.8, 7.6, 0
z = x if x < y else y
print(z)
