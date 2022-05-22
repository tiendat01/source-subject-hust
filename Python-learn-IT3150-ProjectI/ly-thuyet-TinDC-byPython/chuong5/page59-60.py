# #include <stdio.h>
# #include <ctype.h>
# void main(){
# char ch;
# printf(“Nhap vao mot ki tu: “);
# scanf(“%c”, &ch);
# if (isupper(ch)) {
# printf(“Ki tu nay la chu hoa\n”);
# printf(“Ki tu chu thuong tuong
# ung %c\n”,tolower(ch));
# } else if(islower(ch)) {
# printf(“Ki tu nay la chu thuong\n”);
# printf(“Ki tu chu hoa tuong ung %c\n”,
# toupper(ch));
# }
# }

def main():
    ch = str(input('Nhap vao mot ky tu: '))[0]
    if (ch.isupper()):
        print('Ki tu nay la chu hoa')
        print(f'Ki tu chu thuong tuong ung {ch.lower()}')
    elif (ch.islower()):
        print('Ky tu nay la chu thuong')
        print(f'Ky tu chu hoa tuong ung {ch.upper()}')
main()