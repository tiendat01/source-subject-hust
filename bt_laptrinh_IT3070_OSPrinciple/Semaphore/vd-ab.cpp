// nb < na <= nb + 10

#include <windows.h>
#include <iostream>
#include <stdint.h>

int na = 0;
int nb = 0;

DWORD WINAPI T1(LPVOID);
DWORD WINAPI T2(LPVOID);

HANDLE S1, S2;

int main() {
    S1 = CreateSemaphore(NULL, 10, INT_MAX, NULL); // khoi tao la 10
    S2 = CreateSemaphore(NULL, 0, 1, NULL);   // khoi tao la 0, 
                                                // gia tri lon nhat < 10 la ok de na luon > nb
                                                // neu chon gia tri lon nhat >= 10 thi na >= nb, nhung ko bao gio na < nb, vi S2 chi len duoc toi da la 10

    HANDLE thread1, thread2;
    DWORD ThreadId;
    thread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)T1, NULL, 0, &ThreadId);
    thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)T2, NULL, 0, &ThreadId);

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    return 0;
}

DWORD WINAPI T1(LPVOID lpParameter) {
    while (1) {
        WaitForSingleObject(S1, INFINITE);
        na = na + 1;
        ReleaseSemaphore(S2, 1, NULL);

        if (na > nb + 10 || na <= nb) 
            printf("a = %d || b = %d sai\n", na, nb);
        else 
            printf("a = %d || b = %d dung, from T1\n", na, nb);
    }
}

DWORD WINAPI T2(LPVOID lpParameter) {
    while (1) {
        WaitForSingleObject(S2, INFINITE);
        nb = nb + 1;
        ReleaseSemaphore(S1, 1, NULL);

        if (na > nb + 10 || na <= nb) 
            printf("a = %d || b = %d sai\n", na, nb);
        else 
            printf("a = %d || b = %d dung, from T2\n", na, nb);
    }

    
}