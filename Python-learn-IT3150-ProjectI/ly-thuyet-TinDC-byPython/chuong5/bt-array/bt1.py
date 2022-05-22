# 1. Nhập vào N số thực, kiểm tra xem dãy số có tăng
# dần hoặc giảm dần không?

def main():
    a = []
    n = int(input('Nhap vao so N: '))
    for i in range(0, n):
        a.append(float(input(f'Nhap a[{i}] = ')))
    flag_acs = True
    flag_dsc = True
    for i in range(0, n-1):
        if a[i] < a[i+1]:
            continue
        flag_acs = False
        break
    for i in range(1, n):
        if a[i] < a[i-1]:
            continue
        flag_dsc = False
        break
    if flag_acs:
        print("Day tang dan!")
    if flag_dsc:
        print('Day giam dan!')
    if flag_acs == False and flag_dsc == False:
        print('Day ko tang ko giam')
main()