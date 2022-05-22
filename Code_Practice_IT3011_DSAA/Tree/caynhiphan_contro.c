#include <stdio.h>
#include <stdlib.h>

typedef char datatype;
typedef struct _nodetype {
    datatype inf;
    struct _nodetype *left;
    struct _nodetype *right;
} btreeNode;

btreeNode *makeTreeNode(datatype x) {
    btreeNode *newNode = (btreeNode*)malloc(sizeof(btreeNode));
    if (newNode == NULL) return NULL;
    newNode->inf = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int countNodes(btreeNode *r) {
    if (r == NULL) return 0;
    else {
        int leftNode = countNodes(r->left);
        int rightNode = countNodes(r->right);
        return 1+leftNode+rightNode;
    }
}

int depth(btreeNode *r) {
    if (r == NULL) return 0;
    else {
        int leftchild = depth(r->left);
        int rightchild = depth(r->right);
        return 1+(leftchild > rightchild ? leftchild : rightchild);
    }
}

void freeTree(btreeNode *r) {
    if (r == NULL) return;
    freeTree(r->left);
    freeTree(r->right);
    free(r); // giai phong bo nho cho nut cha
}

btreeNode *taoCaynhiphandaydu(int n, datatype x) {
    // chieu cao n, cac node mang cung mot thong tin x
    if (n==0) return NULL;
    btreeNode *r = makeTreeNode(x);
    btreeNode *left_child = taoCaynhiphandaydu(n-1, x);
    btreeNode *right_child = taoCaynhiphandaydu(n-1, x);
    r->left = left_child;
    r->right = right_child;
    return r;
}

int kiemtraCaynhiphandaydu(btreeNode *r) {
    if (r==NULL) return 0; // cay rong
    if (r->left == NULL && r->right == NULL) return 1; // cay co 1 nut
    int left_child = kiemtraCaynhiphandaydu(r->left);
    int right_child = kiemtraCaynhiphandaydu(r->right);
    int height_left = depth(r->left);
    int height_right = depth(r->right);
    // la cay nhi phan day du khi 2 nut o cung 1 do cao co du cac con trai, phai
    if (height_left == height_right && left_child == 1 && right_child == 1) return 1;
    else return 0;
}

int demSoAnhEmcuaNut(btreeNode *r, btreeNode *node) {
    // cac buoc neo de quy
    if (r == NULL || node == NULL) return 0;
    if (r == node) return 0; // nut goc ko co ae nao
    // truong hop cay co chieu cao h = 2
    if (node == r->left && r->right == NULL) return 0;
    else if (node == r->right && r->left == NULL) return 0;
    else if (node == r->left && r->right != NULL) return 1;
    else if (node == r->right && r->left != NULL) return 1;
    // truong hop con lai la cac buoc de quy:
    else {
        int left_child = demSoAnhEmcuaNut(r->left, node);
        int right_child = demSoAnhEmcuaNut(r->right, node);
        return left_child+right_child;
    }

}

int soNutLa(btreeNode *r) {
    if (r == NULL) return 0;
    if (r->left == NULL && r->right == NULL) return 1;
    int count_leftchild = soNutLa(r->left);
    int count_rightchild = soNutLa(r->right);
    return count_leftchild+count_rightchild;
    
}

void preorder(btreeNode *r) {
    if (r == NULL) return ;
    printf("%c ", r->inf);
    preorder(r->left);
    preorder(r->right);
}

void postorder(btreeNode *r) {
    if (r == NULL) return ;
    postorder(r->left);
    postorder(r->right);
    printf("%c ", r->inf);
}

void inorder(btreeNode *r) {
    if (r == NULL) return ;
    inorder(r->left); // duyet left trc!!!
    printf("%c ", r->inf);
    inorder(r->right);
}

/// khu de quy



int main() {
    btreeNode *mytree = makeTreeNode('A');
    btreeNode *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;

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
	
	mytree->left = nutB;
	nutB->left = nutE;
	nutB->right = nutC;
	nutC->left = nutG;
	nutC->right = nutD;
	nutE->right = nutF;
	nutG->left = nutH;
	nutH->right = nutI;
	nutI->right = nutJ;
	nutJ->right = nutK;

    printf("Duyet truoc cay nhi phan:");
	preorder(mytree);
	printf("\nDuyet sau cay nhi phan:");
	postorder(mytree);
	printf("\nDuyet giua cay nhi phan:");
	inorder(mytree);
	
	printf("\nChieu sau cay tong quat:");
	printf("%d",depth(mytree));

    printf("\nSo nut cua cay nhi phan:");
    printf("%d", countNodes(mytree));

    printf("\nSo nut la cua cay nhi phan:");
	printf("%d",soNutLa(mytree));
	
	printf("\nSo ae cua nut F:");
	printf("%d",demSoAnhEmcuaNut(mytree, nutF));
	
	printf("\nKiem tra cay nhi phan day du mytree: %d", kiemtraCaynhiphandaydu(mytree));
	
	btreeNode *caydaydu = taoCaynhiphandaydu(3,'X');
	printf("\nKiem tra cay nhi phan day du moi tao: %d", kiemtraCaynhiphandaydu(caydaydu));
}