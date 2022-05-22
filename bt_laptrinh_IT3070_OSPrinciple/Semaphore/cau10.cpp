// 2 TT T1 va T2 cung thuc hien 1 cv: 
//  while(1):
        // x = x + 1;
        // if (x == 20) x = 0;
// tai nguyen gang la x
// neu ko dieu do x co the vuot qua 21

// dung 1 semaphore S1 de dieu do

#include <windows.h>
#include <iostream>
#include <stdint.h>

int x = 0;

DWORD WINAPI T1(LPVOID);
DWORD WINAPI T2(LPVOID);

HANDLE S1, S2;

int main() {
    S1 = CreateSemaphore(NULL, 1, INT_MAX, NULL);
    // S2 = CreateSemaphore(NULL, 1, INT_MAX, NULL);   

    HANDLE thread1, thread2;
    DWORD ThreadId;
    thread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)T1, NULL, 0, &ThreadId);
    thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)T2, NULL, 0, &ThreadId);

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    return 0;
}

DWORD WINAPI T1(LPVOID lpParameter) {
    do {
        WaitForSingleObject(S1, INFINITE);
        x = x + 1;
        if (x == 20) x = 0;
        
        ReleaseSemaphore(S1, 1, NULL);

        if (x > 20) printf("%4d sai\n", x);
        else printf("dung\n");

        
    } while (1);
}

DWORD WINAPI T2(LPVOID lpParameter) {
    do {
        WaitForSingleObject(S1, INFINITE);

        x = x + 1;
        if (x == 20) x = 0;
        ReleaseSemaphore(S1, 1, NULL);

        if (x > 20) printf("%4d sai\n", x);
        else printf("dung\n");
        
    } while (1);   
}