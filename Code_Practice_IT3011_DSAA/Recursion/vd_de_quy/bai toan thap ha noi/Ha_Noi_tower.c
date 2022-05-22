// Y tuong: 3 cot A, B, C. Chuyen n dia tu cot A sang cot C voi B la cot trung gian.
// Thuc hien lap lai de quy cac buoc:
// + chuyen n-1 dia tu A sang B voi C la cot trung gian. (giai bai toan hanoitower voi n-1 dia)
// + chuyen 1 dia con lai (la dia lon nhat) tu A sang C.
// + chuyen n-1 dia tu B sang C voi A la cot trung gian. (giai bai toan hanoitower voi n-1 dia)

// cach 1:

// #include<stdio.h>
// void TOH(int n,char x,char y,char z) {
//    if(n>0) { // dieu kien nay can het!!!
//       TOH(n-1,x,z,y);
//       printf("\n%c to %c",x,y);
//       TOH(n-1,z,y,x);
//    }
// }
// int main() {
//    int n=3;
//    TOH(n,'A','B','C');
// }


// cach 2:
#include <stdio.h> 

void HanoiTower(int n, char a, char b, char c) { // a la start,  c la finish, b la cot trung gian
   // buoc neo de quy
   if (n == 1) {
      printf("\n%c to %c", a, c);
   }
   else {
      HanoiTower(n-1,a,c,b);
      HanoiTower(1,a,b,c);
      HanoiTower(n-1,b,a,c);d
   }
}

int main() {
   int n = 4;
   char a = 'A', b = 'B', c = 'C';
   HanoiTower(n, a, b, c);
}