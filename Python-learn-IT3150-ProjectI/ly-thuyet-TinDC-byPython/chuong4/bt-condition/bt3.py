# Bài 3: Nhập vào 3 số a, b, c bất kỳ. Kiểm tra xem a,
# b, c có phải là 3 cạnh của tam giác hay không?
# Nếu đúng thì là tam giác gì?

def main():
    a = float(input('Nhap canh a: '))
    b = float(input('Nhap canh b: '))
    c = float(input('Nhap canh c: '))
    if a <= 0 or b <= 0 or c <= 0:
        print('Khong phai tam giac')
    else:
        if a + b > c and b + c > a and c + a > b:
            print('La tam giac', end=' ')
            max_edge = max(a, b, c)
            if a == b and a == c:
                print('deu')
            elif a == b or b == c or c == a:
                print('can')
            elif max_edge ** 2 == a ** 2 + b ** 2 or  \
                max_edge ** 2 == b ** 2 + c ** 2 or   \
                max_edge ** 2 == c ** 2 + a ** 2:    
                print('vuong')
            else:   
                print('thuong')

main()