# Viết hàm đếm số ký tự chữ hoa, chữ thường
# và chữ số có trong xâu ký tự

def count_alnum(s):
    c_up = 0
    c_low = 0
    c_digit = 0
    # bai 1
    for ch in s:
        if (ch.isdigit()):
            c_digit += 1
        else:
            if (ch.islower()):
                c_low += 1
            elif (ch.isupper()):
                c_up += 1

    print(f'c_up = {c_up}')
    print(f'c_low = {c_low}')
    print(f'c_digit = {c_digit}')

def maiN():
    s = '  Nguyen Tien Dat   20194242'
    count_alnum(s)

maiN()