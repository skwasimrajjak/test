//Implementation of Stack Using Linked List Program

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

//add at top
//insertBeginnning
void push(Node** phead, int data){
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

//delete from top
//deleteBeginning
int pop(Node** phead){
    if(*phead != NULL){
        int x;
        Node* ptr = *phead;
        *phead = (*phead)->next; //*phead = ptr->next;
        x = ptr->data;
        free(ptr);
        return x;
    }
    else
        return -1;
}

//prints items of Stack
void display(Node** phead){
    Node* ptr = *phead;
    while(ptr != NULL){
        printf("%d, ",ptr->data);
        ptr = ptr->next;
    }
}

//returns item at top of Stack
int peek(Node** phead){
    Node* ptr = *phead;
    return (ptr->data);
}


int main(){

    Node* head = NULL;
    int choice, data;

    while(1){
        printf("\nCHOICES-\n1. PUSH\n2. POP\n3. DISPLAY\n4. PEEK\n0. EXIT\n");
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
                printf("\nPopped item: %d\n",data);
                break;

            case 3: //display
                display(&head);
                printf("\n");
                break;

            case 4: //peek
                data = peek(&head);
                printf("\nItem at top: %d\n",data);
                break;

            case 0: //exit
                exit(0);

            default: //invalid
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}