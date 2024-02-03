//postfix evaluation program

//declaring header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//creating user defined datatype stack
typedef struct stack{
	int top;
	int size;
	char* arr;
}stack;

//function for initialising stack
void init(stack* ptr, int size){
	ptr->size = size;
	ptr->top = -1;
	ptr->arr = (char*)malloc(size*sizeof(char));
}

//function to push in stack
void push(stack* ptr, int item){
	ptr->arr[++ptr->top] = item;
}

//to check if stack is empty or not
int isempty(stack* ptr){
	return (-1 == ptr->top);
}

//function for popping from stack
char pop(stack* ptr){
	if(!isempty(ptr))
		return ptr->arr[ptr->top--];
}

//function to check for operator
int isoperator(char ch){
	if(ch == '^' || ch == '/' || ch == '*' || ch == '%' || ch == '+' || ch == '-')
		return 1;
	else
		return 0;
}

//function to see element at top of stack
char peek(stack* s){
	return s->arr[s->top];
}

//function for opeation
char operation(char a, char b, char operator){
	char res;
	if(operator == '^')
		res = (a-48) ^ (b-48);
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
void postfixEval(stack* s, char* postfix){
	char a, b, c;
	int i, ilen = strlen(postfix);
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

int main(){
	stack st; //stack storing the operators
	init(&st, 100);
	char postfix[100];

    printf("Enter postfix expression: ");
	gets(postfix);

	postfixEval(&st, postfix);
	printf("\nAnswer = %c\n",peek(&st));
	return 0;
}