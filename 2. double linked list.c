// double linked list

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	struct node* prev;
	int data;
	struct node* next;
} NODE;

// create node
NODE* create_node(int data);

// insert 
void insert_at_beginning();
void insert_after_data();
void insert_before_data();
void insert_at_end();
// delete
void delete_node();
//traversal
NODE* traverse(int data);
// display
void display();
// menu
void menu();

NODE* head = NULL;
NODE* current_node;
int first_node = 0;

int main(){
	
	menu();
	
	return 0;
}

NODE* traverse(int data){
	NODE* temp_node = head;
	while(temp_node != NULL){
		if(temp_node->data == data)
			return temp_node;
		temp_node = temp_node->next;
		}
	printf("Data not found!\n");	
    return NULL;
}

NODE* create_node(data){
	
	NODE* created_node = (NODE*) malloc(sizeof(NODE));
	created_node->prev = NULL;
	created_node->data = data;
	created_node->next = NULL;
	return created_node;
}

void insert_at_beginning() {
	int data;
    printf("Enter the data to be inserted at the beginning: ");
    scanf("%d", &data);
    current_node = create_node(data);
	if(head == NULL){
		head = current_node;
	}
	else{
		 current_node->next = head;
		 head = current_node;
		 current_node->next->prev = current_node;
	}
}

void insert_after_data(){

	int data, element_after;
	printf("Enter data to insert : ");
    scanf("%d", &data);
    getchar();
    
	NODE* new_node = create_node(data);
    printf("Enter the element after which %d should be inserted: ", data);
    scanf("%d", &element_after);
    getchar();
    
	NODE* temp_node = traverse(element_after);
	if(temp_node != NULL){
		new_node->next = temp_node->next;
		new_node->prev = temp_node;
		temp_node->next = new_node;
		if(new_node->next == NULL)
			current_node = new_node;
    }
}

void insert_before_data(){
	
	int data, element_before;
	printf("Enter data to insert : ");
    scanf("%d", &data);
    getchar();
    
	NODE* new_node = create_node(data);
    printf("Enter the element before which %d should be inserted: ", data);
    scanf("%d", &element_before);
    getchar();
    
	NODE* temp_node = traverse(element_before);
	if(temp_node != NULL){
		new_node->prev = temp_node->prev;
		new_node->next = temp_node;
		temp_node->prev = new_node;
		if(new_node->prev == NULL)
			head = new_node;
		else
			new_node->prev->next = new_node;
    }
}

void insert_at_end(){
    int data;
	printf("Enter data to insert : ");
    scanf("%d", &data);
    getchar();
	NODE* new_node = create_node(data);
	if(first_node == 0){
		head = new_node;
		current_node = new_node;
		first_node += 1;	
	}
	else{
	
		current_node->next = new_node;
		new_node->prev = current_node;
		current_node = new_node;
    }
}

void delete_node(){
	int data;
	NODE* temp = head;
	printf("Enter the data to be deleted : ");
	scanf("%d", &data);
	getchar();
	while(temp != NULL){
		if(temp->data == data){
			if(temp->prev == NULL){
				temp = NULL;
				return;
			}
			else{
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				free(temp);
				return;
		}
		temp = temp->next;
	}
	if(temp->data == data){
		temp->prev->next = NULL;
		free(temp);
		return;
	}
	
	printf("Data not found.\n");
	return;
}
}

void display(){
	current_node = head;
	while(current_node != NULL){
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	printf("\n");
}

void menu(){
	int option, persist = 1, sub_category;
	printf("Menu:\n1. Insert \n2. Delete\n3. Display\n4. Quit\n");
	while(persist){
		printf("Enter operation number: ");
		scanf("%d", &option);
		getchar();
		switch(option){
			case 1:
				printf("0. Insert at start \n1. Insert after data\n2. Insert before data\n3. Insert at end\n");
				printf("Enter type of insert: ");
				scanf("%d", &sub_category);
				switch(sub_category){
					case 0: 
						insert_at_beginning();
						break;
					case 1:
					    insert_after_data();
					    break;
					case 2:
						insert_before_data();
						break;
					case 3:
						insert_at_end();
						break;
				}
				break;
			
			case 2:
				delete_node();
				break;
			
			case 3:
				display();
				break;
			
			case 4:
				printf("Exiting...");
				persist = 0;
				break;
		}
	}
}
