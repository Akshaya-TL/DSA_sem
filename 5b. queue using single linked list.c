// queue implementation using linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct list{
	int data ;
	struct list *link;
}NODE;

// creation of front node which contains no data
// but acts as a pointer to 1st node
NODE* front;

// insert related functions	
void insert_at_end();
void display();

// delete related functions
void delete_first_node();
bool is_empty();

// display
void display();

// menu
void menu();

int main(){
	
	front = (NODE *)malloc(sizeof(NODE));
	front->data = 0;
	front->link = NULL;
    printf("Queue using Single linked list operations : \n");
    printf("1. Enqueuet\n2. Dequeue\n3. Is empty\n4. Display\n5. Exit\n");
    menu();

	return 0;
}

void insert_at_end(){
	NODE *new_node, *current = front;
	new_node = (NODE *)malloc(sizeof(NODE));
	new_node->link = NULL;
	printf("Enter the value to be inserted at end : ");
	scanf("%d", &new_node->data);
	while(current->link != NULL){
		current = current->link;
	}
	current->link = new_node;
}

bool is_empty(){
	if(front->link == NULL)
	   return true;
	return false;
}

void delete_first_node(){
	if(is_empty())
	   printf("No more elements can be removed.\n");
	else{
	NODE *current = front->link;
	front->link = current->link;
	free(current);
	}
}

void display(){
	if(is_empty())
	  printf("No elements to display.\n");
	else{
	printf("\n");
	NODE* current;
	int i = 1;
	current = front->link;          
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
			insert_at_end();
			break;
		
		case 2:
			delete_first_node();
				break;
		
		case 3:
			if(is_empty())
			   printf("Queue is empty.\n");
			else
			   printf("Queue is not empty.\n");
			   break;
		case 4:
			display();
			break;
		
		case 5:
			next = 0;
			break;
	}
	}	
	}

