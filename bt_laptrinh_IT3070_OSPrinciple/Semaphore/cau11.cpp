/*
Cau11: 2 TT:
process T1 {A1, A2}
process T2 {B1, B2}
Dong bo hoa s/c A1 va B1 thuc hien truoc khi A2, B2 bat dau
*/

#include <windows.h>
#include <iostream>
#include <stdint.h>

int x = 0, y = 0, z = 0, t = 0;

DWORD WINAPI T1(LPVOID);
DWORD WINAPI T2(LPVOID);

HANDLE S1, S2;

int main() {
    S1 = CreateSemaphore(NULL, 0, INT_MAX, NULL);
    S2 = CreateSemaphore(NULL, 0, INT_MAX, NULL);   

    HANDLE thread1, thread2;
    DWORD ThreadId;
    thread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)T1, NULL, 0, &ThreadId);
    thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)T2, NULL, 0, &ThreadId);

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    return 0;
}

DWORD WINAPI T1(LPVOID) {
    while(1) {
        x = 1;
        t = 4;
        ReleaseSemaphore(S2, 1, NULL);
        WaitForSingleObject(S1, INFINITE);
        x = x + y; 
        printf("%4d", x); 
    }
    return 0;
}


DWORD WINAPI T2(LPVOID) {
    while(1) {
        y = 2;
        z = 3;
        ReleaseSemaphore(S1, 1, NULL);
        WaitForSingleObject(S2, INFINITE);
        z = z + t;
        printf("%4d", z);
        
    }
    return 0;
}