#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}NODE;

NODE* head;

NODE* create(int data){
	NODE* new_node; 
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}

void insert(int data){
	NODE *current = head;
	while(current->link != NULL){
		current = current->link;
	}
	current->link = create(data);	
}

void Delete(int position){
	int i = 0;
	NODE* current = head;
	while(i < position-1 && current != NULL){
		current = current->link;
		i++;
	}
	if(current != NULL)
		current->link = current->link->link;
	else
		printf("Invalid position!\n");
}

void display(){
	NODE* current = head->link;
	while(current != NULL){
		printf("%d -> ", current->data);
		current = current->link;
	}
}

void menu();
int main(){
	head = (NODE*)malloc(sizeof(NODE));
	head->link = NULL;
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
				printf("Enter position to delete: ");
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

