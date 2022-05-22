#include <windows.h>
#include <stdio.h>
 
#define BUFFER 100
 
char buffer[BUFFER];
HANDLE sem_consumer, sem_producer;
DWORD WINAPI Thread_Consumer( LPVOID );
DWORD WINAPI Thread_Producer( LPVOID );
 
int main( void )
{
    
 
    sem_consumer = CreateSemaphore( NULL, 0, BUFFER, NULL);
    sem_producer = CreateSemaphore( NULL, BUFFER, BUFFER, NULL);
 
    HANDLE consumer, producer;
    DWORD tid_consumber, tid_producer;
    
    consumer = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) Thread_Consumer, NULL, 0, &tid_consumber);
    producer = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) Thread_Producer, NULL, 0, &tid_producer);
 
    WaitForSingleObject(consumer, INFINITE);
    WaitForSingleObject(producer, INFINITE);
 
    CloseHandle(consumer);
    CloseHandle(producer);
 
    CloseHandle(sem_consumer);
    CloseHandle(sem_producer);
 
    system("pause");
    return 0;
}
 
DWORD WINAPI Thread_Producer( LPVOID lpParam )
{
    int index = 0;
    while(true)
    {
        DWORD dwWaitResult = WaitForSingleObject(sem_producer, INFINITE);
        if (dwWaitResult == WAIT_OBJECT_0)
        {
            buffer[index] = '@';
            printf("Produce a %c at %d\n", buffer[index], index);
            index = (index+1)%BUFFER;
 
            if (!ReleaseSemaphore(sem_consumer, 1, NULL))
                printf("ReleaseSemaphore error: %d\n", GetLastError());
        }
    }
    return TRUE;
}
 
DWORD WINAPI Thread_Consumer( LPVOID lpParam )
{
    int index = 0;
    while(true)
    {
        DWORD dwWaitResult = WaitForSingleObject(sem_consumer, INFINITE);
        if (dwWaitResult == WAIT_OBJECT_0)
        {
            printf("Consume a %c at %d\n", buffer[index], index);
            index = (index+1)%BUFFER;
 
            if (!ReleaseSemaphore(sem_producer, 1, NULL))
                printf("ReleaseSemaphore error: %d\n", GetLastError());
        }
    }
    return TRUE;
}