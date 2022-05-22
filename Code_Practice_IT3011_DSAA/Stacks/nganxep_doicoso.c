#include <stdio.h>
#include <stdlib.h>


// cai dat stack
typedef char element_type;
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
        printf("%c", temp_node->value);
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

void push(Stack *s, element_type x) {
    if (s == NULL) printf("NO MEMORY! Cannot push anything."); 
    StackNode *new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node == NULL) printf("NO MEMORY for new elements! Cannot push into stack.");
    new_node->value = x;
    new_node->next = s->top;
    s->top = new_node;
}

element_type pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop anything.");
        return 0;
    }
    StackNode *temp_node = s->top;
    element_type x = temp_node->value;
    s->top = temp_node->next;
    free(temp_node);
    return x;
}

char digitChar[] = "0123456789ABCDEF";
int main() {
	// doi so tu he dem thap phan sang he dem co so b tuong ung
	Stack *s = makeNewStack();
	int n = 3553; // so trong he dem thap phan
	int b = 16; // he co so b tuong ung phai doi
	while (n != 0)
	{
		int element = n % b;
		push(s, digitChar[element]);
		n = n/b;
	}
	duyetStack(s);	
}

