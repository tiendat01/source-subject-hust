#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stack

typedef char elementype;
typedef struct _node {
    elementype element;
    struct _node *next;
} node;
typedef struct _Stack {
    node *top;
} Stack;

Stack *makeNewStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) return NULL; // het bo nho ko the malloc cho s
    s->top = NULL;
    return s;
}

// Khi cai dat ngan xep bang ds lienket, chi khi het bo nho thi ngan xep moi full
int isFull(Stack *s) {

}

int isEmpty(Stack *s) {
    if (s == NULL) return 1;
    if (s->top == NULL) return 1;
    return 0;
}

void duyetStack(Stack *s) {
    node *temp_node = s->top;
    while (temp_node != NULL) {
        printf("%c %p\n", temp_node->element, temp_node->next);
        temp_node = temp_node->next;
    } 
}

int stackSize(Stack *s) {
    if (s == NULL) return 0;
    if (s->top == NULL) return 0;
    node *temp_node = s->top; int count = 0;
    while (temp_node != NULL) {
        count++;
        temp_node = temp_node->next;
    }
    return count;
}

void push(Stack *s, elementype x) {
    if (s == NULL) printf("NO MEMORY! Cannot push anything."); 
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) printf("NO MEMORY for new elements! Cannot push into stack.");
    new_node->element = x;
    new_node->next = s->top;
    s->top = new_node;
}

elementype pop(Stack *s) {
    if (isEmpty(s) == 1) {
        printf("Stack is empty! Cannot pop anything.");
        return 0;
    }
    node *temp_node = s->top;
    elementype x = temp_node->element;
    s->top = temp_node->next;
    free(temp_node);
    return x;
}

// Queue


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

int isEmptyQ(queue *q) {
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
        printf("%c ", i->element);
    }
}



int main()
{
    Stack *s = makeNewStack();
    queue *q = makeNewQueue();

    char xau[50];
    printf("Nhap xau:");
    gets(xau);

    for (int i = 0; i < strlen(xau); i++)
    {
        push(s, xau[i]);
        enQueue(q, xau[i]);
    }

    // duyetStack(s);
    // printf("\n");
    // print(q);

    int check = 1;
    elementype element_pop, element_dequeue;
    node *i, *j;
    i = q->front;
    j = s->top;

    while (i != NULL && j != NULL) {
        element_pop = pop(s);
        element_dequeue = deQueue(q);
        if (element_pop != element_dequeue) {
            check = 0;
            break;
        } 
        // sau khi pop va Dequeue thi q->front va s->top da tien len 1 nut 
        i = q->front;
        j = s->top;
    }
     printf("\n%d\n", check);
    
}