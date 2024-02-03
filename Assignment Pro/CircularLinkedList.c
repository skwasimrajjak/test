//Circular Linked List Program

//header files
#include<stdio.h>
#include<stdlib.h>

//creating Linked List datastructure
typedef struct Node{
    int data;
    struct Node *next;
}Node;

//insert elements at end of Linked List
void append(Node** prear, int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*prear == NULL){
        *prear = newNode;
        newNode->next = *prear;
    }
    else{
        newNode->next = (*prear)->next;
        (*prear)->next = newNode;
        *prear = newNode;
    }
}

//insert at beginning
void insertBeginning(Node** prear, int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*prear == NULL){
        *prear = newNode;
        newNode->next = *prear;
    }
    else{
        newNode->next = (*prear)->next;
        (*prear)->next = newNode;
    }
}

//delete last node
void deleteEnd(Node** prear){
    Node* prev = (*prear)->next;
    Node* ptr = (*prear)->next;
    while(ptr != *prear){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    *prear = prev;
    free(ptr);
}

//delete first node
void deleteBeginning(Node** prear){
    Node* ptr = (*prear)->next;
    (*prear)->next = (*prear)->next->next;
    free(ptr);
}

//returns address of Node of given data
Node* searchKey(Node** prear, int data){
    Node* ptr = (*prear)->next;
    while(ptr != *prear && ptr->data != data)
        ptr = ptr->next;
    if(ptr->data == data)
        return ptr;
    else
        return NULL;
}

//insert after given Node
void insertAfter(Node* prev, int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = prev->next;
    prev->next = newNode;
}

//delete after given Node
void deleteAfter(Node* prev){
    Node* delNode = prev->next;
    prev->next = prev->next->next;
    free(delNode);
}

//display
void display(Node** prear){
    Node* ptr = *prear;
    do{
        ptr = ptr->next;
        printf("%d, ", ptr->data);
    }while(ptr != *prear);
    printf("\n");
}

int main(){
    Node* rear;
    rear = NULL;
    Node* prev;
    int data, data2, choice;

    while(1){
        printf("\nCHOICES-\n1. TO ENTER AT BEGINNING\n2. TO ENTER AT END\n3. TO ENTER AFTER NODE\n4. TO DELETE AT BEGINNING\n5. TO DELETE AT END\n6. TO DELETE AFTER NODE\n7. TO DISPLAY\n0. TO EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice){

            case 2:
                printf("Enter data to be appended: ");
                scanf("%d",&data);
                append(&rear,data);
                break;

            case 1:
                printf("Enter data to be inserted at beginning: ");
                scanf("%d",&data);
                insertBeginning(&rear,data);
                break;

            case 3:
                printf("Enter data after which data to be inserted: ");
                scanf("%d",&data2);
                printf("Enter data to be inserted: ");
                scanf("%d",&data);

                prev = searchKey(&rear,data2);
                if(prev == rear)
                    append(&rear, data);
                else
                    insertAfter(prev, data);
                break;

            case 4:
                deleteBeginning(&rear);
                break;

            case 5:
                deleteEnd(&rear);
                break;

            case 6:
                printf("Enter data after which data to be deleted: ");
                scanf("%d",&data2);

                prev = searchKey(&rear,data2);
                if(prev->next == rear)
                    deleteEnd(&rear);
                else
                    deleteAfter(prev);
                break;

            case 7:
                display(&rear);
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    
    return 0;
}