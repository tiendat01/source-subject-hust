#include <iostream>

 //Cộng hai ma trận
	 void MultiMatrix(int *A,int *B,int*C,int M_A,int N_A, int M_B, int N_B)
	 {
		 if (N_A != M_B) {
             printf("2 ma tran ko thoa man dieu kien de nhan!");
             return;
         }
         else {
            for (int i = 0; i < M_A; i++) {
                for (int j = 0; j < N_B; j++) {
                    int tmp = 0;
                    for (int k = 0; k < N_A; k++) tmp += A[i*N_A+k] * B[k*N_B+j];
                    C[i*N_B+j] = tmp;
                }
            }
         }
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
	 int M_A,N_A,M_B,N_B;
	 int *A = NULL,*B = NULL,*C = NULL;
	 printf("\n Nhap so dong cua ma tran A: "); scanf("%d",&M_A);
	 printf("\n Nhap so cot cua ma tran A: "); 	 scanf("%d",&N_A);
     printf("\n Nhap so dong cua ma tran B: "); scanf("%d",&M_B);
	 printf("\n Nhap so cot cua ma tran B: "); 	 scanf("%d",&N_B);
 	//Cấp phát vùng nhớ cho ma trận A
	 if (!AllocMatrix(&A,M_A,N_A))
	 {
		 printf("\n Khong con du bo nho! ");
		 return 1;
	 }
	//Cấp phát vùng nhớ cho ma trận B
	 if (!AllocMatrix(&B,M_B,N_B))
	 {
		 printf("\n Khong con du bo nho! ");
		 FreeMatrix(A);//Giải phóng vùng nhớ A
		 return 1;
	 }

    //Cấp phát vùng nhớ cho ma trận C
	 if (!AllocMatrix(&C,M_A,N_B))
	 {
		 printf("\n Khong con du bo nho! ");
		 FreeMatrix(A);//Giải phóng vùng nhớ A
		 FreeMatrix(B);//Giải phóng vùng nhớ B
		 return 1;
	 }


	 printf("\n Nhap ma tran thu 1 ");
	 InputMatrix(A,M_A,N_A,'A');
	 printf("\n Nhap ma tran thu 2 ");
	 InputMatrix(B,M_B,N_B,'B');
        printf("\n Ma tran thu 1\n");
	 DisplayMatrix(A,M_A,N_A);
	 printf("\n Ma tran thu 2\n");
	 DisplayMatrix(B,M_B,N_B);
	 MultiMatrix(A,B,C,M_A,N_A,M_B,N_B);
	 printf("\n Tong hai ma tran\n");
	 DisplayMatrix(C,M_A,N_B);
	 FreeMatrix(A);//Giải phóng vùng nhớ A
	 FreeMatrix(B);//Giải phóng vùng nhớ B
	 FreeMatrix(C);//Giải phóng vùng nhớ C
	 return 0;
 }