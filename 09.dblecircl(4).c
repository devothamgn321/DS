#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int info;
  struct NODE *llink;
  struct NODE *rlink;
};
typedef struct NODE * node;

void InsertPos(node);
void DeleteRear(node);
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
      printf("\nEnter choice:\n1:Insert by Position\n2: Delete Rear\n3: Search for an item by value/key\n4:Exit\n")
;
 scanf("%d",&ch);
      switch(ch)
      {
  case 1: InsertPos(Head); 
          Disp(Head);
           break;
  case 2: DeleteRear(Head);
          Disp(Head);
          break;
  case 3 : SearchByKey(Head);
           break;
   case 4: exit(0);
   }
 }
 //getch();
 }

 void InsertPos(node H)
  {

       node NN,TN;
       int pos,cnt;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);

       printf("\nenter position   from 1 to %d:" ,H->info+1);
       scanf("%d",&pos);
       if(pos>=1 && pos<=H->info+1)
       {
	  cnt= 1;
	  TN = H;
	  while(cnt<pos)
	  {
	     TN= TN->rlink;
	      cnt++;
	  }
	  NN->rlink = TN->rlink;
	  NN->llink = TN;
	  TN->rlink = NN;
	  NN->rlink->llink = NN;
	  H->info++;
       }
       else
       printf("Invalid position\n");
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


 void DeleteRear(node H)
  {  node  ND;
     if(H->info==0)
       {
	 printf("empty\n");
	 return ;
       }
       ND = H->llink;
      printf("\ndeletd %d",ND->info);
      ND->llink->rlink = H;
      H->llink = ND->llink;
      H->info--;
      free(ND);

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
