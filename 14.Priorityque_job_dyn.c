#include<stdio.h>
#include<stdlib.h>

struct JOBS{
    int id;
    char name[20];
    int priority;
};
typedef struct JOBS jobs;

struct QUEUE{
    jobs items[5];
    int front,rear;
};
typedef struct QUEUE queue;

queue enqueue(queue Q){
    if(Q.rear==4){
        printf("Queue is full\n");
    }else{
        jobs J;
        printf("Enter the new job details:"); 
        printf("Enter job id:");
        scanf("%d",&J.id);
        printf("Enter job name:");
         scanf("%s",J.name);
        printf("Enter job priority:");
        scanf("%d",&J.priority);
        Q.items[++Q.rear]=J;
        printf("Job enqueued\n");
    }
    return Q;
}

queue dequeue(queue Q){
    if(Q.front>Q.rear){
        printf("Queue is empty\n");
    }else{
        int minI=0,i;
        jobs min=Q.items[0];
        for(i=Q.front;i<=Q.rear;i++){
            if(Q.items[i].priority<min.priority){
                min=Q.items[i];
                minI=i;
            }
        }
        for(i=minI;i<Q.rear;i++){
            Q.items[i]=Q.items[i+1];
        }
        Q.rear--;
        printf("Dequeued job-\nid: %d\nName: %s\nPriority: %d\n",min.id,min.name,min.priority);
    }
    return Q;
}

void displayQueue(queue Q){
     if(Q.front>Q.rear){
        printf("Queue is empty\n");
    }else{
        printf("Queue jobs:\n");
        printf("id \tName \tPriority \n");
        printf("___________________________\n");
        for(int i=Q.front;i<=Q.rear;i++){
            printf("%d\t%s\t%d\t\n",Q.items[i].id,Q.items[i].name,Q.items[i].priority);
        }
        printf("\n");
    }
}

int main(){
    int choice;
    queue Q;
    Q.front=0;Q.rear=-1;
    while(1){
        printf("\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display Queue\nEnter your choice:");
		scanf("%d", &choice);
        
        switch(choice){
            case 0: exit(0); break;
            case 1: Q=enqueue(Q); break;
            case 2: Q=dequeue(Q); break;
            case 3: displayQueue(Q); break;
            default: printf("INVALID\n");
        }
    }
    return 0;
}
