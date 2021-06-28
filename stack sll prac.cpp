#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
	int data;
	struct Node* next;
}NODE;

NODE* top;
void push();
void pop();
int isEmpty();
void display();
void menu();

int main(){
	top = (NODE*)malloc(sizeof(NODE));
	top->next = NULL;
	top->data = 0;
	menu();
	return 0;
}

void push(){
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->next = top;
	top = new_node;
	printf("Enter data to enter: ");
	scanf("%d", &top->data);
	return;
}

void pop(){
	if(isEmpty())
		printf("No elements to pop.\n");
	else{
	NODE* cur = top->next;
	free(top);
	top = cur;	
	}
	return;
}

int isEmpty(){
	return top->next == NULL;
}

void display(){
	if(isEmpty()){
		printf("No elements to display.\n");
		return;
	}
	NODE* cur = top;
	while(cur->next != NULL){
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

void menu(){
	printf("Stack using Single linked list operations : \n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
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
			next = 0;
			break;
	}
	}	
	}

