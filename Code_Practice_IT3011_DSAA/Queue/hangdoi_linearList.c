#include <stdio.h>
#include <stdlib.h>

typedef int elementype;
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
    // truong hop q ban dau rong
    if (q->front == NULL) { 
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
    // dequeue khi queue chi con 1 ptu, gan rear la NULL luon
    if (q->front == NULL) q->rear = NULL;
    free(temp_node);
    return delete_item;
}

void print(queue *q) {
    if (q->rear == NULL) {
        printf("Queue is empty! Cannot dequeue!");
        return NULL;
    }
    for (node *i = q->front; i != NULL; i = i->next) {
        printf("%d ", i->element);
    }
}

int main() {
    queue *q = makeNewQueue();
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);

    printf("Dequeue element: %d\n", deQueue(q));

    deQueue(q);
    deQueue(q);
    enQueue(q,4);
    enQueue(q,5);
    print(q);
}