# 5. Viết hàm thực hiện sắp xếp mảng a theo
# thứ tự tăng dần hoặc giảm dần.

def sort_asc(a):
    a.sort(reverse=False)
    return a
def sort_dsc(a):
    a.sort(reverse=True)
    return a
def print_arr(a):
    print('Cac phan tu cua mang so nguyen a: ')
    for element in a:
        print(f'{element:<5d}', end='')
def main():
    a = [1,2,3,-5, 4, 943, -6]
    print_arr(sort_asc(a))
    print()
    print_arr(sort_dsc(a))

main() 
