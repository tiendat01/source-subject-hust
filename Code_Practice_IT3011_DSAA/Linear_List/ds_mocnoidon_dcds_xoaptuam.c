  #include <stdio.h>
#include <stdlib.h>

typedef int elementtype; /* elements are integers */
typedef struct list_node {
            elementtype inf;
            struct list_node *next;
}node;

void duyetds(node *first)
{
    node *tg = first;
    while(tg!=NULL)
    {
        printf("%d ",tg->inf);
        tg = tg->next;
    }
}

node *makenewnode(elementtype x)
{
    node *first = NULL;
    first= (node*)malloc(sizeof(node));
    first->inf = x;
    first->next = NULL;

    return first;
}

node *Insert_ToHead(node *First, elementtype X)
{
    node *TempNode;
	TempNode = (node *) malloc(sizeof(node));
	TempNode->inf=X;
	TempNode->next=First;
	First=TempNode;
	return First;
}

void Insert_ToLast(node *head, elementtype X)
{
    node *NewNode;
    node *TempNode;
    NewNode = (node *) malloc(sizeof(node));
    NewNode->inf=X;
    NewNode->next=NULL;
    TempNode=head;
    while (TempNode->next != NULL) // go to the end of a list
        TempNode= TempNode->next;
    TempNode->next = NewNode;

}

node *Insert_Middle(node *Pred, elementtype X)
{
    node *TempNode;
	TempNode = (node *) malloc(sizeof(node));  //(1)
	TempNode->inf=X;                                   //(1)
	TempNode->next=Pred->next;                         //(2)
	Pred->next=TempNode;                               //(3)
	return TempNode;
}

node *Delete_Head(node *First)
{
    if(First==NULL) return NULL;
    node *TempNode;
	TempNode=First->next;
	free(First);
	return TempNode;
}

node *Delete_Last(node *First)
{
    node *TempNode1, *TempNode2;
	TempNode1= First; TempNode2= First;
   while (TempNode1->next != NULL) // Go to the end of a list
   {
        TempNode2 = TempNode1;
        TempNode1= TempNode1->next;
    }
   TempNode2->next = NULL;
   free(TempNode1);
   if(TempNode1==First) return NULL;
   else
        return First;
}

node *dcds_cach1(node *first)
{
    node *p1, *p2, *p3;
    if(first==NULL||first->next==NULL) return first;
    p1 = NULL; p2 = first; p3=first->next; // p2 = first la ta thay doi con tro first

    while(p3!=NULL)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    return p2; // luc nay p2 la con tro first cua dc dao chieu
}

node *dcds_cach2(node *first)
{
    node *tg;
    if(first==NULL||first->next==NULL) return first;
    if(first->next->next==NULL) // Base case
        tg=first->next;
    else
        tg = dcds_cach2(first->next);

    first->next->next = first;
    first->next = NULL;
    return tg;
}

node *taods_duong(node *first)
{
	node *out = NULL,*t=first;
	if(first==NULL) return NULL;
	
	while(t!=NULL)
       {
		if(t->inf>=0){
			if(out==NULL){
				out=Insert_ToHead(out,t->inf);
			}
			else{
				Insert_ToLast(out,t->inf);
			}
		}
		t=t->next;
	}
	return out;
}

node *xoaptuam(node *first)
{
    if(first==NULL) return NULL;
    if(first->next==NULL){
        if(first->inf<0)
        {
            free(first);
            return NULL;
        }
        else return first;
	}
	
    node *p1, *p2;
    p1 = first;
    p2 = NULL;
    while(p1!=NULL)
    {
        if(p1->inf<0)
        {
            printf("\nNut se bi xoa %d\n",p1->inf);
            if(p1==first){//neu la nut dau tien
                first = p1->next;
                p2 = p1;
                p1 = p1->next;
                free(p2);
            }
            else{
                if(p1->next==NULL){//neu la nut cuoi
                    p2->next=NULL;
                    p2 = p1;
                    p1 = p1->next;
                    free(p2);
                }
                else {//neu la mot nut khong phai nut dau cuoi
                    p2->next = p2->next->next;
                    p2 = p1;
                    p1 = p1->next;
                    free(p2);
                }
            }
        }
        else{
            p2 = p1;
            p1 = p1->next;
        }
    }
    return first;
}

int  main()
{
    node *first = NULL;
    first= makenewnode(10);

    node *nut2 = makenewnode(12);
    first->next = nut2;

    //node *tg,*otg=nut2;
    int i;
    /*
    for(i=0;i<1000;i++)
    {
        tg=makenewnode(i);
        otg->next = tg;
        otg = tg;
    }
    */
    for(i=0;i<1000;i++)
    {
        Insert_ToLast(first,i);
    }

    first = Insert_ToHead(first,-10);
    Insert_ToLast(first,1000);
    Insert_Middle(first->next->next,-1);
    first = Delete_Head(first);
    first = Delete_Last(first);
    printf("\nDS vua tao ra :\n");
    duyetds(first);

    printf("\n***********DC DS vua tao ra bang cach 2:\n");
    first = dcds_cach2(first);
    // first = Insert_ToHead(first,-50);
    // Insert_ToLast(first,-50);
    duyetds(first);

    //printf("\n***********Xoa ptu am trong ds(cach 1):\n");
    //first = xoaptuam(first);
    //duyetds(first);

    // printf("\n***********Xoa ptu am trong ds(cach 2):\n");
    // node *new=taods_duong(first);
    // duyetds(new);

    printf("\n");
    
    return 1;
}
