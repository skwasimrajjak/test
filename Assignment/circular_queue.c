//implement a circular Queue by using array

#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int front;
    int rear;
    int cap;
    int size;
    int *arr;
}Q;

int init(Q *q, int cap);
int isFull(Q* q);
int isEmpty(Q* q);
void enque(Q* q, int item);
int deque(Q* q);
void showFront(Q* q);
void showRear(Q* q);

int main(){
    int size, item, element;
    Q q;
    int choice;
    printf("Enter full capacity of stack: ");
    scanf("%d",&size);
    
    init(&q,size);
    while(1)
    {
        printf("\nChoose:\n1. En-Queue\n2. De-Queue\n3. Show Front\n4. Show Rear\n0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(!isFull(&q))
                {
                    printf("Enter item: ");
                    scanf("%d",&item);
                    enque(&q, item);
                }
                else
                {
                    printf("\nQueue Overflow!\n");
                }
                    
                break;

            case 2:
                element = deque(&q);
                if(element != 404)
                {
                    printf("%d\n",element);
                }
                else
                {
                    printf("\nQueue Underflow!\n");
                }
                   
                break;

            case 3:
                if(!isEmpty(&q))
                {
                    showFront(&q);
                } 
                else
                {
                    printf("\nEmpty Queue\n");
                }
                break;

            case 4:
                if(!isEmpty(&q))
                {
                    showRear(&q);
                }
                else
                {
                    printf("\nEmpty Queue\n");
                }
                break;

            case 0:
                exit(0);
                break;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

//initialising queue
int init(Q *q, int cap)
{
    q->cap = cap;
    q->size = 0;
    q->front = q->rear = -1;
    q->arr = (int*)malloc(cap*sizeof(int));
}

//to find if queue is full
int isFull(Q* q)
{
    return(q->front==0 && q->rear==q->cap-1 || q->rear+1==q->front); //returns 0 if not full
}

//to find if queue is empty
int isEmpty(Q* q)
{
    return(q->front == -1); 
}

//enqueue operation
void enque(Q* q, int item)
{
    if(!isFull(q))
    {
        if(q->front==-1 && q->rear==-1)
            q->front = q->rear = 0;
        else if(q->rear == q->cap-1)
            q->rear = 0;
        else
            q->rear=q->rear+1;

        q->arr[q->rear] = item;
        q->size = q->size+1;
    }
}

//dequeue operation
int deque(Q* q)
{
    int item;
    if(!isEmpty(q))
    {
        item = q->arr[q->front];
        q->size = q->size-1;
        if(q->front == q->rear)
            q->front=q->rear=-1;
        else if(q->front == q->cap-1)
            q->front = 0;
        else
            q->front = q->front+1;
        return item;
    }
    else
        return 404;
}

//to show element at front
void showFront(Q* q)
{
    printf("Element at front: %d\n",q->arr[q->front]);
}

//to show element at rear
void showRear(Q* q)
{
    printf("Element at rear: %d\n",q->arr[q->rear]);
}