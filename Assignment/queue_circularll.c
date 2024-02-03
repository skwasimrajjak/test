//Implementing Queue using Circular Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void enqueue(node** prear, int data);
void dequeue(node** prear);
void displayRear(node** prear);
void displayFront(node** prear);

int main()
{
    node* rear;
    rear = NULL;
    int data, data2, choice;

    while(1){
        printf("\nChoose: \n1. En-Queue\n2. De-Queue\n3. Show Front\n4. Show Rear\n0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                enqueue(&rear,data);
                break;

            case 2:
                dequeue(&rear);
                break;

            case 3:
                displayFront(&rear);
                break;

            case 4:
                displayRear(&rear);
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid Case!\n");
        }
    }

    return 0;
}

//add element at end
void enqueue(node** prear, int data)
{
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if(*prear == NULL)
    {
        *prear = newnode;
        newnode->next = *prear;
    }
    else{
        newnode->next = (*prear)->next;
        (*prear)->next = newnode;
        *prear = newnode;
    }
}

//delete element at beginning
void dequeue(node** prear)
{
    if(*prear == NULL)
    {
        printf("Queue Underflow\n");
    }
       
    else
    {
        node* ptr = (*prear)->next;
        if(ptr == *prear)
        {
            *prear = NULL;
        }
            
        else if(*prear != NULL)
        {
            (*prear)->next = (*prear)->next->next;
            free(ptr);
        }
    }
}

//display element at rear end
void displayRear(node** prear)
{
    if(*prear != NULL)
    {
        printf("Queue Rear: %d\n",(*prear)->data);
    }
    else
    {
        printf("\nQueue Underflow! Please Enter Data.\n");
    }
}

//display element at front end
void displayFront(node** prear)
{
    if(*prear != NULL)
    {
        printf("Queue Front: %d\n",(*prear)->next->data);
    }
    else
    {
        printf("\nQueue Underflow! Please Enter Data.\n");
    }
}