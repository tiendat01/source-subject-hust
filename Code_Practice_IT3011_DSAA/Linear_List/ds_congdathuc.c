#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coeff, pow;
    struct PolyNode *next;
} Poly;

Poly *makeNewNode(int heso, int somu) {
    Poly *temp = (Poly*)malloc(sizeof(Poly));
    temp->coeff = heso;
    temp->pow = somu;
    temp->next = NULL;
    return temp;
}

Poly *InsertLast(Poly *poly, int heso, int somu) {
    Poly *newnode = makeNewNode(heso, somu);
    if (poly == NULL) {
        // poly = (Poly*)malloc(sizeof(Poly));
        // poly = newnode;
        poly = makeNewNode(heso, somu);
    }
    else {
        Poly *temp = poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;   
    }
    return poly;
}

void duyetds(Poly *p) {
    if (p == NULL) return NULL;
    Poly *temp = p;
    while (temp != NULL) {
        printf("%d_%d ", temp->coeff, temp->pow);
        temp = temp->next;
    }
}

// dk la cac da thuc phai sap xep bac ko giam
Poly *Psum(Poly *poly1, Poly *poly2) {
    Poly *polySum = NULL;
    Poly *p1 = poly1, *p2 = poly2;
    Poly *temp = polySum; 

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow < p2->pow) {
            polySum = InsertLast(polySum, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else if (p1->pow > p2->pow) {
            polySum = InsertLast(polySum, p2->coeff, p2->pow);
            p2 = p2->next;
        }

        else {
            polySum = InsertLast(polySum, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    if (p1 == NULL) {
        while (p2 != NULL) {
            polySum = InsertLast(polySum, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }
    
    if (p2 == NULL) {
        while (p1 != NULL) {
            polySum = InsertLast(polySum, p1->coeff, p1->pow);
            p1 = p1->next;
        }
    }
    return polySum;
}

int main() {
    Poly *p1 = NULL, *p2 = NULL, *poly_sum = NULL;
    p1 = InsertLast(p1,4,0);
    InsertLast(p1,-5,1);
    InsertLast(p1,3,3);

    p2 = InsertLast(p2,1,0);
    InsertLast(p2,1,1);
    InsertLast(p2,2,2);
    InsertLast(p2,1,4);
    InsertLast(p2,-3,5);

    poly_sum = Psum(p1, p2);
    duyetds(p1);
    printf("\n");
    duyetds(p2);
    printf("\n");
    duyetds(poly_sum);
}