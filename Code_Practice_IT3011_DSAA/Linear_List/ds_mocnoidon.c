#include <stdio.h>
#include <stdlib.h>

typedef int element_type;
typedef struct NodeType {
    element_type Inf;
    struct NodeType *next;
} slist;

// Ham End(L) tra ve con tro tro toi node cuoi cua ds
slist *End(slist *first) {
    slist *node = first;
    while (node->next != NULL) {
        node = node->next;
    }
    return node;
}

// Ham MakeNewNode
slist *MakeNewNode(element_type x) {
    slist *first = NULL;
    first = (slist*)malloc(sizeof(slist));
    // con tro first tro den 1 o gom 2 trg thong tin la Inf va con tro next tro den o tiep theo
    first->Inf = x;
    first->next = NULL;
    return first;
}

// ham duyet qua ds
void DuyetDs(slist *first) {
    slist *temp_node = first;
    while (temp_node != NULL) {
        printf("%d %p\n", temp_node->Inf, temp_node->next);
        temp_node = temp_node->next;
    }
}

slist *Insert_To_Head(element_type x, slist *first) {
    slist *temp_node = (slist*)malloc(sizeof(slist));
    temp_node->Inf = x;
    temp_node->next = first;
    first = temp_node;
    return first;
}

void Insert_To_Middle(element_type x, slist *pred) {
    slist *temp_node = (slist*)malloc(sizeof(slist));
    temp_node->Inf = x;
    temp_node->next = pred->next;
    pred->next = temp_node;
}

void Insert_To_Last(element_type x, slist *first) {
    slist *detect_node = first;
    while (detect_node->next != NULL) {
        detect_node = detect_node->next;
    }
    slist *temp_node = (slist*)malloc(sizeof(slist));
    temp_node->Inf = x;
    temp_node->next = detect_node->next;
    detect_node->next = temp_node;
}

// muon xoa node nao thi thu hoi free() con tro tro toi node do
slist *Delete_Head(slist *first) {
    if (first == NULL) return NULL;
    slist *temp_node = first;
    first = first->next;
    free(temp_node);
    return first;
}

slist *Delete_Last(slist *first) {
    slist *detect_node = first, *temp_node = first;
    while (detect_node->next != NULL)
    {
        temp_node = detect_node;
        detect_node = detect_node->next;
    } // sau vong lap nay con tro temp_node->next = detect_node
    temp_node->next = NULL; // gan cho con tro ap chot trc khi xoa la NULL
    free(detect_node); // giai phong con tro detect_node tro den o bi xoa

    if (temp_node == first) return NULL; // day la truong hop danh sach rong
    else return first;
}

// void Delete_Middle(slist *pred) { // xoa node o sau node dc tro boi pred
//     slist *temp_node = pred->next;
//     pred->next = pred->next->next;
//     free(temp_node);  
// }

void Delete_Middle(slist **pred) {
    slist *temp_node = *pred;
    *pred = (*pred)->next;
    free(temp_node);
}

void Search(slist *first, element_type x) {
    slist *detect_node = first;
    while (detect_node->next!=NULL) {
        if (detect_node->Inf == x) {
            printf("Dia chi tro den gia tri %d: %p", x, detect_node);
            break;
        }
        detect_node = detect_node->next;
    }
    if (detect_node->Inf == x) printf("Dia chi tro den gia tri %d: %p", x, detect_node);
    else {
        printf("Deo co gia tri %d", x);
    }
}

// Ham kiem tra ds rong 
int IsEmpty (slist *first) {
    return !first;
}

// Ham huy ds
slist *MakeNull (slist *first) {
    while (!IsEmpty(first)) first = Delete_Head(first);
    return first;
}

// Recursive function:
slist* insertLast(slist *first, int v) {
    if (first==NULL) {
        return MakeNewNode(v);
    }
    first->next = insertLast(first->next, v);
    return first;
}

int s=0;
int sum(slist *first, int a, int b) {
    if (first==NULL) {
        return s;
    }
    else {
        sum(first->next, a, b);
        if (first->Inf <= b && first->Inf >= a) s += first->Inf;
    }
    return s;
}

slist *xoa_o_vi_tri_le(slist *first) {
    slist *q = first;
    if (first != NULL && first->next != NULL) {
        first = first->next;
        free(q);
    }
    for (slist *p = first; p != NULL && p->next != NULL; p = p->next) {
        slist *t = p->next;
        p->next = p->next->next;
        free(t);
    }
    return first;
}

slist *xoa_o_vi_tri_chan(slist *first) {
    for (slist *p = first; p != NULL && p->next != NULL; p = p->next) {
        slist *t = p->next;
        p->next = t->next;
        free(t);
    }
    return first;
}

int main() {
    slist *first = NULL, *node1, *node2;
    first = MakeNewNode(1);
    node1 = MakeNewNode(2);
    first->next = node1;
    node2 = MakeNewNode(3);
    node1->next = node2;
    
    first = Insert_To_Head(-1,first);
    Insert_To_Middle(0, first->next); 
    Insert_To_Last(11, first);

    Insert_To_Last(12,first);
    Insert_To_Middle(10, first->next->next->next->next);

    first = insertLast(first, 15);
    // first = MakeNull(first);
    DuyetDs(first);
    printf("\n");
    // printf("%d", sum(first,2,12));

    // first = xoa_o_vi_tri_le(first);
    // DuyetDs(first);
    //printf("%p", End(first));
    // Search(first, 15);
    
    // printf("Sau khi xoa:\n");

    // first = Delete_Head(first);
    // first = Delete_Last(first);

    slist *cur = first->next;
    printf("%d %d", cur->Inf, first->next->Inf);

    Delete_Middle(&cur); // sai do dia chi cua cur khac dia chi cua first->next: &(first->next)

    DuyetDs(first);

}