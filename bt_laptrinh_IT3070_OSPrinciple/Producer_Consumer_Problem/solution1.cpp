// code mo phong ko su dung win32api

// // #include <stdio.h>

// // #define BUFFER_SIZE 10

// // int main() {
// //     int IN = 0;
// //     int OUT = 0;
// //     int Counter = 0;
// //     int buffer[BUFFER_SIZE];

// //     while (1) {

// //     }
// // }

// #include<stdio.h>
// #include<stdlib.h>
 
// int mutex=1,full=0,empty=3,x=0;
 
// int main()
// {
// 	int n;
// 	void producer();
// 	void consumer();
// 	int wait(int);
// 	int signal(int);
// 	printf("\n1.Producer\n2.Consumer\n3.Exit");
// 	while(1)
// 	{
// 		printf("\nEnter your choice:");
// 		scanf("%d",&n);
// 		switch(n)
// 		{
// 			case 1:	if((mutex==1)&&(empty!=0))
// 						producer();
// 					else
// 						printf("Buffer is full!!");
// 					break;
// 			case 2:	if((mutex==1)&&(full!=0))
// 						consumer();
// 					else
// 						printf("Buffer is empty!!");
// 					break;
// 			case 3:
// 					exit(0);
// 					break;
// 		}
// 	}
	
// 	return 0;
// }
 
// int wait(int s)
// {
// 	return (--s);
// }
 
// int signal(int s)
// {
// 	return(++s);
// }
 
// void producer()
// {
// 	mutex=wait(mutex);
// 	full=signal(full);
// 	empty=wait(empty);
// 	x++;
// 	printf("\nProducer produces the item %d",x);
// 	mutex=signal(mutex);
// }
 
// void consumer()
// {
// 	mutex=wait(mutex);
// 	full=wait(full);
// 	empty=signal(empty);
// 	printf("\nConsumer consumes item %d",x);
// 	x--;
// 	mutex=signal(mutex);
// }

// #include <stdio.h>
// #include <stdlib.h>
 
// int temp = 0, overflow = 0, mutex = 1, underflow = 10;
 
// int wait_protocol(int counter)
// {
//       return (--counter);
// }
 
// int signal_protocol(int counter)
// {
//       return(++counter);
// }
 
// void producer()
// {
//       mutex = wait_protocol(mutex);
//       overflow = signal_protocol(overflow);
//       underflow = wait_protocol(underflow);
//       temp++;
//       printf("\nProducer:\t Element %d\n", temp);
//       mutex = signal_protocol(mutex);
// }
 
// void consumer()
// {
//       mutex = wait_protocol(mutex);
//       overflow = wait_protocol(overflow);
//       underflow = signal_protocol(underflow);
//       printf("\nConsumer:\t Element %d\n", temp);
//       temp--;
//       mutex = signal_protocol(mutex);
// }
 
// int main()
// {
//       int choice;
//       printf("\n1.Producer\t");
//       printf("2. Consumer\t");
//       printf("3. Quit\t");
//       while(1)
//       {
//             printf("\nEnter your choice:\t");
//             scanf("%d", &choice);
//             switch(choice)
//             {
//                   case 1: if((mutex == 1) && (underflow != 0))
//                           {
//                                 producer();
//                           }
//                           else
//                           {
//                                 printf("Buffer Overflow\n");
//                           }
//                           break;
//                   case 2: if((mutex == 1) && (overflow != 0))
//                           {
//                                 consumer();
//                           }
//                           else
//                           {
//                                 printf("Buffer Underflow\n");
//                           }
//                           break;
//                   case 3: exit(0);
//                           break;
//             }
//       }
//       return 0;
// }





// su dung win32 api 
// sol1: dung 1 bien mutex

#include <iostream>
#include <windows.h>
#include <mutex>
#include <time.h>


#define BUFFER_SIZE 2

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int counter = 0; // tai nguyen gang

HANDLE mutex = CreateSemaphore(NULL, 0, 1, NULL); // binary semaphore 

DWORD WINAPI CONSUMER(LPVOID);
DWORD WINAPI PRODUCER(LPVOID);

int main() {
    DWORD ThreadId;
    HANDLE producer = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PRODUCER, NULL, 0, &ThreadId);
    HANDLE consumer = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CONSUMER, NULL, 0, &ThreadId);

    WaitForSingleObject(producer, INFINITE);
    WaitForSingleObject(consumer, INFINITE);

    system("pause");
    return 0;

}

DWORD WINAPI PRODUCER(LPVOID lpParameter) {
    srand(time(NULL));
    while (1) {
        if (counter == BUFFER_SIZE) 
            WaitForSingleObject(mutex, INFINITE);
        
        int nextProduced = rand() % 100;
        buffer[in] = nextProduced;
        printf("Produce : %d at %d\n", nextProduced, in);
        in = (in + 1) % BUFFER_SIZE;
        
        counter++;

        if (counter == 1) 
            ReleaseSemaphore(mutex, 1, NULL);
    }
    return 0;
}


DWORD WINAPI CONSUMER(LPVOID lpParameter) {
    while (1) {
        if (counter == 0) 
            WaitForSingleObject(mutex, INFINITE);
        
        int nextConsumed = buffer[out];
        printf("Consume : %d at %d\n", nextConsumed, out);
        out = (out + 1) % BUFFER_SIZE;
        
        counter--;
        
        ReleaseSemaphore(mutex, 1, NULL);
    }
    return 0;
}