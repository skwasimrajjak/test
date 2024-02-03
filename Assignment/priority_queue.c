//Implementation of priority queue using heap

#include <stdio.h>
#include <stdlib.h>

#define max 20 //size of priority queue

//creating Item of queue
typedef struct Item{
    int data;
    int prior;
}Item;

//creating queue
typedef struct queue{
    Item arr[max];
    int rear;
}Q;

void init(Q* q);
int isFull(Q* q);
int isEmpty(Q* q);
void swap(Item* item1, Item* item2);
Item createItem(Item item, int data, int prior);
void insertHeap(Q* q, Item item);
Item delHeap(Q* q);

int main()
{
    Item item;
    Q q;
    int data, priority, choice;
    init(&q);

    while(1){
        printf("\nChoose:\n1. Insert\n2. Delete\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                printf("Enter priority: ");
                scanf("%d",&priority);
                item = createItem(item, data, priority);
                insertHeap(&q, item);
                break;
                
            case 2:
                if(q.rear != -1){
                    item = delHeap(&q);
                    printf("%d\n",item.data);
                }
                else
                    printf("Queue is empty\n");
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}

//initialise queue
void init(Q* q)
{
    q->rear = -1;
}

//checks if queue is full or not
int isFull(Q* q)
{
    return (q->rear == max-1);
}

//checks if queue is empty or not
int isEmpty(Q* q)
{
    return (q->rear == -1);
}

//swaps items of queue
void swap(Item* item1, Item* item2)
{
    Item temp;
    temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}

//creating item for inserting in queue
Item createItem(Item item, int data, int prior)
{
    item.data = data;
    item.prior = prior;
    return item;
}

//inserting heap
void insertHeap(Q* q, Item item)
{
    int parent, child;
    if(!isFull(q))
    {
        q->arr[++q->rear] = item;
        child = q->rear;
        do{
            parent = (child-1)/2;
            if(q->arr[child].prior > q->arr[parent].prior)
            {
                swap(&q->arr[child], &q->arr[parent]);
            }
            else
            {
                break;
            }
                
            child = parent;
        }while(child != 0);
    }
}

//deleting heap
Item delHeap(Q* q)
{
    int parent, child;
    Item item;
    if(!isEmpty(q))
    {
        parent = child = 0;
        item = q->arr[0];
        q->arr[0] = q->arr[q->rear];
        q->rear--;

        do{
            child = 2*parent + 1;
            if(child > q->rear)  break;

            if(child < q->rear && q->arr[child].prior < q->arr[child+1].prior)
            {
                child = child + 1;
            } 

            if(q->arr[child].prior > q->arr[parent].prior)
            {
                swap(&q->arr[parent], &q->arr[child]);
                parent = child;
            }

            else
                break;
                
        }while(child <= q->rear);
        return item;
    }
}