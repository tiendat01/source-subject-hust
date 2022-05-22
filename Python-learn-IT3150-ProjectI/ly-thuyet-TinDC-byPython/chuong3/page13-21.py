a = 1234
print('{:5}'.format(a))
print('{so:5}'.format(so = 34))

print('{:3} {:>15} {:>3}'.format(1, 'nguyen van a', 'g'))
print('{:3} {:>15} {:>3}'.format(2, 'tran van b', 'k'))


print('%f' % 17.345)
print('%.2f' % 17.345)
print('%7.2f' % 17.345)

a = 1000
print('So a la: %1d' % a)
print('So a la: %06d' % a)

print('%-3d %-15s %.02f %-3c' % (9, 'nguyen van a', 7.5, 'g'))
print('{:<3d} {:<15s} {:.2f} {:<3s}'.format(10, 'nguyen ha', 6.75, 'k'))