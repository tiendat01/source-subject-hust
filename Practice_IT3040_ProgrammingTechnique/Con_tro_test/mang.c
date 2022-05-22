// #include <stdio.h>

// int main() {
//     char s1[10] = "ABC", *s2 = "ABC", *s3;
//     s3 = "ABC";
//     printf("s1 = %s, s2 = %s, s3 = %s",s1,s2,s3);
//     printf("\ns1[1] = %c, s2[1] = %c, s3[1] = %c",s1[1],s2[1],s3[1]);
//     s3 = s1; // khi do s1 va s3 la giong nhau
//     s1[1] = 'D';
//     // s2[1] = 'D'; // loi vi "ABC" la const nen ko thay doi bang phep gan dc
//     s3[2] = 'F';
//     printf("\ns1 = %s, s2 = %s, s3 = %s",s1,s2,s3);
//     printf("\ns1[1] = %c, s2[1] = %c, s3[1] = %c \n",s1[1],s2[1],s3[1]);
//     gets(s1);
//     // gets(s2); // loi vi s2 chua duoc cap phat bo nho
//     gets(s3);
//     printf("\ns1 = %s, s2 = %s, s3 = %s",s1,s2,s3);
// }

// Sau khi cap phat bo nho cho s2:
#include <stdio.h>
#include <stdlib.h>


int main() {
    char s1[10] = "ABC", *s2 = "ABC", *s3;
     s2 = (char*)malloc(sizeof(char)); 
     gets(s2);
    s3 = "ABC";
    printf("s1 = %s, s2 = %s, s3 = %s",s1,s2,s3);
    printf("\ns1[1] = %c, s2[1] = %c, s3[1] = %c",s1[1],s2[1],s3[1]);
    s3 = s1; // khi do s1 va s3 la giong nhau
    s1[1] = 'D';
     s2[1] = 'D'; // loi vi "ABC" la const nen ko thay doi bang phep gan dc
    s3[2] = 'F';
    printf("\ns1 = %s, s2 = %s, s3 = %s",s1,s2,s3);
    printf("\ns1[1] = %c, s2[1] = %c, s3[1] = %c \n",s1[1],s2[1],s3[1]);
    gets(s1);
     gets(s2); // loi vi s2 chua duoc cap phat bo nho
    gets(s3);
    printf("\ns1 = %s, s2 = %s, s3 = %s",s1,s2,s3);
    free(s2);
}
