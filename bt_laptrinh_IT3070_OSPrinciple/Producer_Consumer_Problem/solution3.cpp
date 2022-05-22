/*
 * An example of the bounded buffer (producer/consumer) problem based on threads
 * created using the Win32 API.
 * using 3 semaphore: mutex, full <-> element, empty <-> space
 * khi co nhieu TT cung loai, o day, lay 5 tien trinh: 3 produce va 2 consume
 */


#include <windows.h>
#include <process.h>
#include <iostream>
#include <time.h>
using namespace std;


#define NUM_THREADS	5
#define	BUF_SIZE	10


// Function Prototypes

DWORD WINAPI Producer(LPVOID param);
DWORD WINAPI Consumer(LPVOID param);


// Global Semaphores

HANDLE	mutex = CreateSemaphore(0, 1, 1, 0);			// mutual exclusion (binary)
HANDLE	space = CreateSemaphore(0, BUF_SIZE, BUF_SIZE, 0);	// space available in buffer
HANDLE	element = CreateSemaphore(0, 0, BUF_SIZE, 0);		// element avalable in buffer


// Global buffer variables
int	buffer[BUF_SIZE];
int	front = 0;
int	back = 0;


int main()
{
	DWORD	ThreadId;
	HANDLE	threads[NUM_THREADS];
	int	params[] = { 0, 1, 2, 3, 4 };

	// create and start threads

	for (int i = 0; i < 3; i++)
		threads[i] = CreateThread(0, 0, Producer, &params[i], 0, &ThreadId);
	for (int i = 3; i < 5; i++)
		threads[i] = CreateThread(0, 0, Consumer, &params[i], 0, &ThreadId);


	// wait for child threads to terminate

	for (int i = 0; i < NUM_THREADS; i++)
		WaitForSingleObject(threads[i], INFINITE);
}



DWORD WINAPI Producer(LPVOID param)
{
	int	id = * (DWORD *)param;

	srand(time(0) + id);

	for (int i = 0; i < 10; i++)
	{
		int	prod = rand() % 8000;
		// Sleep(prod);
		Sleep(1000);

		// critical section -- see text section 6.2

		WaitForSingleObject(space, INFINITE);
		WaitForSingleObject(mutex, INFINITE);

		buffer[front] = prod;
		front = (front + 1) % BUF_SIZE;
		cout << "producer " << id << " " << prod << endl;

		ReleaseSemaphore(mutex, 1, 0);
		ReleaseSemaphore(element, 1, 0);

		// end critical section
	}

	return 0;
}



DWORD WINAPI Consumer(LPVOID param)
{
	int	id = * (DWORD *)param;

	srand(time(0) + id);

	for (int i = 0; i < 15; i++)
	{
		int	consume;
		// Sleep(rand() % 4000);
		Sleep(1000);

		// critical section -- see section 6.2

		WaitForSingleObject(element, INFINITE);
		WaitForSingleObject(mutex, INFINITE);

		consume = buffer[back];
		back = (back + 1) % BUF_SIZE;

		cout << "consumer " << id << " " << consume << endl;

		ReleaseSemaphore(mutex, 1, 0);
		ReleaseSemaphore(space, 1, 0);

		// end critical section
	}

	return 0;
}