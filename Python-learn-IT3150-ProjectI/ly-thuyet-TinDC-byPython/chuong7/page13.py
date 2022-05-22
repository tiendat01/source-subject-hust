# int giai_thua(int a)
# {
# int ket_qua;
# int i;
# if(a < 0) ket_qua = -1;
# else if(a == 0) ket_qua = 1;
# else {
# ket_qua = 1;
# for (i = 1; i <= a; i++)
# ket_qua = ket_qua * i;
# }
# return ket_qua;
# }

def giaithuc(a):
    if a < 0:
        ket_qua = -1
    elif a == 0:
        ket_qua = 1
    else:
        ket_qua = 1
        for i in range(1, a+1):
            ket_qua *= i
    return ket_qua

def main():
    print(f'{giaithuc(10)}')

main()