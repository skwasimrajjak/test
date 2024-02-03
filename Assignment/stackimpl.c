//program for stack implementation

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int top;
	int size;
	int* arr;
}stack;

void init(stack* ptr, int size);
int isfull(stack* ptr);
void push(stack* ptr, int item);
int isempty(stack* ptr);
int pop(stack* ptr);
void display(stack* ptr, int length);
void peek(stack* ptr);

int main()
{
	stack store;
	int len, val, choice, temp;
	printf("Enter number of elements: ");
	scanf("%d",&len);
	init(&store,len);
	
	while(1){
		printf("\nChoose:\n1. Push\n2. Pop\n3. Display\n4. Peek\n0. Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter item to push: ");
				scanf("%d",&val);
				push(&store,val);
				break;
			
			case 2:
				temp = pop(&store);
				if(temp == -999)
					printf("\nStack Underflow!\n");
				else
					printf("\n%d is popped\n",temp);
				break;
				
			case 3:
				display(&store,store.top+1);
				break;
			
			case 4:
				peek(&store);
				break;

			case 0:
				exit(0);
				
			default:
				printf("\nInvalid choice\n");
		}
	}
	
	return 0;
}

//function for initialisation
void init(stack* ptr, int size)
{
	ptr->size = size;
	ptr->top = -1;
	ptr->arr = (int*)malloc(size*sizeof(char));
}

//function to check stack is full or not
int isfull(stack* ptr)
{
	return (ptr->top == ptr->size-1);
}

//function for pushing element in stack
void push(stack* ptr, int item)
{
	if(!isfull(ptr))
		ptr->arr[++ptr->top] = item;
	else
		printf("\nStack Overflow!\n");
}

//function to check stack is empty or not
int isempty(stack* ptr)
{
	return (ptr->top == -1);
}

//function for popping element from stack
int pop(stack* ptr)
{
	if(isempty(ptr))
		return -999;
	else
		return ptr->arr[ptr->top--];
}

//function for displaying elements in stack
void display(stack* ptr, int length)
{
	int i;
	for(i=ptr->top; i>-1; i--)
		printf("%d\n",ptr->arr[i]);
}

void peek(stack* ptr)
{
	printf("%d\n",ptr->arr[ptr->top]);
}