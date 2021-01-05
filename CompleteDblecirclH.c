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
void InsertRear(node);
void DeleteFront(node);
void DeleteRear(node);
void Disp();
void InsertPos(node);
void insertByOrder(node);
void DeletePos(node);
void DeleteKey(node);
void SearchByKey(node);
void createAnOrderedList(node);
node Copy(node);
void reverse(node);
void searchByPosition(node);
void leftK(node);
void rightK(node);


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
      printf("\nenter choice:\n1:InsertFront\n2:Disply\n3:InsertRear\n4:DeleteFront\n5:DeleteRear\n6:InsertByposition\n7:DeleteByposition\n8:DeleteByKey\n9:Search Key\n10:createAnOrderedList\n11:createACopy\n12:reverse\n13:InsertByOrder\n14:SearchByposition\n15:deleteKthleft\n16:Delete Kth right\n");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1: InsertFront(Head);
		
		Disp(Head);
		break;
	case 2: Disp(Head); break;
	case 3: InsertRear(Head); Disp(Head); break;
	case 4:  DeleteFront(Head); Disp(Head); break;
	case 5:  DeleteRear(Head); Disp(Head); break;
	case 6:  InsertPos(Head); Disp(Head); break;
	case 7:  DeletePos(Head); Disp(Head);break;
	case 8:  DeleteKey(Head);Disp(Head);break;
	case 9: SearchByKey(Head); break;
    case 10: createAnOrderedList(Head);Disp(Head); break;
    case 11: L2=Copy(Head);printf("\ncopied ");Disp(L2);break;
    case 12: reverse(Head);Disp(Head);break;
    case 13: insertByOrder(Head);Disp(Head);break;
    case 14: searchByPosition(Head);Disp(Head);break;
    case 15: leftK(Head);Disp(Head);break;
    case 16: rightK(Head);Disp(Head);break;
	default:exit(0);
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
  void DeleteFront(node H)
  {  node ND;
     if(H->info==0)
       {
	 printf("empty\n");
	 return;
       }
       ND=H->rlink;
       printf("\ndeleted %d",ND->info);
      H->rlink = ND->rlink;
      ND->rlink->llink =H;
      H->info--;
      free(ND);
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
 void  DeletePos(node H)
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
	 TN->llink->rlink = TN->rlink;
	 TN->rlink->llink = TN->llink;
	 printf("Deleted %d\n",TN->info);
	 free(TN);
	 H->info--;
      }
      else
      printf("Invalid position retry\n");
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

  void createAnOrderedList(node H)
  {
    int swapped, i; 
    node PN; 
    node TN = NULL; 
  
    if (H->info == 0) 
        return ; 
  
    do
    { 
        swapped = 0; 
        PN = H->rlink; 
  
        while (PN->rlink != H) 
        { 
            if (PN->info > PN->rlink->info) 
            {  
                int temp = PN->info; 
                    PN->info = PN->rlink->info; 
                    PN->rlink->info = temp;  
                swapped = 1; 
            } 
            PN = PN->rlink; 
        } 
        TN = PN; 
    } 
    while (swapped); 
 }


node Copy(node H)
{
  node PN, NN, TN, header;
  if(H->info==0)
  {
    return NULL;
  }
  TN=H->rlink;
  header=(node)malloc(sizeof(struct NODE));
  header->info=H->info;
  header->llink=header->rlink=NULL;
  PN=header;

  while (TN!=H)
  {
    NN=(node)malloc(sizeof(struct NODE));
    NN->info=TN->info;
    NN->llink=PN;NN->llink->rlink=NN;NN->rlink=NULL;
    TN=TN->rlink;
    PN=NN;
  }
  PN->rlink = header;
  header->llink=PN;
  return header;
}

void reverse(node H)
{
    if(H->info == 0)
           return;
    node TN,C,PN;
    TN=H;
    C=NULL;
    do
    {
       C=TN;
       TN=TN->rlink;
       PN=C->llink;
       C->llink=C->rlink;
       C->rlink=PN;

    }while(TN != H);
}

void insertByOrder(node H)
{
    node NN, TN, PN;
    NN = (node)malloc(sizeof(struct NODE));
    printf("Enter the element to be Entered: ");
    scanf("%d", &NN->info);
    TN=H->rlink;PN=NULL;
    H->info++;
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
