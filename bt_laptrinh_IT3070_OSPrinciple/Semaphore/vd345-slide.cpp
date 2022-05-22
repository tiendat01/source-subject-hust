#include <windows.h>
#include <iostream>

HANDLE S1, S2;

DWORD WINAPI T1(LPVOID);
DWORD WINAPI T2(LPVOID);

// tai nguyen gang:
int x = 0;
int y = 1;

int main() {
    // tao semaphore:
    S1 = CreateSemaphore(NULL, 0, 1, NULL); // khoi tao semaphore = 0
    S2 = CreateSemaphore(NULL, 0, 1, NULL); // khoi tao semaphore = 0

    // tao thread:
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
        WaitForSingleObject(S1, INFINITE); // block
        x = y + 1;
        ReleaseSemaphore(S2, 1, NULL);
        printf("%4d", x);
    }
}

DWORD WINAPI T2(LPVOID lpParameter) {
    while (1) {
        y = 2;
        ReleaseSemaphore(S1, 1, NULL); // vao doan gang
        WaitForSingleObject(S2, INFINITE);
        y = 2 * y;
    }
}