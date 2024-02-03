//Implementation of Stack Using Linked List Program

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void push(Node** phead, int data);
int pop(Node** phead);
int peek(Node** phead);




int main(){

    Node* head = NULL;
    int choice, data;

    while(1){
        printf("\nChoose:\n1. Push\n2. Pop\n3. Peek\n0. EXIT\n");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: //push
                printf("\nEnter element: ");
                scanf("%d", &data);
                push(&head,data);
                break;

            case 2: //pop
                data = pop(&head);
                if(data==-9999)
                {
                    printf("\nStack Underflow!");
                }
                else
                {
                    printf("\nPopped item: %d\n",data);
                }
                
                break;

            case 3: //peek
                data = peek(&head);
                if(data==-9999)
                {
                    printf("Stack is Empty!");
                }
                else
                {
                    printf("\nItem at top: %d\n",data);
                }
                
                break;
    
            case 0: //exit
                exit(0);

            default: //invalid
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}

//insertBeginnning or add from top
void push(Node** phead, int data)
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


//deleteBeginning or delete from top
int pop(Node** phead)
{
    if(*phead != NULL)
    {
        int x;
        Node* ptr = *phead;
        *phead = (*phead)->next; //*phead = ptr->next;
        x = ptr->data;
        free(ptr);
        return x;
    }
    else
        return -9999;
}


//returns item at top of Stack
int peek(Node** phead)
{
    if(*phead==NULL)
    {
        return -9999;
    }
    else
    {
        Node* ptr = *phead;
        return (ptr->data);
    }
    
}