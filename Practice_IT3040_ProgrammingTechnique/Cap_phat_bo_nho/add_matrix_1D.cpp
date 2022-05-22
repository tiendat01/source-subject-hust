// #include <stdio.h>
// #define hang 3
// #define cot 3
// int main() {
//   int mt[hang][cot] = {{7,8,9},{10,13,15},{2,7,8}};
//   int i,j;
//   for (i=0;i<hang;i++) {
//      for (j=0;j<cot;j++)   printf(" %d ", mt[i][j]);
//      printf("\n");
//    }
//    for (i=0; i<hang;i++) {
//       for (j=0;j<cot;j++)  {
//  		*(*(mt+i)+j)=*(*(mt+i)+j) +10;
// 		 printf(" %d ", *(*(mt+i)+j));    
//         }
//        printf("\n"); 
//     }
//   }




// Cach 1: Bieu dien mang 2 chieu thanh mang 1 chieu
#include <iostream>

 //Cộng hai ma trận
	 void AddMatrix(int *A,int *B,int*C,int M,int N)
	 {
		 for(int I=0;I<M*N;++I)
		 C[I] = A[I] + B[I];
	 }
	 //Cấp phát vùng nhớ cho ma trận
	 int AllocMatrix(int **A,int M,int N)   // chú ý : **
	 {
		 *A = new int [M*N];
		 if (*A == NULL)
		  return 0;
		 return 1;
	 }
	 //Giải phóng vùng nhớ
	 void FreeMatrix(int *A)
	 {
		 if (A!=NULL)
		 delete [] A;
	 }
//Nhập các giá trị của ma trận
	 void InputMatrix(int *A,int M,int N,char Symbol)
	 {
		 for(int I=0;I<M;++I)
		 for(int J=0;J<N;++J)
		{
			 printf("\n  %c [%d][%d] = ",Symbol,I,J);
			scanf("%d",&A[I*N+J]);
		}
	}
	 //Hiển thị ma trận
	 void DisplayMatrix(int *A,int M,int N)
	 {
		 for(int I=0;I<M;++I)
		 {
		       for(int J=0;J<N;++J)
		       	 printf("%7d",A[I*N+J]);
		 printf("\n");
		 }
	 }
 
 
 int main()
 {
	 int M,N;
	 int *A = NULL,*B = NULL,*C = NULL;
	 printf("\n Nhap so dong cua ma tran: "); scanf("%d",&M);
	 printf("\n Nhap so cot cua ma tran: "); 	 scanf("%d",&N);
 	//Cấp phát vùng nhớ cho ma trận A
	 if (!AllocMatrix(&A,M,N))
	 {
		 printf("\n Khong con du bo nho! ");
		 return 1;
	 }
	//Cấp phát vùng nhớ cho ma trận B
	 if (!AllocMatrix(&B,M,N))
	 {
		 printf("\n Khong con du bo nho! ");
		 FreeMatrix(A);//Giải phóng vùng nhớ A
		 return 1;
	 }

    //Cấp phát vùng nhớ cho ma trận C
	 if (!AllocMatrix(&C,M,N))
	 {
		 printf("\n Khong con du bo nho! ");
		 FreeMatrix(A);//Giải phóng vùng nhớ A
		 FreeMatrix(B);//Giải phóng vùng nhớ B
		 return 1;
	 }


	 printf("\n Nhap ma tran thu 1 ");
	 InputMatrix(A,M,N,'A');
	 printf("\n Nhap ma tran thu 2 ");
	 InputMatrix(B,M,N,'B');
        printf("\n Ma tran thu 1\n");
	 DisplayMatrix(A,M,N);
	 printf("\n Ma tran thu 2\n");
	 DisplayMatrix(B,M,N);
	 AddMatrix(A,B,C,M,N);
	 printf("\n Tong hai ma tran\n");
	 DisplayMatrix(C,M,N);
	 FreeMatrix(A);//Giải phóng vùng nhớ A
	 FreeMatrix(B);//Giải phóng vùng nhớ B
	 FreeMatrix(C);//Giải phóng vùng nhớ C
	 return 0;
 }