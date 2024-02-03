//postfix evaluation program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack{
	int top;
	int size;
	char* arr;
}stack;

void init(stack* ptr, int size);
void push(stack* ptr, int item);
int isempty(stack* ptr);
char pop(stack* ptr);
int isoperator(char ch);
char peek(stack* s);
char operation(char a, char b, char operator);
void postfixEval(stack* s, char* postfix);


int main()
{
	stack store; //stack storing the operators
	init(&store, 100);
	char postfix[100];
	
    printf("\nEnter postfix expression: ");
	fgets(postfix, 100, stdin); //used instead of 'gets' for it has limit of data entry

	postfixEval(&store, postfix);
	printf("\nAnswer: %c\n\n",peek(&store));
	return 0;
}

//function for initialising stack
void init(stack* ptr, int size)
{
	ptr->size = size;
	ptr->top = -1;
	ptr->arr = (char*)malloc(size*sizeof(char));
}

//function to push in stack
void push(stack* ptr, int item)
{
	ptr->arr[++ptr->top] = item;
}

//to check if stack is empty or not
int isempty(stack* ptr)
{
	return (-1 == ptr->top);
}

//function for popping from stack
char pop(stack* ptr)
{
	if(!isempty(ptr))
		return ptr->arr[ptr->top--];
}

//function to check for operator
int isoperator(char ch)
{
	if(ch == '^' || ch == '/' || ch == '*' || ch == '%' || ch == '+' || ch == '-')
		return 1;
	else
		return 0;
}

//function to see element at top of stack
char peek(stack* s)
{
	return s->arr[s->top];
}

//function for opeation
char operation(char a, char b, char operator)
{
	char res;
	if(operator == '^')
		res = (a-48) ^ (b-48); //ASCII value of string numeric starts from 48
	else if(operator == '/')
		res = (a-48) / (b-48);
	else if(operator == '*')
		res = (a-48) * (b-48);
	else if(operator == '%')
		res = (a-48) % (b-48);
	else if(operator == '+')
		res = (a-48) + (b-48);
	else if(operator == '-')
		res = (a-48) - (b-48);
 	return (res+48); 
}

//function to evaluate postfix expression
void postfixEval(stack* s, char* postfix)
{
	char a, b, c;
	int i;
	int ilen = strlen(postfix);
	for(i=0; i<ilen; i++){
		if(isalnum(postfix[i]))
			push(s, postfix[i]);
		else if(isoperator(postfix[i])){
			a = pop(s);
			b = pop(s);
			c = operation(b,a,postfix[i]);
			push(s,c);
		}
	}
}