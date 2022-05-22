#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef double element_type;
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
        printf("%c\n", temp_node->value);
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


int checkOp(char op) {
    if (op == '+' || op == '-' || op == '*') return 1;
    else return 0;
}

double doOp(double a, double b, char op) {
    double ans;
    switch (op)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = a / b;
        break;
    }
    return ans;
}

double result(char str[10], Stack *s) {
    char *ptr;
    double first, second, c;
    ptr = strtok(str, " ");

    while (ptr) {
        if (checkOp(*ptr)) {
            second = pop(s); first = pop(s);
            c = doOp(first, second, *ptr);
            push(s, c);
        }
        else {
            c = atof(ptr); push(s, c);
        }
        //printf("%lf", c);
        // printf("%s\n", ptr);
        ptr = strtok(NULL, " ");

    }
    return pop(s);
}

int main() {
    Stack *s = makeNewStack();
    // du lieu dau vao la 1 chuoi bieu thuc hau to, giua cac phan tu co 1 dau cach
    char post_fix[30] = "7 11 - 2 * 3 + ";
    printf("%lf", result(post_fix, s));
}

