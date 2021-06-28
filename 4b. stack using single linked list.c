#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct list{
	int data ;
	struct list *link;
}NODE;

// creation of head node which contains no data
// but acts as a pointer to 1st node
NODE* top;


// insert related functions	
void insert_at_start();

// delete related functions
void delete_first_node();
bool is_empty();

// display
void display();

// menu
void menu();

int main(){
	
	top = (NODE *)malloc(sizeof(NODE));
	top->data = 0;
	top->link = NULL;
    printf("Stack using Single linked list operations : \n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    menu();

	return 0;
}

void insert_at_start(){
	NODE* new_node;
	new_node = (NODE*) malloc(sizeof(NODE));
	new_node->link = top->link;
	
	printf("Enter the value to be inserted on top : ");
	scanf("%d", &new_node->data);
	top->link = new_node;
}

bool is_empty(){
	if(top->link == NULL)
	   return true;
	return false;
}

void delete_first_node(){
	if(is_empty())
	   printf("No more elements can be removed.\n");
	else{
	NODE *current = top->link;
	top->link = current->link;
	}
}

void display(){
	if(is_empty())
	  printf("No elements to display.\n");
	else{
	printf("\n");
	NODE* current;
	int i = 1;
	current = top->link;          
	do{
		printf("The value at position %d is %d\n", i, current->data);
		current = current->link;
		i++;
	}while(current != NULL);
}
}
void menu(){
	int next = 1;
    int operation;
	while(next){
		printf("\nEnter the operation number : ");
		scanf("%d", &operation);
	switch(operation){
		case 1:
			insert_at_start();
			break;
		
		case 2:
			delete_first_node();
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

