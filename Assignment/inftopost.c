//Convertion of Infix to Postfix
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
char pop(stack* ptr);
int isoperator(char ch);
int precedence(char ch);
char peek(stack* s);
char* infix_to_postfix(char* infix, stack *s);


int main()
{
	
	stack store; //stack storing the operators
	init(&store, 100);
	char infix[100]; 
	printf("\nEnter infix expression: ");
	fgets(infix, 100, stdin); 
	
	//dynamic character array stores resultant postfix expression
	char* postfix = infix_to_postfix(infix, &store); 

	printf("\nPostfix expression: %s\n\n",postfix); 
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

//function for popping from stack
char pop(stack* ptr)
{
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

//function to return precedence of an operator
int precedence(char ch)
{
	if(ch == '^')
		return 3;
	else if(ch == '/' || ch == '*' || ch == '%')
		return 2;
	else if(ch == '+' || ch == '-')
		return 1;
	else
		return 0;
}

//function to see element at top of stack
char peek(stack* s)
{
	return s->arr[s->top];
}

//function to convert infix to postfix
char* infix_to_postfix(char* infix, stack *s)
{
	int len = strlen(infix);
	char* pf = (char*)malloc(len*sizeof(char));
	int i, j;
	for(i=0, j=0; i<len; i++)
	{
		if(infix[i] == ' ' || infix[i] == '\t') 
		{
			continue;
		}
		else if(infix[i] == '(')
		{
			push(s, infix[i]);
		}
		else if(isalnum(infix[i]))
		{
			pf[j++] = infix[i];
		}	
		else if(infix[i] == ')')
		{
			while(peek(s) != '(' && s->top > -1)
			{
				pf[j++] = pop(s);
			}
			if(s->top == -1 && s->arr[s->top+1] != '(') //if opening bracket not present
			{
				return "Invalid Expression\n";
			}
			else
			{
				s->top--;
			}
			
		}
		else if(isoperator(infix[i]))
		{
			while(precedence(infix[i]) <= precedence(peek(s)) && s->top > -1)
			{
				pf[j++] = pop(s);
			}
			push(s, infix[i]);
		}
	}
	while(s->top > -1)
	{
		pf[j++] = pop(s);
	}
		
	pf[j] = '\0';
	return pf;
}


