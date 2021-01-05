#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int info;
  struct NODE *llink;
  struct NODE *rlink;
};
typedef struct NODE * node;

void InsertFront(node);
void leftK(node);
void searchByPosition(node);

void main()
{
   int ch;
   node Head, L2=NULL;
   Head = (node)malloc(sizeof(struct NODE));
   Head->info = 0;
   Head->llink=Head->rlink = Head; 
  system("clear");
   for(;;)
   {
      printf("\nEnter choice:\n1:InsertFront\n2:Delete left Kth node\n3:Search By position\n4.Exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1: InsertFront(Head);
		Disp(Head);
		break;
       case 2: leftK(Head);
                Disp(Head);
                break;
        case 3: searchByPosition(Head);
                 Disp(Head);
                 break;
           case 4:
               exit(0);
     }
 }
 //getch();
 }
 void InsertFront(node H)
    {
       node NN;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NN->llink = H;
       NN->rlink = H->rlink;
       NN->rlink->llink = NN;
       H->rlink = NN;
       H->info++;
    }
    
    void Disp(node H)
   {    node TP;
       if(H->info==0)
       {
	 printf("empty\n");
	 return;

	 }
	 TP = H->rlink;
       printf("\nList is:\n");
      while(TP!=H)
       {
	  printf("%d ", TP->info);
	  TP =TP->rlink;
      }
  }
void  InsertRear(node H)
    {
       node NN;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);


       NN->rlink = H;
       NN->llink = H->llink;
       H->llink->rlink = NN;
       H->llink = NN;
       H->info++;
   }
void leftK(node H)
{
    node  TN;
    int pos, cnt;
     if(H->info==0)
       {
	 printf("empty\n");
	 return ;
       }
	printf("\nenter kth position:" );
       scanf("%d",&pos);
       if(pos>=1 && pos<=H->info)
       {
        if(pos==1)
        {
            printf("\ndeletion of the previous node is not possible\n");
            return;
        }
	 TN = H->rlink;
	 cnt = 1;
     pos=pos-1;
	 while(cnt !=pos)
	 {
	   TN=TN->rlink ;
	   cnt++;
	 }
	 TN->llink->rlink = TN->rlink;
	 TN->rlink->llink = TN->llink;
	 printf("Deleted (k-1)th element %d\n",TN->info);
	 free(TN);
	 H->info--;
      }
      else
      printf("Invalid position retry\n");
}

void searchByPosition(node H)
{
    node  TN;
    int pos, cnt;
     if(H->info==0)
       {
	 printf("empty\n");
	 return ;
       }
	printf("\nenter position   from 1 to %d:" ,H->info);
       scanf("%d",&pos);
       if(pos>=1 && pos<=H->info)
       {
	 TN = H->rlink;
	 cnt = 1;
	 while(cnt !=pos)
	 {
	   TN=TN->rlink ;
	   cnt++;
	 }
	 printf("%d is present at position %d", TN->info, pos);
      }
      else
      printf("Invalid position retry\n");
}

