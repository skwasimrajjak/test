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

int isempty(stack* ptr){
	return (-1 == ptr->top);
}

//function for popping from stack
char pop(stack* ptr){
	if(isempty(ptr))
		return '$';
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
	//printf("Top value = %d\n",s->top);
	printf("Stack: ");
	for(i=0; i<=s->top; i++)
		printf("%c",s->arr[i]);
	printf("\n");
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
	
	stack s1; //stack storing the operators
	init(&s1, 100);
	char infix[100]; // = "a+b+(c*d)+e/f";
	char res;
	printf("Enter infix expression: ");
	//scanf("%s",&infix);
	gets(infix); //stores infix expression given by user
	char* postfix = infix_to_postfix(infix, &s1); //dynamic character array stores resultant postfix expression
	printf("Resultant postfix expression: %s\n",postfix);
	
	postfixEval(&s1, postfix);
	display(&s1); //for displaying stack
	//res = pop(&s1);
	printf("\nAnswer = %c\n",peek(&s1));
	postfixEval(&s1, "123/*5/");
	printf("\nAnswer = %c\n",peek(&s1)); //0
	return 0;
}
