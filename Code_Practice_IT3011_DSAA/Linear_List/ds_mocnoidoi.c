#include <stdio.h>
#include <stdlib.h>

typedef int element_type;
typedef struct NodeType {
    element_type inf;
    struct NodeType *next;
    struct NodeType *prev;
} dlist;

dlist *head = NULL, *tail = NULL; // khai bao bien toan cuc

void Insert_Tail(element_type x) {
    dlist *temp_node = (dlist*)malloc(sizeof(dlist));
    temp_node->inf = x;

    if (head == NULL) {
        head = temp_node;
        temp_node->prev = NULL;
    }
    else {
        tail->next = temp_node;
        temp_node->prev = tail;
    }
    tail = temp_node;
    temp_node->next = NULL;
}

void Insert_After(element_type x, dlist *after) {
    dlist *temp_node = (dlist*)malloc(sizeof(dlist));
    temp_node->inf = x;

    if (after->next == NULL) tail = temp_node;
    
    else after->next->prev = temp_node;
    
    temp_node->next = after->next;
    temp_node->prev = after;
    after->next = temp_node;
}

// xoa o tro boi temp_node
void Remove(dlist *temp_node) {
    if (temp_node->next == NULL && temp_node->prev == NULL) {
        head = NULL;
        tail = NULL;
    }
    else if (temp_node->next == NULL) {
        tail = temp_node->prev;
        tail->next = NULL;
    }
    else if (temp_node->prev == NULL) {
        head = temp_node->next;
        head->prev = NULL;
    }
    else {
        temp_node->next->prev = temp_node->prev;
        temp_node->prev->next = temp_node->next;
    }
    free(temp_node);
}

int sum(dlist *p) {
    dlist *temp_to_head = p, *temp_to_tail = p->next;
    int sum = 0;
    while (temp_to_head != NULL)
    {
        sum += temp_to_head->inf;
        temp_to_head = temp_to_head->prev;
    }
    while (temp_to_tail != NULL)
    {
        sum += temp_to_tail->inf;
        temp_to_tail = temp_to_tail->next;
    }
    return sum;
    
}

int main() {
    dlist *node;
    for (int i = 0; i <= 5; i++) 
        Insert_Tail(i);
    
    Insert_After(-1, head);
    Insert_After(6, tail);
    // print the dll list forward
    printf("Traverse the dll list forward \n");
    // for (node = head; node; node = node->next) 
    //     printf("%d ", node->inf);

    node = head;
    while (node != NULL) {
        printf("%d ", node->inf);
        node = node->next;
    }

    // print the dll list backward
    printf("\nTranverse the dll list backward \n");
    for (node = tail; node; node = node->prev)
        printf("%d ", node->inf);    
    printf("\n");
    // while (head != NULL) 
    //     Remove(head);
    // if (head == NULL && tail == NULL) printf("\nDanh sach da bi xoa\n");

    printf("%d", sum(head->next->next));
}