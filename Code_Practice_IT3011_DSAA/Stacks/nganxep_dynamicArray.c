#include <stdio.h>
#include <stdlib.h>

typedef int elementype;
typedef struct Ngan_Xep {
    int top;
    unsigned capacity;
    elementype *array;
} Stack;

Stack *Create_Stack(unsigned capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (elementype*)malloc(stack->capacity * sizeof(elementype));
    return stack;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void Push(Stack *stack, elementype x) {
    if (isFull(stack) == 1) printf("Stack is full. Cannot push any elements!");
    stack->array[++stack->top] = x;
    printf("%d pushed to stack\n", x);
}

void Pop(Stack *stack) {
    if (isEmpty(stack)) printf("Stack is empty. Cannot pop any elements!");
    printf("%d poped from stack\n", stack->array[stack->top]);
    stack->top--;
}

int Top(Stack *stack) {
    if (isEmpty(stack) == 1) return -1;
    return stack->array[stack->top];
}

int Size(Stack *stack) {
    return ++stack->top;
}

void Print(Stack *stack) {
    if (isEmpty(stack)) printf("Stack is empty.");
    else {
        printf("Stack: \n");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->array[i]);
        }
    }
}
int main() {
    Stack *stack = Create_Stack(100);
    Push(stack, 14);
    Push(stack, 25);
    Push(stack, 38);
    Push(stack, 48);

    Pop(stack);

    Print(stack);

    printf("Top item is %d\n", Top(stack));
 
    return 0;
}