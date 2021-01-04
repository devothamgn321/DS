#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int info;
    struct node *llink, *rlink;
};

typedef struct node* Node;

Node insert(Node root) {
    Node newNode = (Node) malloc(sizeof(struct node));
    newNode->llink = newNode->rlink = NULL;

    printf("Enter info to insert into tree: ");
    scanf("%d", &newNode->info);

    if (root == NULL)
        return newNode;

    int i, n;
    Node curNode, parentNode;
    char posStr[10];
    do {
        printf("Enter position to insert the element: ");
        scanf("%s", posStr);

        n = strlen(posStr);
        curNode = root, parentNode = NULL;
        for (i = 0; i < n; i++) {
            if (curNode == NULL)
                break;
            
            parentNode = curNode;
            switch(posStr[i]) {
                case 'L':
                case 'l':
                    curNode = curNode->llink;
                    break;

                case 'R':
                case 'r':
                    curNode = curNode->rlink;
                    break;
            }
        }
    } while (i != n || curNode != NULL);

    switch(posStr[i-1]) {
        case 'L':
        case 'l':
            parentNode->llink = newNode;
            break;
        case 'R':
        case 'r':
            parentNode->rlink = newNode;
            break;
    }

    return root;
}



// DFS: proorder, inorder, postorder

void preorder_traversal(Node root) {
    if (root == NULL)
        return;

    printf("%d ", root->info);
    preorder_traversal(root->llink);
    preorder_traversal(root->rlink);
}

void inorder_traversal(Node root) {
    if (root == NULL)
        return;

    inorder_traversal(root->llink);
    printf("%d ", root->info);
    inorder_traversal(root->rlink);
}

void postorder_traversal(Node root) {
    if (root == NULL)
        return;

    postorder_traversal(root->llink);
    postorder_traversal(root->rlink);
    printf("%d ", root->info);
}

// BFS

typedef struct {
    Node items[100];
    int fidx, ridx;
} Queue;

void initQueue(Queue* q) {
    q->fidx = 0;
    q->ridx = -1;
}

int isEmpty(Queue* q) {
    return q->fidx > q->ridx;
} 

void enqueue(Queue* q, Node n) {
    if (q->ridx == 99) {
        printf("Queue is full\n");
        return;
    }
    q->items[++q->ridx] = n;
}

Node dequeue(Queue* q) {
    if (isEmpty(q))
        return NULL;

    Node p = q->items[q->fidx++];
    if (isEmpty(q))
        initQueue(q);
    
    return p;
}

void levelorder_traversal(Node root) { 
    if (root == NULL) {
        printf("Tree is empty. \n");
        return;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    
    Node curNode;
    do {
        curNode = dequeue(&q);

        printf("%d ", curNode->info);
        if (curNode->llink != NULL) enqueue(&q, curNode->llink);
        if (curNode->rlink != NULL) enqueue(&q, curNode->rlink);
    } while (!isEmpty(&q));
}

void display(Node root) {
    if (root == NULL) {
        printf("Tree is empty. \n");
        return;
    }

    printf("DFS: \n");
    printf("Pre-order traversal: ");
    preorder_traversal(root);
    printf("\nIn-order traversal: ");
    inorder_traversal(root);
    printf("\nPost-order traversal: ");
    postorder_traversal(root);

    printf("\n\nBFS (Level order traversal): ");
    levelorder_traversal(root);
    putchar('\n');
}

Node search(Node root, int key, Node* parentNode) {
    Node searchNode = NULL;

    if (root == NULL)
        return NULL;
    
    if (key == root->info)
        return root;
    
    *parentNode = root;

    if (searchNode == NULL)
        searchNode = search(root->llink, key, parentNode);
    
    if (searchNode == NULL) {
        *parentNode = root;
        searchNode = search(root->rlink, key, parentNode);
    }

    return searchNode;
}

void searchUtil(Node root) {
    int key;
    Node parentNode = NULL, searchNode;
    printf("Enter key to search: ");
    scanf("%d", &key);

    searchNode = search(root, key, &parentNode);
    
    if (searchNode) {
        if (parentNode)
            printf("Key %d was found with parent %d\n", searchNode->info, parentNode->info);
        else
            printf("Key %d was found at the root\n", searchNode->info);
    } else {
        printf("Key %d not found.\n", key);
    }
}

int countLeafNodes(Node root) {
    if (root == NULL)
        return 0;
    
    if (root->llink == NULL && root->rlink == NULL)
        return 1;
    else
        return countLeafNodes(root->llink) + countLeafNodes(root->rlink);
}



void printMenu() {
    printf("1. Insert element into tree\n");
    printf("2. Display all traversals of the tree\n");
    printf("3. Search key in tree\n");
    printf("4. Count leaf nodes\n"); 
    printf("5. Exit\n");
}


int main() {
    Node root = NULL, copyRoot = NULL;

    int isRunning = 1;
    while (isRunning) {
        printMenu();
        printf("Enter your choice: ");
        int ch;
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                root = insert(root);
                break;
            case 2:
                display(root);
                break;
            case 3:
                searchUtil(root);
                break;
            case 4: 
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
             case 5:
                isRunning = 0;
                break;

              default:
                printf("Invalid choice\n");
        }
    }

   

    return 0;
}
