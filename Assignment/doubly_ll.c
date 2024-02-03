//Doubly Linked List Program

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


Node* searchKey(Node** phead1, Node** phead2, int data);

void append(Node **phead1, Node** phead2, int data);
void insertBeginning(Node **phead1, Node** phead2, int data);
void insertAfter(Node* prev, int data);
void insertBefore(Node* post, int data);

void deleteEnd(Node** phead2);
void deleteBeginning(Node** phead1);
void deleteBefore(Node* post);
void deleteAfter(Node* prev);

void displayForward(Node** phead1);
void displayBackward(Node** phead2);


int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* post;
    Node* prev;
    int data, data2, choice;
    int insert, delete, display;

    while(1){
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Display\n0. EXIT\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: //insert 
            {
                printf("\nInsert:\n1. Beginning\n2. End\n3. Before\n4. After\n0. Back\n");
                printf("Enter choice: ");
                scanf("%d",&insert);
                switch (insert)
                {
                case 1:
                    printf("Enter item: ");
                    scanf("%d",&data);
                    insertBeginning(&head1, &head2, data);
                    break;
                case 2:
                    printf("Enter item: ");
                    scanf("%d",&data);
                    append(&head1, &head2, data);
                    break;
                case 3:
                    printf("Enter data of Post node: ");
                    scanf("%d",&data2);
                    printf("Enter item to be added: ");
                    scanf("%d",&data);

                    post = searchKey(&head1, &head2, data2);
                    if(head1 == post)
                    {
                        insertBeginning(&head1, &head2, data);
                    }
                    else if(post != NULL)
                    {
                        insertBefore(post, data);
                    }
                    else
                    {
                        printf("Post node data Not Fount!");
                    }
                    break;
                case 4:
                    printf("Enter data of Previous node: ");
                    scanf("%d",&data2);
                    printf("Enter item to be added: ");
                    scanf("%d",&data);

                    prev = searchKey(&head1, &head2, data2);
                    if(head2 == prev)
                    {
                        append(&head1, &head2, data);
                    }
                	   
				    else if(prev != NULL)
                    {
                        insertAfter(prev, data);
                    }
                        
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid Choice!");
                }
            }
            break;

            case 2: //delete
            {
                printf("\nDelete:\n1. Beginning\n2. End\n3. Before\n4. After\n0. Back\n");
                printf("Enter choice: ");
                scanf("%d",&delete);
                switch (delete)
                {
                case 1:
                    deleteBeginning(&head1);
                    break;
                case 2:
                    deleteEnd(&head2);
                    break;
                case 3:
                    printf("Enter data of Post node: ");
                    scanf("%d",&data2);

                    post = searchKey(&head1, &head2, data2);
                    if(post == head1->right)
                    {
                        deleteBeginning(&head1);
                    }   
                    else if(post != NULL)
                    {
                        deleteBefore(post);          
                    }
                    else
                    {
                        printf("Post node data not found.");
                    }
                    break;
                case 4:
                    printf("Enter data of Previous node: ");
                    scanf("%d",&data2);
                
                    prev = searchKey(&head1, &head2, data2);
                    if(prev == head2->left)
                    {
                        deleteEnd(&head2);
                    }
                    else if(prev != NULL)
                    {
                        deleteAfter(prev);
                    }
                    else
                    {
                        printf("Previous node data Not found,");
                    }
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid Choice!");
                }
            }
            break;

            case 3: //display
            {
                printf("\nDisplay:\n1. Forward\n2. Backward\n0. Back\n");
                printf("Enter choice: ");
                scanf("%d",&display);
                switch (display)
                {
                case 1:
                    displayForward(&head1);
                    break;
                case 2:
                    displayBackward(&head2);
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid Choice!");
                }
            }
            break;

            case 0: //exit
                exit(0);

            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}

//to insert item at beginning
void append(Node **phead1, Node** phead2, int data){
    Node *new_node;
    new_node=(Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if(*phead1 == NULL){
        *phead1 = new_node;
        *phead2 = new_node;
    }
    else{
        (*phead2)->right = new_node;
        new_node->left = *phead2;
        *phead2 = new_node;
    }
}

//to insert at end
void insertBeginning(Node **phead1, Node** phead2, int data){
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if(*phead1 == NULL){
        *phead1 = new_node;
        *phead2 = new_node;
    }
    else{
        new_node->right = *phead1;
        (*phead1)->left = new_node;
        *phead1 = new_node;
    }
}

//search Node with data
Node* searchKey(Node** phead1, Node** phead2, int data){
    Node* ptr1 = *phead1;
    Node* ptr2 = *phead2;

    if(*phead1 != NULL){
        while(ptr1->data != data && ptr2->data != data)
		{
            ptr1=ptr1->right;
            ptr2=ptr2->left;
        }
        if(ptr1->data == data)
		{
            return ptr1;
        }
        else if(ptr2->data == data)
        {
            return ptr2;
        }
    }
    else
        return NULL;
}

//to insert Node after given Node
void insertAfter(Node* prev, int data){
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    new_node->left = prev;
    new_node->right = prev->right;
    prev->right->left = new_node;
    prev->right = new_node;
}

//to insert Node before given Node
void insertBefore(Node* post, int data){
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    new_node->right = post;
    new_node->left = post->left;
    post->left->right = new_node;
    post->left = new_node;
}

//to delete Node at end
void deleteEnd(Node** phead2){
    if(phead2 != NULL){
        Node* delNode = *phead2;
        delNode->left->right = NULL;
        *phead2 = delNode->left;
        free(delNode);
    } 
}

//to delete Node at beginning
void deleteBeginning(Node** phead1){
    if(phead1 != NULL){
        Node* delNode = *phead1;
        delNode->right->left = NULL;
        *phead1 = delNode->right;
        free(delNode);
    }
}

//to delete Node before given Node
void deleteBefore(Node* post){
    Node* delNode = post->left;
    post->left = post->left->left;
    delNode->left->right = post;
    free(delNode);
}

//to delete Node after given Node
void deleteAfter(Node* prev){
    Node* delNode = prev->right;
    prev->right = delNode->right;
    delNode->right->left = prev;
    free(delNode);
}

//display from start to end
void displayForward(Node** phead1){
    Node* ptr = *phead1;
    while(ptr != NULL){
        printf("%d, ",ptr->data);
        ptr = ptr->right;
    }
    printf("\n");
}

//display from end to start
void displayBackward(Node** phead2){
    Node* ptr = *phead2;
    while(ptr != NULL){
        printf("%d, ",ptr->data);
        ptr = ptr->left;
    }
    printf("\n");
}
