#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

typedef struct _Polynom {
   int coeff;
   int pow;
   struct _Polynom *link;
} Poly;



Poly *Psum(Poly *Poly1, Poly *Poly2)
{
   Poly *PolySum=(Poly*)malloc (sizeof(Poly)); // khoi tao vung nho cho con tro dau cua list
   Poly *ptr1,*ptr2, *ptr; // ptr la con tro trung gian chay list 3
   ptr1 = Poly1;
   ptr2 = Poly2;
   Poly *node = PolySum; // PolySum la con tro dau cua list 3, node la con tro trung gian de thao cong, tru tren list 1,2
   while(ptr1!=NULL && ptr2!=NULL){
       if  (ptr1->pow > ptr2->pow ) {
	       node->coeff=ptr2->coeff;
	       node->pow=ptr2->pow;
	       ptr2=ptr2->link;   //update ptr list 2
       }
       else if ( ptr1->pow < ptr2->pow )
         {
	          node->coeff=ptr1->coeff;
	          node->pow=ptr1->pow;
	          ptr1=ptr1->link;   //update ptr list 1
	      }
	      else
	      {  node->coeff=ptr2->coeff+ptr1->coeff;
	         node->pow=ptr2->pow;
	         ptr1=ptr1->link;   //update ptr list 1
	         ptr2=ptr2->link;   //update ptr list 2
	      }
        ptr=node;
        
        node=(Poly *)malloc (sizeof(Poly)); // khoi tao vung nho cho nut moi cua list 3 
        ptr->link=node;   //update ptr list 3
   } //end of while

   if (ptr1==NULL)     //end of list  1
   {
        while(ptr2!=NULL){
 	     node->coeff=ptr2->coeff; 
         node->pow=ptr2->pow;
	     ptr2=ptr2->link;   //update ptr list 2
	     ptr=node; 

         node=(Poly *)malloc (sizeof(Poly)); // tao con tro moi cho nut tiep theo
	     ptr->link=node; }  //update ptr list 3
   }
   else if (ptr2==NULL)     //end of list  2
   {
	    while(ptr1!=NULL) {
	       node->coeff=ptr1->coeff;
	       node->pow=ptr1->pow;
	       ptr1=ptr1->link;   //update ptr list 2
	       ptr=node;

	       node=(Poly *)malloc (sizeof(Poly)); // tao con tro moi cho nut tiep theo
	       ptr->link=node;   //update ptr list 3
	   }
	}
  ptr->link=NULL;
  return PolySum; // tra lai con tro dau cua list 3
}

void duyetds(Poly *head)
{
    Poly *tg = head;
    while(tg!=NULL)
    {
        printf("%d_%d ",tg->coeff,tg->pow);
        tg=tg->link;
    }
}

int main()
{
    Poly *Px, *Qx;
    Poly  *newnode=(Poly *)malloc (sizeof(Poly));
    newnode->coeff = 4;
    newnode->pow = 0;
    newnode->link = NULL;

    Px = newnode;
    newnode=(Poly *)malloc (sizeof(Poly));
    newnode->coeff = -5;
    newnode->pow = 1;
    newnode->link = NULL;

    Px->link = newnode;
    newnode=(Poly *)malloc (sizeof(Poly));
    newnode->coeff = 3;
    newnode->pow = 3;
    newnode->link = NULL;
    
    Px->link->link = newnode;

    printf("\nDs Px:\n");
    duyetds(Px);

    newnode=(Poly *)malloc (sizeof(Poly));
    newnode->coeff = 1;
    newnode->pow = 0;
    newnode->link = NULL;
    Qx = newnode;

    newnode=(Poly *)malloc (sizeof(Poly));
    newnode->coeff = 1;
    newnode->pow = 1;
    newnode->link = NULL;
    Qx->link = newnode;

    newnode=(Poly *)malloc (sizeof(Poly));
    newnode->coeff = 2;
    newnode->pow = 2;
    newnode->link = NULL;
    Qx->link->link = newnode;

    newnode=(Poly *)malloc (sizeof(Poly));
    newnode->coeff = 1;
    newnode->pow = 4;
    newnode->link = NULL;
    Qx->link->link->link = newnode;

    newnode=(Poly *)malloc (sizeof(Poly));
    newnode->coeff =-3;
    newnode->pow = 5;
    newnode->link = NULL;
    Qx->link->link->link->link = newnode;

    printf("\nDs Qx:\n");
    duyetds(Qx);

    Poly *Sum = Psum(Px,Qx);
    printf("\nDs Tong:\n");
    duyetds(Sum);
    printf("\n");
    return 1;
}
