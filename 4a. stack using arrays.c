// stack with arrays

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int *stack;
int top = -1;
int size;
	
void push();
void pop();
void diplay();
bool isfull();
bool isempty();
void menu();

int main(){
   
    printf("Enter number of elements you want to insert : ");
    scanf("%d", &size);
    stack = (int *)malloc(size * sizeof(int));
	printf("\nOPERATIONS : \n");
	printf("1. Push \n2. Pop \n3. Display \n4. Is stack full\n5. Is stack empty\n6. Quit \n");
	menu();
	return 0;

}

void display(){
	int i = 0;
	if(isempty())
	    printf("There are no elements to display.\n");
	else{
		printf("The elements : \n ");
		for(i = top; i >= 0; i--){
			printf("%d ", stack[i]);
		}
		printf("\n");
	}	
}

void push(){
	int value;
	if(isfull())
	   printf("The stack is full. No more elements can be inserted. \n");
	else{
	printf("Enter the value to insert : ");
	scanf("%d", &value);
	top += 1;
	stack[top] = value;
   }
}

void pop(){
	if(isempty()) 
	    printf("No more elements can be deleted. \n");
	else{
		top -= 1;
		printf("%d is popped from the stack.\n",stack[top + 1]);}
}

bool isfull(){
	return top == (size - 1);
}

bool isempty(){
	return top == -1;
}

void menu(){
	int next = 1;
    int operation;
	while(next){
		printf("\nEnter the operation number : ");
		scanf("%d", &operation);
	switch(operation){
		case 1:
			push();
			break;
		
		case 2:
			pop();
			break;
		
		case 3:
			display();
			break;
			
		case 4:
			isfull() != 0? printf("The stack is full!\n") : printf("The stack is not full.\n");
			break;
			
		case 5:
			isempty() != 0? printf("The stack is empty! \n") : printf("The stack is not empty.\n");
			break;
		
		case 6:
			next = 0;
			printf("Thank you! Have a Great day!\n");
			break;
	}	
	}
}
