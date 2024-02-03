//Reverse Linked List Program

//header files
#include<stdio.h>
#include<stdlib.h>

//creating Linked List datastructure
typedef struct Node{
    int data;
    struct Node *next;
}Node;

//to insert at end
void append(Node **phead, int data){
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

int display(Node* ptr){
    if(ptr == NULL)
        return 0;
    else{
        display(ptr->next);
        printf("%d, ",ptr->data);
    }
}

int main(){
    Node* head = NULL;
    int data;

    printf("Enter elements of Linked List (Enter -1 to stop)\n");
    while(1){
        printf("Enter element: ");
        scanf("%d",&data);
        if(data != -1)
            append(&head,data);
        else
            break;
    }

    display(head);
    return 0;
}