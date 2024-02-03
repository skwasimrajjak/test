//Split a Linked List Program

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

    if(*phead == NULL)
        *phead = newNode;
    else{
        Node* ptr = *phead;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
}

void split(Node** phead1, Node** phead2){
    // Node** phead2 = NULL;
    Node* ptr = *phead1;
    int c = 0, i=0;

    while(ptr != NULL){
        c++;
        ptr = ptr->next;
    }

    ptr = *phead1;
    while(i != (c/2)-1){
        i++;
        ptr = ptr->next;
    }

    *phead2 = ptr->next;
    ptr->next = NULL;
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

    split(&head1,&head2);

    printf("\nElements of 1st splitted Linked List: ");
    display(&head1);
    printf("\nElements of 2nd splitted Linked List: ");
    display(&head2);

    return 0;
}