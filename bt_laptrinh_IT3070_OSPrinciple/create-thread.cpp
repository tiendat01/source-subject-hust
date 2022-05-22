#include <windows.h>
#include <iostream>

DWORD WINAPI Routine(LPVOID);

int main() {
    int params[5] = { 0, 1, 2, 3, 4 };
    DWORD ThreadId; // name of thread
    HANDLE thread[5];
    // create Thread:
    for (int i = 0; i < 5; i++) {
        thread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Routine, &params[i], 0, &ThreadId);
        printf("Thread named : %d was created\n", ThreadId);
    }
    for (int i = 0; i < 5; i++) 
        WaitForSingleObject(thread[i], INFINITE); // doi cho thread hoan thanh xog cong viec.

    return 0;
}

DWORD WINAPI Routine(LPVOID lpParameter) {
    while (1)
        printf("My argument is %d\n", *((int*)lpParameter));
}