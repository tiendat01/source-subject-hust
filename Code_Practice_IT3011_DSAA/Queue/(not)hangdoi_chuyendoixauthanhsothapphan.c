#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char elementype;
typedef struct _node {
    elementype element;
    struct _node *next;
} node;
// boc 2 con tro front va rear
typedef struct {
    node *front;
    node *rear;
} queue;

queue *makeNewQueue() {
    queue *q = (queue*)malloc(sizeof(queue));
    if (q == NULL) return NULL;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(queue *q) {
    if (q == NULL || q->front == NULL) return 1;
    return 0;
}

void enQueue(queue *q, elementype x) { // giong ham InserToLast cua ds noi don!!!
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) return ;
    new_node->element = x;
    new_node->next = NULL;
    if (q->rear == NULL) { 
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

elementype deQueue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty! Cannot dequeue!");
        return NULL;
    }
    elementype delete_item;
    node *temp_node = q->front;

    delete_item = q->front->element;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL; // dequeue khi queue chi con 1 ptu, gan rear la NULL luon
    free(temp_node);
    return delete_item;
}

void print(queue *q) {
    if (q->rear == NULL) {
        printf("Queue is empty! Cannot dequeue!");
        return NULL;
    }
    for (node *i = q->front; i != NULL; i = i->next) {
        printf("%c", i->element);
    }
}

int main() {
    queue *q = makeNewQueue();
    char xau_chu_so[30];
    printf("Nhap xau:");
    gets(xau_chu_so);
    for (int i = 0; i < strlen(xau_chu_so); i++) {
        enQueue(q, xau_chu_so[i]);
    }

}