#include <stdio.h>
#include <stdlib.h>

typedef int element_type;
typedef struct NodeType {
    element_type value;
    struct NodeType *next;
} StackNode;
typedef struct _Stack {
    StackNode *top;
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
    StackNode *temp_node = s->top;
    while (temp_node != NULL) {
        printf("%d %p\n", temp_node->value, temp_node->next);
        temp_node = temp_node->next;
    } 
}

int stackSize(Stack *s) {
    if (s == NULL) return 0;
    if (s->top == NULL) return 0;
    StackNode *temp_node = s->top; int count = 0;
    while (temp_node != NULL) {
        count++;
        temp_node = temp_node->next;
    }
    return count;
}

// inssert to head
void push(Stack *s, element_type x) {
    if (s == NULL) printf("NO MEMORY! Cannot push anything."); 
    StackNode *new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node == NULL) printf("NO MEMORY for new elements! Cannot push into stack.");
    new_node->value = x;
    new_node->next = s->top;
    s->top = new_node;
}

// delete head
element_type pop(Stack *s) {
    if (isEmpty(s) == 1) {
        printf("Stack is empty! Cannot pop anything.");
        return 0;
    }
    StackNode *temp_node = s->top;
    element_type x = temp_node->value;
    s->top = s->top->next;
    free(temp_node);
    return x;
}

int main()
{
	printf("Tao ngan xep:\n");
	Stack *s = makeNewStack();
	printf("Chen 10\n");
	printf("Chen 12\n");
	printf("Chen 15\n");
	push(s,10);
	push(s,12);
	push(s,15);
	printf("So phan tu trong ngan xep:%d\n",stackSize(s));
	printf("Lay cac phan tu ra:\n");
    pop(s);
	// while(!isEmpty(s))
	// 	printf("%d ",pop(s));
    duyetStack(s);
	printf("\n");
	return 1;
}