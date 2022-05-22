#include <windows.h>
#include <stdio.h>

int x = 0;
int y = 0;
HANDLE S1, S2;
void T1();
void T2();
int main(){
     HANDLE h1, h2;
     DWORD ThreadId;

    S1 = CreateSemaphore( NULL,0,1, NULL);
    S2 = CreateSemaphore( NULL,4,4, NULL);
    h1 = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)T1, NULL, 0, &ThreadId);
    h1 = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)T2, NULL, 0, &ThreadId);
    WaitForSingleObject(h1, INFINITE);
    WaitForSingleObject(h2, INFINITE);

//     getch();
     return 0;
}
void T1(){
     while(1)
     {
     		//printf("T1");
          WaitForSingleObject(S2, INFINITE);
          x = x + 1;     
          //printf("X++");
          ReleaseSemaphore(S1, 1, NULL);
          //if(x<y||x>=y+5)
          if(x-y==4)
          	printf("%5d",x-y);
          
     }
}
void T2(){
     while(1)
     {
     	//printf("T2");
     	WaitForSingleObject(S1, INFINITE);
        y = y + 1;    
		//printf("Y++"); 
        ReleaseSemaphore(S2, 1, NULL);
          //y = y * 2;
     }
}
