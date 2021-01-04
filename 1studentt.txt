#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N,size;
struct student{
    int stud_id;
    char name[10];
    int marks[3];
};

void insert(struct student*);
void delete(struct student*);
void highest(struct student*);

int main(){
    struct student*sp;N=-1;
    printf("enter the size\n");
    scanf("%d",&size);
    sp = (struct student*) malloc(size*sizeof(struct student));
    int choice;
    for(;;)
    {printf("\nenter choice\n1.insert\n2.delete\n3.search for the student with highest marks(each subject)\n4.exit");
    scanf("%d",&choice);
    switch(choice)
    {case 1: insert(sp);break;
     case 2: delete(sp);break;
     case 3: highest(sp);break;
     case 4: exit(0);
     default:printf("invalid choice");exit(0);
    }
    
    }
    return 0;
}

void insert(struct student *sp)
{if(N== (size-1))
 {printf("insufficient memory space\n");
  printf("reallocating memory\n");
  sp = (struct student*) realloc(sp,size*2);
  size= size*2;
 }
 N++;
 int i;
 printf("enter id,name,marks in 3 subjects\n");
 scanf("%d %s",&(sp+N)->stud_id,(sp+N)->name);
 for(i=0;i<3;i++)
 scanf("%d",&(sp+N)->marks[i]);
 
 printf("ID \t NAME \t TEST1 \t TEST2 \t TEST3 \n");
 for(i=0;i<=N;i++)
 {printf("%d \t %s \t %d \t %d \t %d \n",(sp+i)->stud_id,(sp+i)->name,(sp+i)->marks[0],(sp+i)->marks[1],(sp+i)->marks[2]);
 }
 
}

void delete (struct student*sp)
{if (N==-1)
 {printf("list is empty\n");
  return;
 }
 
 int key,i;
 printf("enter id of the student");
 scanf("%d",&key);
 for(i=0;i<=N && (sp+i)->stud_id != key;i++){}
 if(i==(N+1))
 {printf("not found\n");
  return;}
  
  for(;i<N;i++)
  {(sp+i)->stud_id = (sp+i+1) ->stud_id;
   strcpy((sp+i)->name,(sp+i+1)->name);
   for(int j=0;j<3;j++)
   (sp+i)->marks[j] = (sp+i+1)->marks[j] ;
   
  }
  
  N--;
  if(N==-1)
  {printf("list empty\n");return;}
  
  for(i=0;i<=N;i++)
 {printf("%d \t %s \t %d \t %d \t %d \n",(sp+i)->stud_id,(sp+i)->name,(sp+i)->marks[0],(sp+i)->marks[1],(sp+i)->marks[2]);
 }
}

void highest(struct student *sp)
{if(N==-1)
{printf("list empty\n");
 return;
}

int h1=0,h2=0,h3=0,marks1=0,marks2=0,marks3=0;
for(int i=0;i<=N;i++)
{if((sp+i) ->marks[0] > marks1)
  {h1= i;
   marks1=(sp+i)->marks[0];
  }
  
  if((sp+i) ->marks[1] > marks2)
  {h2= i;
   marks2=(sp+i)->marks[1];
  }
  
  if((sp+i) ->marks[2] > marks1)
  {h3= i;
   marks3=(sp+i)->marks[2];
  }
  
}

printf("student with highest marks in sub1\n");
printf("NAME - %s",(sp+h1)->name);
printf("\nID - %d", (sp+h1)->stud_id);
printf("\nMarks - %d\n",(sp+h1)->marks[0]);

printf("student with highest marks in sub2\n");
printf("NAME - %s",(sp+h2)->name);
printf("\nID - %d", (sp+h2)->stud_id);
printf("\nMarks - %d\n",(sp+h2)->marks[1]);

printf("student with highest marks in sub3\n");
printf("NAME - %s",(sp+h3)->name);
printf("\nID - %d", (sp+h3)->stud_id);
printf("\nMarks - %d\n",(sp+h3)->marks[2]);

}