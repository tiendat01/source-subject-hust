// #include <iostream>
// #include <conio.h>
// using namespace std;
// void doi(int *a, int b){
// *a=b;
// *a+=b++;
// }
// int main()
// { int x,y;
// doi(&x,y=2);
// cout<<x<<" "<<y;
//  getch();
//     return 0;
// }



// #include <iostream>
// #include <conio.h>
// #include <stdio.h>
// using namespace std;

// int main()
// {
//     int a=2, b=4;

//     switch(b){
//     case 5: b+=2;
//     case 2: a--;
//     default: a-b--;
//     }
//     cout<<a<<" " <<b;
//     getch();
//     return 0;
// }


// #include <iostream>

// using namespace std;

// int main()
// {    double m=3.4, *p=&m;
//     double r=5.6, *q=&r;
//     double *&v=q;
//     cout<<*p<<' '<<*v<<endl;
//     return 0;
// }




// #include <iostream>

// using namespace std;
// double v=12;
// double *pv=&v;
// int f(int *pd)
// {
//     cout<<*pd<<endl;
//     return *pd;
// }
// int main()
// {
//     f((int *)pv);
//     return 0;
// }



// #include <iostream>
// #include <conio.h>
// using namespace std;

// int main()
// {   char name[30] = "Trung Tam Tin Hoc CCS";
//     cout<<name+10;
//     getch();
//     return 0;
// }



// #include <iostream>

// using namespace std;

// int main()
// {   int a=1, b=5;
//     a+=++b+=6;
//     (a>b)? cout<<++a<<" "<<b:cout<<b<<" "<<++a;
//     return 0;
// }



// #include <iostream>

// using namespace std;

// int main()
// {
//    int a=5, b=6, c=7;
//    if(a>b) {
//         if(b<c)
//             c=a;
//         else c=b;
//          }
//         cout<<"c= "<<c<<endl;
//     return 0;
// }


// #include <iostream>
// #include <stdio.h>
// #include <iomanip>
// using namespace std;

// int main()
// {   for(int num=2; num<=60; num+=((num+10)%20==0)?10:2)
//     cout<<num<<" ";
//     cout << endl;
//     return 0;
// }


// int f(unsigned so){
//     cout<<so%10;
//     if(so/10==0) return 0; 
//     else return f(so/10);
// }
// f(456)

// #include <iostream>
// using namespace std;
// void input(int *pi)
// {
//     *pi=1;
//     *(pi+1)=-100;
//     *(pi+2)=5;
//     *(pi+3)=0;
// }
// void f(int *pi, int &m)
// {
//     m=*pi;
//     for(int i=1; i<4; i++)
//         if(m<*(pi+i)) m=*(pi+i);
// }
// int main()
// {   int a[10], x;
//     input(a);
//     f(a,x);
//     std::cout<<x;
//     return 0;
// }


// #include <iostream>
// #define ARRY_SIZE 5

// using namespace std;

// int  main()
// { int values[ARRY_SIZE] = {80, 70, 90, 85, 80};
//   int i;
//   for(i=0; i<ARRY_SIZE; i++)
//     cout<<values[i]<<" ";
//     return 0;
// }


// #include <iostream>
// #include <stdio.h>
// #include <conio.h>
// using namespace std;

// int main()
// {   int i=1, n=0;
//     while (i>n)
//     {
//         while (i<4)
//             i+=2; n++;
//             i-=3;

//     }
//     cout<<i<<" " <<n;
//     getch();
//     return 0;
// }

// #include <iostream>

// using namespace std;

// int main()
// {
//    int a=5, b=6, c=7;
//    if(a>b) {
//         if(b<c)
//             c=a;
//    }
//     else c=b;

//         cout<<"c="<<c<<endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int f(int a[], int n)
// {
//     int flag=1;
//     for(int i=0; i<n/2; i++)
//         if(a[i]!=a[n-i-1])
//     {
//         flag=0;
//         break;
//     }
//     return flag;
// }
// int main()
// {   int a[]={-9,-1,0,3,0,-1,-9};
//     cout<<f(a,7);
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int f1(int x)
//     {
//         int i=2;
//         while (x%i!=0 && x>1)
//             i++;
//         if(i==x) return 1;
//         else return 0;
//     }
// int output(int a[], int n){
//     int t=0;
//     for(int i=0; i<n; i++)
//         if(f1(a[i])==1) t++;
//     return t;
//     }
// int main()
// {
//     int a[]={1,5,-9,0,2,4,3};
//     cout<<output(a,7);
//     return 0;
//     }


// #include <iostream>
// using namespace std;
// int f(int a[], int n)
// {
//     int flag=1;
//     for(int i=0; i<n-1; i++)
//         if(a[i]>a[i+1])
//     {
//         flag=0;
//         break;
//     }
//     return flag;
// }
// int main()
// {   int a[]={-9,-1,0,3,4,10,91};
//     cout<<f(a,7);
//     return 0;
// }

// #include <iostream>
// using namespace std;
// void f(int a[],int &n, int x)
//     {
//         for(int i=0; i<n; i++)
//             if(a[i]==x)
//         {
//             for(int j=i; j<n; j++)
//                 a[j]=a[j+1];
//             i--;
//             n--;
//         }
//     }
// void output(int a[], int n){
//     for(int i=0; i<n; i++)
//         cout<<a[i]<<" ";
//     }
// int main()
// {
//     int a[]={1,3,3,-9,5,3}, n=6;
//     f(a,n,3);
//     output(a,n);
//     return 0;
// }



// #include <iostream>
// #include <stdio.h>
// #include <conio.h>
// #include <ctype.h>
// using namespace std;

// int main()
// {   char s[]="Good Luck";
//     int i;
//     i=0;
//     while(s[i]!=0)
//     {
//         if (isalpha(s[i])) {
//             if(s[i]<97)
//                        s[i]+=32;
//             else
//                        s[i]-=32;
//         }
//         i++;

//     }
//     cout<<s;
//     getch();
//     return 0;
// }


// #include <iostream>
// using namespace std;
// int f(int a[], int n)
// {
//     int flag=1;
//     for(int i=0; i<n-1; i++)
//         if(a[i]<a[i+1])
//     {
//         flag=0;
//         break;
//     }
//     return flag;
// }
// int main()
// {   int a[]={10,9,7,-9,0,-8,1};
//     cout<<f(a,7);
//     return 0;
// }


#include <iostream>
using namespace std;

float f(int a[], int n){
    float t=0.0;
    for(int i=0; i<n; i++)
        t+=a[i];
        t/=n;
    return t;
    }
int main()
{
    int a[]={5,4,6,7}, n=4;
    cout<<f(a,n);
    return 0;
}

