#include<stdio.h>
#include<string.h>
char operatorStack[20];
int isOperator(char ch);
int precedence(char ch);
void push(char ch);
char pop();

int top = -1;

int main(){
	char a = '2';
	printf("%d\n", atoi(&a));
	char infix[30];
	int i;
	printf("Enter infix expression: ");
	gets(infix);
	
	for(i = 0; infix[i] != '\0'; i++){
		if(infix[i] == '(')
			push(infix[i]);
		
		else if (infix[i] == ')'){
			while(operatorStack[top] != '('){
				printf("%c", pop());
			}
			pop();   // to remove open paranthesis
		}
		
		else if (isOperator(infix[i])){
			while(top != -1 && precedence(infix[i]) <= precedence(operatorStack[top])){
				printf("%c", pop());
			}
			push(infix[i]);
		}
		
		else
			printf("%c", infix[i]);
	}
	
	while(top != -1){
		printf("%c",pop());
	}
	return 0;
}

void push(char symbol){
	operatorStack[++top] = symbol;
}

char pop(){
	return operatorStack[top--];
}

int precedence(char ch){
	switch(ch){
		case '*':
			return 2;
		case '/':
			return 2;
		case '%':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		default:
			return 0;
	}
}

int isOperator(char ch){
	if(ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-')
		return 1;
	return 0;	
}
