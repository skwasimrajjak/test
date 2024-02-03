//Linked List Program

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* searchKey(Node** phead, int key);
Node* SearchPos(Node** phead, int pos);

void insertBegin(Node **phead, int data);
void append(Node **phead, int data);
void insertAfter(Node *prevNode, int data);
void insertPosition(Node **phead, int data, int pos);

void deleteBeginning(Node** phead);
void deleteEnd(Node** phead);
void deleteAfter(Node* prevNode);
void deletePosition(Node** phead, int pos);
void deleteKey(Node** phead, int key);

void display(Node **phead);
int reverse_display(Node *ptr);

int main(){

    Node *head;
    head=NULL;
    int data, data2, pos, choice, insert, delete;

    while(1){
        printf("\nMenu:\n    1. Insert\n    2. Delete\n    3. Display\n    4. Reverse Display\n    0. EXIT\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
            {
                printf("\nInsert:\n    1. Beginning\n    2. End\n    3. After\n    4. Position\n    0. Back\n");
                printf("Enter choice: ");
                scanf("%d",&insert);
                switch (insert)
                {
                case 1:
                    printf("Enter the Element:");
                    scanf("%d",&data);
                    insertBegin(&head, data);
                    break;

                case 2:
                    printf("Enter the Element:");
                    scanf("%d",&data);
                    append(&head,data);
                    break;
                case 3:
                    printf("Enter data of previous: ");
                    scanf("%d",&data2);
                    printf("Enter the Element:");
                    scanf("%d",&data);
                    insertAfter(searchKey(&head,data2),data);
                    break;
                case 4:
                    printf("Enter position: ");
                    scanf("%d",&pos);
                    printf("Enter the Element: ");
                    scanf("%d",&data);
                    insertPosition(&head, data, pos);
                    break;
                case 0:
                    break;
                default:
                    printf("\nInvalid Choice!\n");
                }
            break;
            }
                
            case 2:
            {
                printf("\nDelete:\n    1. Beginning\n    2. End\n    3. After\n    4. Position\n    5.Element\n 0. Back\n");
                printf("Enter choice: ");
                scanf("%d",&delete);
                switch (delete)
                {
                case 1:
                    deleteBeginning(&head);
                    break;
                case 2:
                    deleteEnd(&head);
                    break;
                case 3:
                    printf("Enter data of previous node: ");
                    scanf("%d",&data2);
                    deleteAfter(searchKey(&head, data2));
                    break;
                case 4:
                    printf("Enter position: ");
                    scanf("%d",&pos);
                    deletePosition(&head, pos);
                    break;
                case 5:
                    printf("Enter Element:");
                    scanf("%d", &data2);
                    deleteKey(&head, data2);
                    break;
                case 0:
                    break;
                default:
                    break;
                }
            break;
            }

            case 3:
                display(&head);
                break;

            case 4:
                printf("Elements in reverse order: ");
                reverse_display(head);
                break;
            case 0:
                exit(0);
                break;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}

//to find Node from given data
Node* searchKey(Node** phead, int key)
{
    Node* ptr = *phead;
    while(ptr->next != NULL && ptr->data != key)
        ptr = ptr->next;
    if(ptr->data == key)
        return ptr;
    else
        return NULL;
}

//to find Node from given position
Node* SearchPos(Node** phead, int pos)
{
    Node* ptr = *phead;
    int i;
    for(i=0; i<pos; i++)
    {
        if((pos-1) != i)
            ptr = ptr->next;
    }
    if(ptr != NULL)
        return ptr;
    else
        return NULL;
}

//to insert item at beginning
void insertBegin(Node **phead, int data)
{
    Node *new_node;
    new_node=(Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if(*phead == NULL)
        *phead = new_node;
    else{
        new_node->next = *phead;
        *phead = new_node;
    }
}

//to insert at end
void append(Node **phead, int data)
{
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if(*phead == NULL)
        *phead = new_node;
    else{
        Node *ptr;
        ptr = *phead;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
}



//insert after given data of node
void insertAfter(Node *prevNode, int data)
{
    if(prevNode==NULL)
    {
        printf("Data not found!");
    }
    else
    {
        Node* new_node;
        new_node = (Node*)malloc(sizeof(Node));
        new_node->data = data;
        new_node->next = NULL;
        new_node->next = prevNode->next;
        prevNode->next = new_node;
    }
}

//insert item at given position
void insertPosition(Node **phead, int data, int pos)
{
    int i;
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node* prevNode = *phead;
    Node* ptr = *phead;

    for(i=0; i<pos; i++){
        if(i==0 && pos==1){
            new_node->next = *phead;
            *phead = new_node;
        }
        else{
            if(i==(pos-1) && ptr!=NULL){
                //prevNode->next = ptr->next;
                new_node->next = ptr;
                prevNode->next = new_node;
            }
            else{
                prevNode = ptr;
                ptr = ptr->next;
            }
        }
    }
}

//delete first Node
void deleteBeginning(Node** phead)
{
    if(*phead != NULL){
        Node* ptr = *phead;
        *phead = (*phead)->next; //*phead = ptr->next;
        free(ptr);
    }
    else
        printf("Empty Linked List!");
}

//delete last Node
void deleteEnd(Node** phead)
{
    if(*phead != NULL){
        Node* ptr = *phead;
        Node* prevNode = *phead;
        while(ptr->next != NULL){
            prevNode = ptr;
            ptr = ptr->next;
        }
        prevNode->next = NULL;
        free(ptr);
    }
    else
        printf("Empty Linked List!");
}

//delete Node after given data of Node
void deleteAfter(Node* prevNode)
{
    if(prevNode==NULL)
    {
        printf("Data not found!");
    }
    else
    {
        Node* ptr = prevNode->next;
        prevNode->next = prevNode->next->next;
        free(ptr);
    }
    
}

//delete Node at given position
void deletePosition(Node** phead, int pos)
{
    Node* prevNode = *phead;
    Node* ptr = *phead;
    int i=0;

    if(pos == 1){
        *phead = prevNode->next;
        free(ptr);
    }
    else{
        while(ptr!= NULL && i!=pos-1){
            prevNode = ptr;
            ptr = ptr->next;
            i++;
        }
        prevNode->next = prevNode->next->next;
        free(ptr);
    }

}

//delete Node by data
void deleteKey(Node** phead, int key)
{
    Node* ptr = *phead;
    Node* prevNode = *phead;
    while(prevNode->data != key){
        prevNode = ptr;
        ptr = ptr->next;
    }
    prevNode->next = prevNode->next->next;        
    free(ptr);
}


//display items in nodes
void display(Node **phead)
{
    Node* ptr = *phead;
    while(ptr != NULL){
        printf("%d, ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//display items in reverse order
int reverse_display(Node *ptr)
{
    if(ptr==NULL)
    {
        return 0;
    }
    else
    {
        reverse_display(ptr->next);
        printf("%d,", ptr->data);
    }
}