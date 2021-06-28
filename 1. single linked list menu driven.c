
#include<stdio.h>
#include<stdlib.h>

int position, value;

typedef struct list{
	int data ;
	struct list *link;
}NODE;

// creation of head node which contains no data
// but acts as a pointer to 1st node
NODE* head;


// insert related functions	
void insert_at_start();
void insert_at_position();
void insert_after_data();
void insert_at_end();


// delete related functions
void delete_first_node();
void delete_at_position();
void delete_last_node();

// display
void display();

// menu
void menu();

int main(){
	
	head = (NODE *)malloc(sizeof(NODE));
	head->data = 0;
	head->link = NULL;
    printf("Single linked list operations : \n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    menu();

	return 0;
}

void insert_at_start(){
	NODE* new_node;
	new_node = (NODE*) malloc(sizeof(NODE));
	new_node->link = head->link;
	
	printf("Enter the value to be inserted at beginning : ");
	scanf("%d", &new_node->data);
	head->link = new_node;
}

void insert_at_position(){
	
	NODE *new_node, *current = head;
	int i;
	new_node = (NODE*)malloc(sizeof(NODE));
	printf("Enter the position (NOT INDEX) : ");
	scanf("%d", &position);
	printf("Enter the value to be inserted at position %d : ", position);
	scanf("%d", &new_node->data);
	for(i = 1; i < position; i++){
		current = current->link;
	}
	new_node->link = current->link;
	current->link = new_node;
	
}

void insert_after_data(){
	
	NODE *new_node, *current = head->link;
	new_node = (NODE*)malloc(sizeof(NODE));
	printf("Enter the value to be inserted : ");
	scanf("%d", &new_node->data);
	printf("Enter the value after which %d has to be inserted : ", new_node->data);
	scanf("%d", &value);
	while(current->data != value){
		current = current->link;
	}
	new_node->link = current->link;
    current->link = new_node;
	
}

void insert_at_end(){
	NODE *new_node, *current = head->link;
	new_node = (NODE *)malloc(sizeof(NODE));
	new_node->link = NULL;
	printf("Enter the value to be inserted at end : ");
	scanf("%d", &new_node->data);
	while(current->link != NULL){
		current = current->link;
	}
	current->link = new_node;
}

void delete_first_node(){
	NODE *current = head->link;
	head->link = current->link;
	}
	
void delete_at_position(){
	printf("Enter the position of node to delete : ");
	scanf("%d", &position);
	NODE *current = head->link;
	int i = 1;
	for(i = 1; i < position - 1; i++){
		current = current->link;
	}
	current->link = current->link->link;
}

void delete_last_node(){
	NODE *current = head;
	while(current->link->link != NULL){
		current = current->link;
	}
	current->link = NULL;
}

void display(){
	printf("\n");
	NODE* current;
	int i = 1;
	current = head->link;
	if(current == NULL){
		printf("No elements to display\n");
		return;         
	}
	do{
		printf("The value at position %d is %d\n", i, current->data);
		current = current->link;
		i++;
	}while(current != NULL);
}

void menu(){
	int next = 1;
    int operation, sub_operation;
	while(next){
		printf("\nEnter the operation number : ");
		scanf("%d", &operation);
	switch(operation){
		case 1:
			printf("	1. Insert at the beginning\n	2. Insert at position\n        3. Insert after a particular data\n        4. Insert at end\n");
			printf("Enter the operation number for type of insert : ");
			scanf("%d", &sub_operation);
			switch(sub_operation){
				case 1:
					insert_at_start();
					break;
				case 2:
					insert_at_position();
					break;
				case 3:
					insert_after_data();
					break;
				case 4:
					insert_at_end();
					break;
			}
			break;
		
		case 2:
			printf("	1. Delete first node\n    2. Delete node at a position\n    3. Delete last node\n");
			printf("Enter the operation number for type of delete : ");
			scanf("%d", &sub_operation);
			switch(sub_operation){
				case 1:
					delete_first_node();
					break;
				case 2:
					delete_at_position();
					break;
				case 3:
					delete_last_node();
					break;
				}
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

