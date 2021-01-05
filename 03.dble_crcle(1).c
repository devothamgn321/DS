#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int info;
  struct NODE *llink;
  struct NODE *rlink;
};
typedef struct NODE * node;


void Disp();
void DeleteKey(node);
void Search(node);
void InsertByOrder(node);

void main()
{
   int ch;
   node Head , NH = NULL;
   Head = (node)malloc(sizeof(struct NODE));
   Head->info = 0;
   Head->llink=Head->rlink = Head; 

   while(1)
   {
      printf("\nenter choice:\n1:InsertByOrder\n2:DeleteByKey\n3:SearchByPos\n4:display\n5:Exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
	
	case 1: InsertByOrder(Head); Disp(Head);break; 
	case 2: DeleteKey(Head);Disp(Head);break;
	case 3: Search(Head); break;
	case 4: Disp(Head);break;
  case 5: exit(0);
	default: printf("invalid input\n");
     }
 }

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
 
void DeleteKey(node H)
{
    node  TN;
    int pos, info;
     if(H->info==0)
       {
	 printf("empty\n");
	 return ;
       }
       printf("enter the info of the node to be deleted\n");
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
       {
	 printf("node with the info %d is present at position %dis deleted \n", TN->info, pos);
	 TN->llink->rlink = TN->rlink;
	 TN->rlink->llink = TN->llink;
	 free(TN);
	 H->info--;
       }
}
void Search(node H)
{
    node  TN;
    int pos, info;
     if(H->info==0)
       {
	 printf("empty\n");
	 return ;
       }
       printf("enter the position of the node to be searched\n");
       scanf("%d", &info);
      TN = H->rlink;
      pos = 1;
	  if(info<1 && info>H->info)
	  {
		  printf("node at %d pos not exist\n",info);
		  return;
	  }
      while(TN!=H && pos<info)
      {
	  TN=TN->rlink;  pos++;
      }
       if(TN == H)
       printf("Node does not exist\n");
       else

	 printf("node with the info %d is present at position %d \n", TN->info, pos);
}

void InsertByOrder(node H)
    {
       node NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
      
       node T = H->rlink;
       while(T->info < NN->info  && T!= H)
         T=T->rlink;
       
       NN->rlink  = T;
       NN->llink = T->llink;
       T->llink = NN;
       NN->llink->rlink = NN;
       H->info ++;

 }
 




