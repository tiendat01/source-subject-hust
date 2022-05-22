# #include <stdio.h>
# void main()
# {
# { int a = 1;
# printf("\n a = %d",a);
# { int a = 2;
# printf("\n a = %d",a);
# }
# printf("\n a = %d",a);
# }
# { int a = 3;
# printf("\n a = %d",a);
# }
# }

def main():
    def outer():
        a = 1
        print(f'a = {a}')
        def inner():
            a = 2
            print(f'a = {a}')
        inner()
        print(f'a = {a}')
    outer()

    def outer():
        a = 3
        print(f'a = {a}')
    outer()

main()