#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int info;
  struct NODE *llink;
  struct NODE *rlink;
};
typedef struct NODE * node;

void InsertRear(node);
void rightK(node);
void SearchByKey(node);

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
      printf("\nEnter choice:\n1:Insert Rear\n2: Delete Right Kth node\n3: Search for an item by value/key\n4:Exit\n")
;
 scanf("%d",&ch);
      switch(ch)
      {
  case 1: InsertRear(Head); 
          Disp(Head);
           break;
  case 2: rightK(Head);
          Disp(Head);
          break;
  case 3 : SearchByKey(Head);
           break;
   case 4: exit(0);
   }
 }
 //getch();
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


void rightK(node H)
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
        if(pos==H->info)
        {
            printf("\ndeletion of the immediate right node is not possible\n");
            return;
        }
	 TN = H->rlink;
	 cnt = 1;
     pos=pos+1;
	 while(cnt !=pos)
	 {
	   TN=TN->rlink ;
	   cnt++;
	 }
	 TN->llink->rlink = TN->rlink;
	 TN->rlink->llink = TN->llink;
	 printf("Deleted (k+1)th element %d\n",TN->info);
	 free(TN);
	 H->info--;
      }
      else
      printf("Invalid position retry\n");
}

void SearchByKey(node H)
{
    node  TN;
    int pos, info;
     if(H->info==0)
       {
	 printf("empty\n");
	 return ;
       }
       printf("enter the info of the node to be searched\n");
       scanf("%d", &info);
      TN = H->rlink;
      pos = 1;
      while(TN!=H && TN->info !=info)
      {
	  TN=TN->rlink;  pos++;
      }
       if(TN == H)
       printf("Node does not exist\n");
       else

	 printf("node with the info %dwhich  is present at position %d \n", TN->info, pos);


}
