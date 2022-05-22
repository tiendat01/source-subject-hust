# int max(int a, int b, int c)
# {
# int ket_qua;
# ket_qua = a;
# if(ket_qua < b) ket_qua = b;
# if(ket_qua < c) ket_qua = c;
# return ket_qua;
# }

def my_max(a, b, c):
    ket_qua = a
    if (ket_qua < b):
        ket_qua = b
    if (ket_qua < c):
        ket_qua = c
    return ket_qua

def main():
    print(my_max(10,2,3))

main()