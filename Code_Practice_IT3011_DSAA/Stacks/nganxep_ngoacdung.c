#include <stdio.h>
#include <stdlib.h>

typedef char element_type;
typedef struct LinearList {
    element_type Inf;
    struct LinearList *next;
} StackNode;
typedef struct _Stack {
    StackNode *top;
} Stack;

Stack *makeNewStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) return NULL;
    s->top = NULL;
    return s;
}

int isEmpty(Stack *s) {
    if (s == NULL || s->top == NULL) return 1;
    else return 0;
}

void duyetStack(Stack *s) {
    if (isEmpty(s)) {printf("Stack empty");}
    else {
        StackNode *temp_node = s->top;
        while (temp_node != NULL) {
            printf("%c\n", temp_node->Inf);
            temp_node = temp_node->next;
        }
    }   
}

int stackSize(Stack *s) {
    if(isEmpty(s)) return 0;
    else {
        StackNode *temp_node = s->top;
        int count = 0;
        while (temp_node != NULL) {
            temp_node = temp_node->next;
            count++;
        }
        return count;
    }
}

void push(Stack *s, element_type c) {
    StackNode *new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node == NULL) printf("NO MEMORY for new elements! Cannot push into stack.");
    new_node->Inf = c;
    new_node->next = s->top;
    s->top = new_node;
}

element_type pop(Stack *s) {
    if (isEmpty(s)) return ' ';

    element_type x;
    x = s->top->Inf;
    StackNode *temp_node = s->top;
    s->top = temp_node->next;
    free(temp_node);
    return x;
}

int checkParenMatching(char s1, char s2) {
    if(s1=='('&&s2==')')
		return 1;
	if(s1=='{'&&s2=='}')
		return 1;
	if(s1=='['&&s2==']')
		return 1;
		
	return 0;
}

int ParenthesesMatching(char xau[100], int n, Stack *s) {
    char x;
    if (!isEmpty(s)) return 0; // stack ban dau phai rong 
    for (int i = 0; i < n; i++) {
        if (xau[i] == '(' || xau[i] == '[' || xau[i] == '{') push(s, xau[i]);
        else {
            if (isEmpty(s)) return 0; // )(()){[()]}

            x = pop(s);
            if (checkParenMatching(x, xau[i]) == 0) return 0; // ({[])}
        }
    }
    if (isEmpty(s)) return 1;
    else return 0; // ()[](
}


int main() {
    int n = 6;
    char xau[100] = {'(', ')', '[', ']', '{', ')'};
    Stack *s = makeNewStack();
    printf("\n1 la dung 0 la sai \n%d", ParenthesesMatching(xau, n, s));
}


