# #include <stdio.h>
# #include <string.h>
# void main(){
# char str1[10] = “abc”;
# char str2[10] = “def”;
# printf(“ str1: %s”,str1);
# printf(“\n str2: %s”,str2);
# printf(“\n strcmp(str1,str2)= %d”,
# strcmp(str1,str2));
# printf(“\n strcpy(str1,str2) = %s”,
# strcpy(str1,str2));
# printf(“ str1: %s”,str1);
# printf(“\n str2: %s”,str2);
# strcpy(str1,”ab”); // str1  “ab”
# strcpy(str2,”abc”); // str2  “abc”
# printf(“ str1: %s”,str1);
# printf(“\n str2: %s”,str2);
# printf(“\n strcmp(str1,str2) = %d”,
# strcmp(str1,str2));
# }

def strcmp(str1, str2):
    if (str1 < str2):
        return -1
    elif str1 > str1:
        return 1
    else:
        return 0

# string is immutable => can't change argument
def strcpy(pstr1, pstr2):
    pstr1 = pstr2
    return pstr1

def main():
    str1 = 'abc'
    str2 = 'def'
    print(f'str1: {str1}')
    print(f'str2: {str2}')
    print(f'strcmp(str1, str2) = {strcmp(str1, str2)}')
    str1 = str2 # strcpy
    print(f'strcpy(str1, str2) = {str1}')
    print(f'str1: {str1}')
    print(f'str2: {str2}')
    str1 = 'ab'
    str2 = 'abc'
    print(f'str1: {str1}')
    print(f'str2: {str2}')
    print(f'strcmp(str1, str2) = {strcmp(str1, str2)}')

main()