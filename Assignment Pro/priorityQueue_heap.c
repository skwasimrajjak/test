//Heap Program

//header files
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

//initialise queue
void init(Q* q){
    q->rear = -1;
}

//checks if queue is full or not
int isFull(Q* q){
    return (q->rear == max-1);
}

//checks if queue is empty or not
int isEmpty(Q* q){
    return (q->rear == -1);
}

//swaps items of queue
void swap(Item* p, Item* q){
    Item temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

//creating item for inserting in queue
Item createItem(Item item, int data, int prior){
    item.data = data;
    item.prior = prior;
    return item;
}

//inserting heap
void insertHeap(Q* q, Item x){
    int p, c;
    if(!isFull(q)){
        q->arr[++q->rear] = x;
        c = q->rear;
        do{
            p = (c-1)/2;
            if(q->arr[c].prior > q->arr[p].prior)
                swap(&q->arr[c], &q->arr[p]);
            else
                break;
            c = p;
        }while(c != 0);
    }
}

//deleting heap
Item delHeap(Q* q){
    int p, c;
    Item z;
    if(!isEmpty(q)){
        p = c = 0;
        z = q->arr[0];
        q->arr[0] = q->arr[q->rear];
        q->rear--;

        do{
            c = 2*p + 1;
            if(c > q->rear)
                break;
            if(c < q->rear && q->arr[c].prior < q->arr[c+1].prior)
                c = c + 1;
            if(q->arr[c].prior > q->arr[p].prior){
                swap(&q->arr[p], &q->arr[c]);
                p = c;
            }
            else
                break;
        }while(c <= q->rear);
        return z;
    }
}

int main(){
    Item item;
    Q q;
    int data, priority, choice;
    init(&q);

    while(1){
        printf("\nCHOICES-\n1. INSERT\n2. DELETE\n0. EXIT\n");
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