#include <stdio.h> 
#include <stdlib.h>

typedef int datatype;
typedef struct TreeNodeRec {
    datatype key;
    struct TreeNodeRec *left;
    struct TreeNodeRec *right;
    
} bstreeNode;

bstreeNode *makeTreeNode(datatype x);
bstreeNode *findMin(bstreeNode *r);
bstreeNode *findMax(bstreeNode *r);
void preorder(bstreeNode *r);
void inorder(bstreeNode *r);
void postorder(bstreeNode *r);
bstreeNode *predecessor(bstreeNode *r, datatype x);
bstreeNode *successor(bstreeNode *r, datatype x);
bstreeNode *search(bstreeNode *r, datatype target);
bstreeNode *insert(bstreeNode *r, datatype x);
bstreeNode *delete(bstreeNode *r, datatype x);



bstreeNode *makeTreeNode(datatype x) {
    bstreeNode *newnode = (bstreeNode*)malloc(sizeof(bstreeNode));
    if (newnode == NULL) return NULL;
    newnode->key = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

bstreeNode *findMin(bstreeNode *r) { // ptu trai nhat
    if (r == NULL) return ;
    bstreeNode *temp_node = r;
    while (temp_node->left != NULL)
        temp_node = temp_node->left;
    return temp_node;
}

bstreeNode *findMax(bstreeNode *r) { // ptu phai nhat
    if (r == NULL) return ;
    bstreeNode *temp_node = r;
    while (temp_node->right != NULL)
        temp_node = temp_node->right;
    return temp_node;
}

void preorder(bstreeNode *r) {
    if (r == NULL) return ;
    printf("%d ", r->key);
    preorder(r->left);
    preorder(r->right);
}

void postorder(bstreeNode *r) {
    if (r == NULL) return ;
    postorder(r->left);
    postorder(r->right);
    printf("%d ", r->key);
}

void inorder(bstreeNode *r) {
    if (r == NULL) return ;
    inorder(r->left); // duyet left trc!!!
    printf("%d ", r->key);
    inorder(r->right);
}

bstreeNode *predecessor(bstreeNode *r, datatype x) {
    // co 3 TH:
    // TH1: ptr la ptu nho nhat => NULL
    // TH2: ptr ko co con trai => to tien gan nhat cua ptr co con phai 
    // TH3: ptr co con trai => nut phai nhat (find_max) cua cay con trai cua ptr
    if (r == NULL) return NULL;
    // find con tro chua key = x:
    bstreeNode *predecessor = NULL;
    bstreeNode *temp_node = r; // con tro detect
    while (temp_node != NULL && temp_node->key != x) {
        if (temp_node->key > x) temp_node = temp_node->left;
        else {
            predecessor = temp_node; // luu to tien (TH2)
            temp_node = temp_node->right;
        }
    }
    // TH3: luc nay temp_node->key = x roi !!!
    if (temp_node != NULL && temp_node->left != NULL) predecessor = findMax(temp_node->left);
    return predecessor;
}

bstreeNode *successor(bstreeNode *r, datatype x) {
    if (r == NULL) return NULL;
    bstreeNode *successor = NULL;
    bstreeNode *temp_node = r;
    while (temp_node != NULL && temp_node->key != x) {
        if (temp_node->key < x) temp_node = temp_node->right;
        else {
            successor = temp_node;
            temp_node = temp_node->left;
        } 
    }

    if (temp_node != NULL && temp_node->right != NULL) successor = findMin(temp_node->right);
    return successor;
}

bstreeNode *search(bstreeNode *r, datatype target) {
    if (r == NULL) return NULL;

    if (target < r->key) return search(r->left, target);
    else if (target > r->key) return search (r->right, target);
    return r;
}

bstreeNode *insert(bstreeNode *r, datatype x) {
    if (r == NULL) r = makeTreeNode(x); // neu cay rong
    else if (x < r->key) r->left = insert(r->left, x);
    else if (x > r->key) r->right = insert(r->right, x);
    return r; // unchanged 
}

bstreeNode *delete(bstreeNode *r, datatype x) {
    if (!search(r, x) && r == NULL) return NULL; // neu ko co phan tu x can xoa trg cay
    // ta phai tim nut chua key = x:
    if (x < r->key) r->left = delete(r->left, x);
    else if (x > r->key) r->right = delete(r->right, x);
    else { // neu x == r->key
        // node with only one child or no child
        if (r->left == NULL) {
            bstreeNode *temp_node = r->right; // neu nut co con phai
            free(r);
            return temp_node;
        }
        else if (r->right == NULL) {
            bstreeNode *temp_node = r->left;; // neu nut co con trai 
            free(r);
            return temp_node;
        }
        // node have 2 children: doi cho phan tu can xoa voi successor cua no, va xoa successor do
        else {
            bstreeNode *temp_node = successor(r, r->key);
            r->key = temp_node->key;
            r->right = delete (r->right, temp_node->key); // vi nut successor luon o cay con phai cua nut x
        }
    }
    return r;

}

int main() {
    bstreeNode *root = NULL;

    // root = insert(root, 43);
    // root = insert(root, 31);
    // root = insert(root, 64);
    // root = insert(root, 20);
    // root = insert(root, 40);
    // root = insert(root, 56);
    // root = insert(root, 28);
    // root = insert(root, 89);
    // root = insert(root, 33);
    // root = insert(root, 47);
    // root = insert(root, 59);
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 55);
    insert(root, 25);
    insert(root, 35);
    insert(root, 53);
    insert(root, 60);
    insert(root, 10);
    insert(root, 31);
    insert(root, 37);
    insert(root, 62);
    insert(root, 20);
    insert(root, 23);


    // printf("%d\n", findMax(root)->key);
    // printf("%d\n", findMin(root)->key);
    
    //inorder(root);

    // datatype item; printf("\nEnter target: "); scanf("%d", &item);
    // if (search(root, item) == NULL) printf("khong tim thay\n");
    // else printf("tim thay\n");

    root = delete(root, 53);

    inorder(root);

}