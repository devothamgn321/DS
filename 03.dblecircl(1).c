/*implement circular double linked list with header node to perfrom 
1. insert by order
2.delete by position
3.search by key */


#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int info;
  struct NODE *llink;
  struct NODE *rlink;
};
typedef struct NODE * node;

void insertByOrder(node);
void DeleteKey(node);
void searchByPosition(node);
void Disp(node);

void main()
{
   int ch;
   node Head;
   Head = (node)malloc(sizeof(struct NODE));
   Head->info = 0;
   Head->llink=Head->rlink = Head; 
  
   for(;;)
   {
      printf("\nenter choice:\n1:InsertByOrder\n2:DeleteByKey\n3:SearchByPosition\n4:display\n");
      scanf("%d",&ch);
      switch(ch)
      {
	
    case 1: insertByOrder(Head);Disp(Head);break;
    case 2:  DeleteKey(Head); Disp(Head);break;
    case 3: searchByPosition(Head);Disp(Head);break;
    case 4: Disp(Head); break;
	default:exit(0);

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

void insertByOrder(node H)
{
    node NN, TN, PN;
    NN = (node)malloc(sizeof(struct NODE));
    printf("Enter the element to be Entered: ");
    scanf("%d", &NN->info);
    TN=H->rlink;PN=NULL;
    H->info++;

    if(TN==H){
        H->rlink=NN;
        NN->llink=TN;
        H->llink=TN;
        NN->rlink=TN;
        return;
    }

    if(TN->info>NN->info)
    {
        H->rlink=NN;
        NN->llink=H;
        TN->llink=NN;
        NN->rlink=TN;
        return;
    }
    while(TN!=H && TN->info<NN->info)
    {
        PN=TN;
        TN=TN->rlink;
    }
    if(TN == NULL){
        printf("Invalid input\n");
    }
    PN->rlink = NN;
    NN->llink=PN;
    TN->llink=NN;
    NN->rlink=TN;
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

