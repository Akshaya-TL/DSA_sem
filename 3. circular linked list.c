// Circular linked list

#include<stdio.h>
#include<stdlib.h>

int elements_count = 0, value;

typedef struct list{
	int data ;
	struct list *link;
}NODE;

// creation of head node which contains no data
// but acts as a pointer to 1st node
NODE* head;

// insert related functions	
void insert_1st_node();
void insert_after_data();
void insert_before_data();

// delete related functions
void delete_data();

// display
void display();

// menu
void menu();

int main(){
	
    menu();

	return 0;
}

void insert_1st_node(){
	NODE* new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	printf("Enter data to be inserted as 1st node in circular linked list: ");
	scanf("%d", &new_node->data);
	new_node->link = new_node;
	head = new_node;
	elements_count += 1;
	return;
}

void insert_after_data(){
	
	NODE *new_node, *current = head->link;
	new_node = (NODE*)malloc(sizeof(NODE));
	printf("Enter the value to be inserted : ");
	scanf("%d", &new_node->data);
	getchar();
	printf("Enter the value after which %d has to be inserted : ", new_node->data);
	scanf("%d", &value);
	getchar();
	while(current->data != value){
		current = current->link;
	}
	new_node->link = current->link;
    current->link = new_node;
    elements_count += 1;
	
}

void insert_before_data(){
	
	NODE *new_node, *current = head, *temp;
	new_node = (NODE*)malloc(sizeof(NODE));
	printf("Enter the value to be inserted : ");
	scanf("%d", &new_node->data);
	getchar();
	printf("Enter the value before which %d has to be inserted : ", new_node->data);
	scanf("%d", &value);
	getchar();
	
	// to insert before head node
	if(current->data == value){
		new_node->link = current;
		temp = current;
		while(current->link != temp){
			current = current->link;
		}
		current->link = new_node;
		head = new_node;
		elements_count += 1;
		return;
	}
	
	current = current->link;
	int  i = 1;
    while(current->data != value && i < elements_count - 1){
    	current = current->link;
    	i++;
	}
	if(current->data == value){
		new_node->link = current;
		temp = current;
		while(current->link != temp){
			current = current->link;
		}
		current->link = new_node;
		elements_count += 1;
	}
	
	
	
	else{
		printf("Value entered not found.\n");
    }
}


void delete_data(){
	int data;
	NODE* current = head, *temp;
	printf("Enter data to be deleted: \n");
	scanf("%d", &data);
	getchar();
	if(current->data == data){
		temp = current;
		head = current->link;
		while(current->link != temp){
			current= current->link;
		}
		current->link = head;
		free(temp);
	}
	else{
		int i = 0;
		while(current->link->data != data && i < elements_count){
			current = current->link;
			i++;
		}
		if(i < elements_count)
		   current->link = current->link->link;
		else
			printf("Data not found!\n");
	}
	
}

void display(){
	printf("\n");
	NODE* current = head;
	int i = 2;
	printf("The value at position 1 is %d\n",  current->data);
	current = head->link;          	
	while(current != head){
		printf("The value at position %d is %d\n", i, current->data);
		current = current->link;
		i++;
	};
}

void menu(){
	int next = 1;
    int operation, sub_operation;
    insert_1st_node();
	printf("Circular linked list operations : \n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
	while(next){
		printf("\nEnter the operation number : ");
		scanf("%d", &operation);
	switch(operation){
		case 1:
			printf("   1. Insert after data\n   2. Insert before data\n");
			printf("Enter the operation number for type of insert : ");
			scanf("%d", &sub_operation);
			switch(sub_operation){
				case 1:
					insert_after_data();
					break;
				case 2:
					insert_before_data();
					break;
			}
			break;
		
		case 2:
			delete_data();
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

