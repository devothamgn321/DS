#include <stdio.h>
#include <stdlib.h>

#define QUEUE_INIT_CAPACITY 10

typedef struct {
    int id;
    char name[20];
    int time;
} jobs;

typedef struct {
    jobs* items;
    int fidx, ridx;
    int size;
    int capacity;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->capacity = QUEUE_INIT_CAPACITY;
    q->fidx = 0;
    q->ridx = -1;
    q->size = 0;

    q->items = (jobs*) malloc(q->capacity * sizeof(jobs*));
}

void deleteQueue(CircularQueue *q) {
    free(q->items);
}

void enqueue(CircularQueue* q) {
    if (q->size == q->capacity) {
        printf("Reallocating queue. \n");
        q->capacity *= 2;
        q->items = (jobs*) realloc(q->items, q->capacity * sizeof(jobs));
    }

   jobs J;
        printf("Enter the new job details\n"); 
        printf("Enter job id:");
        scanf("%d",&J.id);
        printf("Enter job name:");
        scanf("%s",J.name);
        printf("Enter time required to complete job:");
        scanf("%d",&J.time);
        q->items[++q->ridx]=J;
        printf("Job enqueued\n");
    q->size++;
}

void dequeue(CircularQueue* q) {
    if (q->size == 0) {
        printf("Queue is empty. \n");
        return;
    }

    if(q->fidx>q->ridx){
        printf("Queue is empty\n");
        
    };
    jobs J=*(q->items + q->fidx++);

        printf("Dequeued job-\nid: %d\nName: %s\nTime: %d\n",J.id,J.name,J.time);
        if(q->fidx>q->ridx){
            q->fidx=0;
            q->ridx=-1;
        }
    q->size--;
}

void display(CircularQueue* q) {
    if (q->size == 0) {
        printf("Queue is empty. \n");
        return;
    }

    int i;
    printf("Queue jobs:\n");
    printf("id \tName \tTime \n");
    printf("___\n");
    for (i = 0; i < q->size; i++) {
        jobs J=*(q->items + ((q->fidx + i) % q->capacity));
        printf(" %d\t%s\t%d\t\n",J.id,J.name,J.time);
    }
    printf("\n");
}

void printMenu() {
    printf("1. Enqueue \n");
    printf("2. Dequeue \n");
    printf("3. Display queue \n");
    printf("4. Exit \n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    int isRunning = 1;
    while (isRunning) {
        printMenu();
        printf("Enter your choice: ");
        int ch;
        scanf("%d", &ch);
        switch(ch) {
            case 1: enqueue(&q);
                    display(&q);
                    break;
            case 2: dequeue(&q);
                    display(&q);
                    break;
            case 3: display(&q);
                    break;
            case 4: isRunning = 0;
                    break;
            default:
                    printf("Invalid choice. \n");
        }
    }
    deleteQueue(&q);
    return 0;
}
