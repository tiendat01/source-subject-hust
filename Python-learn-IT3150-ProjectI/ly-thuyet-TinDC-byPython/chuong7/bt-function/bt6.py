def compare_ignorecase(str1, str2):
    return bool(str1.lower() == str2.lower())
    
def main():
    str1 = 'dat'
    str2 = 'Datg'
    if (compare_ignorecase(str1, str2)):
        print('Hai xau la giong nhau, khong phan biet chu hoa chu thuong')
    else:
        print('Hai xau khac nhau, khong phan biet chu hoa chu thuong')
        
main()
    