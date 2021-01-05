#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

typedef struct node* Node;

Node createCLL() {
    Node header = (Node) malloc(sizeof(struct node));
    header->info = 0;
    header->link = NULL;
    return header;
}

void display(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }

    Node tempNode = H->link->link;
    do {
        printf("%d ", tempNode->info);
        tempNode = tempNode->link;
    } while (tempNode != H->link->link);
    putchar('\n');
}

void insertFront(Node H) {
    H->info++;
    Node newNode = (Node) malloc(sizeof(struct node));
    printf("Enter item to insert: ");
    scanf("%d", &newNode->info);

    if (H->link == NULL) {
        newNode->link = newNode;
        H->link = newNode;
        return;
    }

    newNode->link = H->link->link;
    H->link->link = newNode;
}

void insertRear(Node H) {
    H->info++;
    Node newNode = (Node) malloc(sizeof(struct node));
    printf("Enter item to insert: ");
    scanf("%d", &newNode->info);

    if (H->link == NULL) {
        newNode->link = newNode;
        H->link = newNode;
        return;
    }

    newNode->link = H->link->link;
    H->link->link = newNode;
    H->link = newNode;
}

void deleteFront(Node H) {
    if (H->info == 0) {
        printf("Empty List");
        return;
    }
    H->info--;

    Node last = H->link;
    Node deleteNode = last->link;
    
    // single element
    if (deleteNode->link == deleteNode) {
        H->link = NULL;
    }

    last->link = deleteNode->link;
    free(deleteNode);
}

void deleteRear(Node H) {
    if (H->info == 0) {
        printf("Empty List");
        return;
    }
    H->info--;

    Node last = H->link;
    Node deleteNode = last;
    
    if (deleteNode->link == deleteNode) {
        H->link = NULL;
    } else {
        Node prevNode = deleteNode->link;
        while (prevNode->link != deleteNode)
            prevNode = prevNode->link;
        
        prevNode->link = deleteNode->link;
        H->link = prevNode;
    }

    free(deleteNode);
}

void insertAtPos(Node H) {
    int pos;
    printf("Enter position to insert at: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > H->info + 1) {
        printf("Invalid position.\n");
        return;
    }

    Node newNode = (Node) malloc(sizeof(struct node));
    printf("Enter item to insert into list: ");
    scanf("%d", &newNode->info);

    if (H->link == NULL) {
        newNode->link = newNode;
        H->link = newNode;
    } else if (pos == H->info + 1) {
        newNode->link = H->link->link;
        H->link->link = newNode;
        H->link = newNode;
    } else {
        int cnt = 1;
        Node tempNode = H->link->link, prevNode = H->link;
        while (cnt < pos) {
            prevNode = tempNode;
            tempNode = tempNode->link;
            cnt++;
        }

        prevNode->link = newNode;
        newNode->link = tempNode;
    }

    H->info++;
}

void deleteAtPos(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }

    int pos;
    printf("Enter position to delete at: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > H->info) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1 && H->link->link == H->link) {
        free(H->link);
        H->link = NULL;
        return;
    }

    int cnt = 1;
    Node tempNode = H->link->link, prevNode = H->link;
    while (cnt < pos) {
        prevNode = tempNode;
        tempNode = tempNode->link;
        cnt++;
    }
    prevNode->link = tempNode->link;
    free(tempNode);

    if (pos == H->info) {
        H->link = prevNode;
    }

    H->info--;
}

void insertByOrder(Node H) {
    H->info++;
    Node newNode = (Node) malloc(sizeof(struct node));
    printf("Enter element to insert by order: ");
    scanf("%d", &newNode->info);

    if (H->link == NULL) {
        newNode->link = newNode;
        H->link = newNode;
        return;
    }

    if (H->link->info < newNode->info) {
        newNode->link = H->link->link;
        H->link->link = newNode;
        H->link = newNode;
        return;
    }

    Node tempNode = H->link->link, prevNode = H->link;

    while (tempNode->info < newNode->info){
        prevNode = tempNode;
        tempNode = tempNode->link;
    }

    newNode->link = tempNode;
    prevNode->link = newNode;
}

void deleteByKey(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }

    int key;
    printf("Enter your key: ");
    scanf("%d", &key);

    if (H->link->link->info == key) {
        H->info--;
        if (H->link == H->link->link) {
            free(H->link);
            H->link = NULL;
            return;
        }

        Node deleteNode = H->link->link;
        H->link->link = deleteNode->link;
        free(deleteNode);
        return;
    }

    Node tempNode = H->link->link, prevNode = H->link;
    do {
        prevNode = tempNode;
        tempNode = tempNode->link;
    } while (tempNode != H->link->link && tempNode->info != key);

    if (tempNode == H->link->link) {
        printf("Key not found in list.\n");
        return;
    }

    H->info--;
    prevNode->link = tempNode->link;
    if (tempNode == H->link) H->link = prevNode;
    free(tempNode);
}

void search(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }

    int key;
    printf("Enter your key to search: ");
    scanf("%d", &key);

    if (H->link->link->info == key) {
        printf("Element %d found at position 1", key);
        return;
    }

    int cnt = 1;
    Node tempNode = H->link->link;
    do {
        tempNode = tempNode->link;
        cnt++;
    } while (tempNode != H->link->link && tempNode->info != key);

    if (tempNode == H->link->link) {
        printf("Key not found in list.\n");
        return;
    }

    printf("Element %d found at position %d\n", key, cnt);
}

int main() {
    Node header = createCLL();
    int isRunning = 1, ch;
    while(isRunning==1)
    {
        printf("0:Display\n1:Insert Front\n2:Insert Rear\n3:Delete Front\n4:Delete Rear\n5:Insert at Position\n6:Delete at position\n7:Insert by Order\n8:Delete by Key\n9:Search by key\n10:Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0: display(header);
                break;
        case 1: insertFront(header);
                display(header);
                break;            
        case 2: insertRear(header);
                display(header);
                break;
        case 3: deleteFront(header);
                display(header);
                break;
        case 4: deleteRear(header);
                display(header);
                break;                
        case 5: insertAtPos(header);
                display(header);
                break;
        case 6: deleteAtPos(header);
                display(header);
                break;     
        case 7:insertByOrder(header);
                display(header);
                break;
        case 8: deleteByKey(header);
                display(header);
                break;
        case 9: search(header);
                break;                                  
        default: exit(0);
        }
    }
    return 0;
}
