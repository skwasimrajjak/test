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

/*int isfull(stack* ptr){
	return (ptr->top == ptr->size-1);
}*/

//function to push in stack
void push(stack* ptr, int item){
	ptr->arr[++ptr->top] = item;
}

/*int isempty(stack* ptr){
	return (-1 == ptr->top);
}*/

//function for popping from stack
char pop(stack* ptr){
	return ptr->arr[ptr->top--];
}

//function to check for operator
int isoperator(char ch){
	if(ch == '^' || ch == '/' || ch == '*' || ch == '%' || ch == '+' || ch == '-')
		return 1;
	else
		return 0;
}

//function to return precedence of an operator
int precedence(char ch){
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
char peek(stack* s){
	return s->arr[s->top];
}

//function to convert infix to postfix
char* infix_to_postfix(char* infix, stack *s){
	int ilen = strlen(infix);
	char* postfix = (char*)malloc(ilen*sizeof(char));
	int i, j = 0;
	for(i=0; i<ilen; i++){
		if(infix[i] == ' ' || infix[i] == '\t')
			continue;
		else if(infix[i] == '(')
			push(s, infix[i]);
		else if(isalnum(infix[i]))
			postfix[j++] = infix[i];
		else if(infix[i] == ')'){
			while(peek(s) != '(' && s->top > -1)
				postfix[j++] = pop(s);
			if(s->top == -1 && s->arr[s->top+1] != '(')
				return "Invalid Expression\n";
			else
				s->top--;
		}
		else if(isoperator(infix[i])){
			while(precedence(infix[i]) <= precedence(peek(s)) && s->top > -1){
				postfix[j++] = pop(s);
			}
			push(s, infix[i]);
		}
	}
	while(s->top > -1)
		postfix[j++] = pop(s);
	postfix[j] = '\0';
	return postfix;
}

//function to display stack
void display(stack* s){
	int i;
	printf("Stack: ");
	for(i=0; i<s->top; i++)
		printf("%c",s->arr[i]);
	printf("\n");
}


int main(){
	
	stack s1; //stack storing the operators
	init(&s1, 100);
	char infix[100]; // = "a+b+(c*d)+e/f";
	printf("Enter infix expression: ");
	//scanf("%s",&infix);
	gets(infix); //stores infix expression given by user
	char* postfix = infix_to_postfix(infix, &s1); //dynamic character array stores resultant postfix expression
	printf("Result: %s\n",postfix);
	//display(&s1); //for displaying stack
	return 0;
}
