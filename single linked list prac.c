#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link; 
}NODE;

NODE* head = NULL;

NODE* create(int data){
	NODE* new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}

NODE* traverse(){
	NODE* current = head;
	if(current == NULL)
		return current;
	while(current->link != NULL)
		current = current->link;
	return current;
}

void insert(int data){
	NODE* current;
	current =  traverse();
	current = create(data);
}

void Delete(int ele){
	NODE* current = head;
	if(head->data == ele){
		head = head->link;
		return;
	}
	while(current != NULL){
		if(current->link != NULL && (current->link->data == ele)){
			current->link = current->link->link;
			return;
		}
		current = current;
	}
	printf("Element not found in the array!\n");
}

void display(){
	NODE* current = head;
	while(current != NULL){
		printf("%d->", current->data);
		current = current->link;
	}
}


void menu();

int main(){
	menu();
	return 0;
}


void menu(){
	printf("Single linked list operations:\n");
	printf("1. Insert	2. Delete	3. Display	4. Quit\n");
	int operation, data;
	while(1){
		printf("Enter the operation number to perform: ");
		scanf("%d", &operation);
		switch(operation){
			case 1:
				printf("Enter data to insert: ");
				scanf("%d", &data);
				insert(data);
				break;
			case 2: 
				printf("Enter data to delete: ");
				scanf("%d", &data);
				Delete(data);
				break;
				
			case 3: 
				display();
				break;	
			case 4: 
				printf("Exiting...");
				exit(100);
		}
	}
}
