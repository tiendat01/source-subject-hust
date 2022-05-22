def main():
    MONTHS = 12
    rainfall = []
    for i in range (0, MONTHS):
        rainfall.append(int(input(f'Nhap vao phan tu thu {i+1}: ')))
    print('Luong mua hang thang la: ')
    for i in range(0, MONTHS):
        print(f'{rainfall[i]:5d}', end=' ')
    
    max_rain = rainfall[0]
    for i in range(1, MONTHS):
        if max_rain < rainfall[i]:
            max_rain = rainfall[i]
    print(f'\nLuong mua nhieu nhat la {max_rain}')

main()