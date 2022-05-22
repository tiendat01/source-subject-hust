#include<windows.h>
#include<iostream>

#define QUEUE_LENGTH 5 // buffer length

HANDLE full_sem; // full semaphore
HANDLE empty_sem; // null semaphore

DWORD WINAPI CONSUMER(LPVOID);
DWORD WINAPI PRODUCER(LPVOID);

struct Msg
{
	int i;
}; // Message Structure

Msg MsgQueue[QUEUE_LENGTH]; // Buffer
int head = 0; // queue head
int tail = 0; // end of the queue

DWORD WINAPI CONSUMER(LPVOID lpParameter) {// consumer thread
	for (int i = 0;; i++) {

		WaitForSingleObject(full_sem, INFINITE); // wait operation

		//std::cout << "CONSUMER : " << MsgQueue[head].i << " at " << head << std::endl;
		printf("CONSUMER : %d at %d\n", MsgQueue[head].i, head);
		head = (head + 1) % QUEUE_LENGTH;

		ReleaseSemaphore(empty_sem, 1, NULL); // signal operation
	}

	return 0;
}
DWORD WINAPI PRODUCER(LPVOID lpParameter) {// producer thread
	for (int i = 0;; i++) {
		WaitForSingleObject(empty_sem, INFINITE);

		MsgQueue[tail].i = i;
		printf("PRODUCER : %d at %d\n", MsgQueue[tail].i, tail);
		//std::cout << "PRODUCER : " << i << " at " << tail << std::endl;
		tail = (tail + 1) % QUEUE_LENGTH;
		ReleaseSemaphore(full_sem, 1, NULL);
	}

	return 0;
}
int main() {

	full_sem = CreateSemaphore(NULL, 0, QUEUE_LENGTH, NULL); // Create the semaphore initial value of 0 and a maximum QUEUE_LENGTH
	empty_sem = CreateSemaphore(NULL, QUEUE_LENGTH, QUEUE_LENGTH, NULL);
	DWORD pro_id;//pid
	DWORD con_id;
	HANDLE producer = CreateThread(NULL, 0, PRODUCER, NULL, 0, &pro_id); // create a thread
	// Sleep (1000); // show clogging

	HANDLE consumer = CreateThread(NULL, 0, CONSUMER, NULL, 0, &con_id);
	
	WaitForSingleObject(producer, INFINITE);
	WaitForSingleObject(consumer, INFINITE); // wait for the thread to complete the run
	
	CloseHandle(producer);
	CloseHandle(consumer); // Close kernel object

    CloseHandle(full_sem);
    CloseHandle(empty_sem);

    system("pause");
    return 0;

}