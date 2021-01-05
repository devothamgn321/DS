#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE{
    int info;
    struct NODE* left;
    struct NODE* right;
};
typedef struct NODE* node;

node INSERT(node R){
    int i;
    char dir[10];
    node NN=(node)malloc(sizeof(struct NODE));
    printf("Enter the info:");
    scanf("%d",&NN->info);
    NN->left=NN->right=NULL;
    if(R==NULL){
        printf("node inserted as the root\n");
        return NN;
    }
    direct: printf("Enter the direction:");
    scanf("%s",dir);
    node CN=R,PN=NULL;  
    for(i=0;i<strlen(dir);i++){
        PN=CN;
        if(CN==NULL) break;
        if(dir[i]=='L' || dir[i]=='l') CN=CN->left;
        else if(dir[i]=='R' || dir[i]=='r') CN=CN->right;
        else break;
    }
    if(i!=strlen(dir) || CN!=NULL){
        printf("Invalid direction or node already exit at given direction\n");
        goto direct;
    }
    if(dir[i-1]=='L' || dir[i-1]=='l') PN->left=NN; 
    else if(dir[i-1]=='R' || dir[i-1]=='r') PN->right=NN; 
    printf("Insertion successfull\n");
    return R;
}

void inOrder(node R){
    if(R==NULL) return;
    inOrder(R->left);
    printf("%d ",R->info);
    inOrder(R->right);
}
void postOrder(node R){
    if(R==NULL) return;
    postOrder(R->left);
    postOrder(R->right);
    printf("%d ",R->info);
}
void preOrder(node R){
    if(R==NULL) return;
    printf("%d ",R->info);
    preOrder(R->left);
    preOrder(R->right);
}

void displayTree(node R){
    if(R==NULL){
        printf("Tree is empty\n");
        return;
    }
    printf("\nInOrder Traversal: "); inOrder(R);
    printf("\nPostOrder Traversal: "); postOrder(R);
    printf("\nPreOrder Traversal: "); preOrder(R);
    printf("\n");
}


node SEARCH(node R, int info,node* PN)   
{
    if(R==NULL) return NULL;
    node NS=NULL;   
    if(R->info==info){
        NS=R;
    }
    if(NS==NULL){
        *PN=R;
        NS=SEARCH(R->left,info,PN);
    }
    if(NS==NULL){
        *PN=R;
        NS=SEARCH(R->right,info,PN);
    }
    return NS;
}
node DELETE(node R){
    if(R==NULL){
        printf("Tree is empty\n");
        return NULL;
    }
    int info;
    printf("Enter the info of the node to be deleted:");
    scanf("%d",&info);
    
   
    if(R->info==info && (R->left!=NULL || R->right!=NULL)){
        printf("Root node can't be deleted unless it has no child.\n");
        return R;
    }
    
    if(R->info==info && R->left==NULL && R->right==NULL){
        printf("Deleted root node with info = %d\n",R->info);
        free(R);
        return NULL;
    }
    
    
    node PN;
    node ND=SEARCH(R,info,&PN);  
    if(ND==NULL){
        printf("Node with info = %d doesn't exist in the tree\n",info);
        return R;
    }else{
        printf("Deleting node info = %d and it's parent node info = %d\n",ND->info,PN->info);
    }

 
    if(ND->left==NULL && ND->right==NULL){
        if(ND==PN->left) PN->left=NULL;
        else PN->right=NULL;
        free(ND);
    }

    
    else if((ND->left!=NULL && ND->right==NULL)
            ||(ND->left==NULL && ND->right!=NULL)){
                
                if(ND->right==NULL)   
                {
                    if(ND==PN->left) PN->left=ND->left;
                    else PN->right=ND->left;
                }
                                        
                else{
                    if(ND==PN->left) PN->left=ND->right;
                    else PN->right=ND->right;
                }
            free(ND);
        }

    else{
        node IS=ND->right, ISP = ND;
      
        while(IS->left!=NULL){
            ISP=IS;
            IS=IS->left;
        }
        ND->info=IS->info;
        if(IS->left==NULL && IS->right==NULL){
            if(IS==ISP->left) ISP->left=NULL;
            else ISP->right=NULL;
        }else{
            if(IS==ISP->left) ISP->left=IS->right;
            else ISP->right=IS->right;
        }
        free(IS);
    }
    printf("Node deleted with info: %d\n",info);
    return R;
}





int main(){
    int choice,info;
    node root=NULL;
    node NS=NULL;
    node PN=NULL;
    while(1){
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: root=INSERT(root); break;
            case 2: displayTree(root); break;
            
            case 3: root = DELETE(root);
                    displayTree(root);
                    break;
            case 4: exit(0);
            
            default: printf("INVALID");
        }
    }
}