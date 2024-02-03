//Merge 2 Linked Lists Program

//header files
#include<stdio.h>
#include<stdlib.h>

//creating Linked List datastructure
typedef struct Node{
    int data;
    struct Node *next;
}Node;

//insert elements at end of Linked List
void append(Node** phead, int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*phead == NULL){
        *phead = newNode;
    }
    else{
        Node* ptr = *phead;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

//function to merge two Linked Lists
void merge(Node** phead1, Node** phead2){
    Node* ptr1 = *phead1;
    Node* ptr2 = *phead2;

    while(ptr1->next != NULL){
        ptr1 = ptr1->next;
    }
    ptr1->next = ptr2;
}

//display Linked List
void display(Node **phead){
    Node* ptr = *phead;
    while(ptr != NULL){
        printf("%d,",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;
    int data;

    printf("Enter elements of 1st Linked List (Enter -1 to stop)\n");
    while(1){
        printf("Enter element: ");
        scanf("%d",&data);
        if(data != -1)
            append(&head1,data);
        else
            break;
    }
    
    printf("Enter elements of 2nd Linked List (Enter -1 to stop)\n");
    while(1){
        printf("Enter element: ");
        scanf("%d",&data);
        if(data != -1)
            append(&head2,data);
        else
            break;
    }

    printf("\nItems of 1st Linked List: ");
    display(&head1);
    printf("\nItems of 2nd Linked List: ");
    display(&head2);

    merge(&head1, &head2);
    printf("\nItems of Merged Linked List: ");
    display(&head1);

    return 0;
}
