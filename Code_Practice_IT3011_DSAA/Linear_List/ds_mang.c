#include <stdio.h>
#include <stdlib.h>

#define maxlength 1000

// Khoi tao list dung mang:
typedef int element_type;
typedef struct list {
    element_type elements[maxlength]; // mang luu gia tri cac phan tu cua list voi vi tri tu 0 den lp->last
    int last; //  vi tri phan tu cuoi cung trong list, vi tri cuoi cung cua mang
} list_type;

// Cac ham thu tuc thao tac voi list
// Ham End(L)
int End(list_type *lp) {
    return (lp->last + 1); // tra ve vi tri cua phan tu cuoi cung
    // do ds danh vi tri tu 1 den n nen last+1
}

// Ham Insert chen x vao list
void Insert(element_type x, int pos, list_type *lp) { // pos la vi tri theo mang tu 0 den lp->last
    if (lp->last + 1 >= maxlength) {
        printf("%s\n", "List is full");
        return;
    }
    if (pos < 0 || pos > lp->last+1) {
        printf("%s\n", "Postition is not existed");
        return;
    }
    else {
        for (int i = lp->last; i >= pos; i--) {
            lp->elements[i+1] = lp->elements[i];
        }
        lp->elements[pos] = x;
        lp->last++;
    }
}

// Ham Delete xoa gia tri x o vi tri p
void Delete(int pos, list_type *lp) {
    if (lp->last < 0) {
        printf("%s\n", "List is empty");
        return;
    }
    if (pos < 0 || pos > lp->last) {
        printf("%s\n", "Position is not existed");
        return;
    }
    else {
        for (int i = pos; i <= lp->last; i++) {
            lp->elements[i] = lp->elements[i+1];
        }
        lp->last--;
    }
}

// Ham Locate tra ve vi tri cua x trong list
int Locate(element_type x, list_type *lp) {
    if (lp->last < 0) {
        printf("%s\n", "List is empty");
        return;
    }
    else {
        for (int i = 0; i < lp->last; i++) {
            if (lp->elements[i] == x) return i+1;
        }
    }
    return;
}


int main() {
    list_type *lp = (list_type*) malloc(sizeof(list_type));
    lp->last = -1;
    Insert(9,0,lp);
    Insert(1,1,lp);
    Insert(3,2,lp);
    Insert(4,3,lp);
    Insert(10,4,lp);
    Insert(8,2,lp);

    Insert(11,-1,lp);
    Insert(11,15,lp);
    for (int i = 0; i <= lp->last; i++) 
        printf("%d ", lp->elements[i]);
    printf("\n-------\n");
    Delete(2,lp);
    for (int i = 0; i <= lp->last; i++) 
        printf("%d ", lp->elements[i]);
}