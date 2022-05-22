#include <stdio.h>
#include <stdlib.h>

typedef char datatype;
typedef struct Tnode {
    datatype inf;
    struct Tnode *left_most_child;
    struct Tnode *right_sibling;
} tnode;

tnode *makeTreeNode(datatype x) {
    // nut A la goc cua cay
    tnode *nutA = (tnode*)malloc(sizeof(tnode));
    if (nutA==NULL) return NULL;
    nutA->inf = x;
    nutA->left_most_child = NULL;
    nutA->right_sibling = NULL;
    return nutA;
}

int countNode(tnode *r) {
    if (r == NULL) return 0;
    int count = 0;
    tnode *temp_node = r->left_most_child;
    while (temp_node != NULL)
    {
        count += countNode(temp_node);
        temp_node = temp_node->right_sibling;
    }
    return count+1; // tinh nut goc
    
}

int height(tnode *r) {
    if (r == NULL) return 0;
    int h = 0;
    tnode *temp_node = r->left_most_child;
    while (temp_node != NULL) {
        int temp_height = height(temp_node);
        if (h < temp_height) h = temp_height;
        temp_node = temp_node->right_sibling;
    }
    return 1+h;

}

int demSoAnhEmcuaNut(tnode *r, tnode *node) {
    if (r == NULL) return 0;
    // ta phai tim muc cua node, tu do dem so ae trong muc do
    if (r == node) return 1;
    int count = 0, temp_count = 0, flag = 0; // flag check xem da tim dc muc cua node chua?
    tnode *p = r->left_most_child;
    // duyet hang ngang, theo muc. Day la TH tim duoc muc cua node. day la buoc neo de quy
    while (p != NULL) {
        count++;
        if (node == p) flag = 1;
        p = p->right_sibling;
    }

    if (!flag) { // neu chua tim dc node, chay de quy xuong muc duoi
        p = r->left_most_child;
        while (p!= NULL)
        {
            temp_count = demSoAnhEmcuaNut(p, node);
            if (temp_count != 0) count = temp_count;
            p = p->right_sibling;
        }
    }
    return count;
}

int soNutLa(tnode *r) {
    if (r == NULL) return 0;
    if (r->left_most_child == NULL) return 1;
    int soNutLa_var = 0;
    tnode *temp_node = r->left_most_child;
    while (temp_node != NULL) {
        soNutLa_var += soNutLa(temp_node);
        temp_node = temp_node ->right_sibling;
    }
    return soNutLa_var;
}

void preorder(tnode *r) {
    if (r==NULL) return ;
    printf("%c ", r->inf);

    tnode *temp_node = r->left_most_child;
    while (temp_node != NULL) {
        preorder(temp_node);
        temp_node = temp_node->right_sibling;
    }
}

void postorder(tnode *r) {
    if (r==NULL) return ;
    tnode *temp_node = r->left_most_child;
    while (temp_node != NULL) {
        postorder(temp_node);
        temp_node = temp_node->right_sibling;
    }

    printf("%c ", r->inf);
}

void inorder(tnode *r) {
    if (r==NULL) return ;
    // cay chi co 1 nut. Buoc neo de quy
    if (r->left_most_child==NULL) {
        printf("%c ", r->inf);
        return ;
    }

    tnode *temp_node = r->left_most_child;
    inorder(temp_node); // phai inorder con trai nhat truoc
    printf("%c ", r->inf);// roi moi den goc!!!

    if(temp_node!=NULL) temp_node = temp_node->right_sibling; // chay 1 lan sang ae phai 

    while (temp_node != NULL) {
        inorder(temp_node);
        temp_node = temp_node->right_sibling;
    }
}



int main() {
    tnode *mytree = makeTreeNode('A');
    tnode *nutB, *nutC, *nutD,*nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;
	nutB = makeTreeNode('B');
	nutC = makeTreeNode('C');
	nutD = makeTreeNode('D');
	nutE = makeTreeNode('E');
	nutF = makeTreeNode('F');
	nutG = makeTreeNode('G');
	nutH = makeTreeNode('H');
	nutI = makeTreeNode('I');
	nutJ = makeTreeNode('J');
	nutK = makeTreeNode('K');

    mytree->left_most_child = nutB;
    nutB->left_most_child = nutE;
    nutB->right_sibling = nutC;
    nutC->left_most_child = nutG;
    nutC->right_sibling = nutD;
    nutE->right_sibling = nutF;
    nutG->left_most_child = nutH;
    nutH->right_sibling = nutI;
    nutI->right_sibling = nutJ;
    nutJ->right_sibling = nutK;  

    printf("Duyet truoc cay tong quat:");
	preorder(mytree);
	printf("\nDuyet sau cay tong quat:");
	postorder(mytree);
	printf("\nDuyet giua cay tong quat:");
	inorder(mytree);

    printf("\nChieu cao cua cay tong quat:");
    printf("%d", height(mytree));
    printf("\nSo nut cua cay tong quat:");
    printf("%d", countNode(mytree));
    printf("\nSo nut la cua cay tong quat:");
    printf ("%d", soNutLa(mytree));
    printf("\nSo ae cua nut I:");
	printf("%d",demSoAnhEmcuaNut(mytree, nutI));
}