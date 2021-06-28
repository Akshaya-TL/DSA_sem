#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *queue;
int front = -1, rear = -1;
int max_size;
// to insert 
void enqueue();
bool is_full();

// to delete
void dequeue();
bool is_empty();

// to display
void display();
void menu();

int main(){
	printf("Enter the size of the queue : ");
	scanf("%d", &max_size);
	queue = (int*)malloc(max_size * sizeof(int));
	printf("Operations for queue : \n");
	printf("1. Enqueue\n2. Dequeue\n3. Is full\n4. Is Empty\n5. Display\n6. Exit\n");
	menu();
}

bool is_full(){
	if(rear >= max_size - 1)
	     return true;
	return false;
}

void enqueue(){
	if(is_full())
	  printf("No more elements can be added.\n");
	else{
		int element;
		printf("Enter an element to insert : ");
		scanf("%d", &element);
		if(front == -1 && rear == -1)
		    front = rear = 0;
		else
		     rear += 1;
		queue[rear] = element;
	}
}

bool is_empty(){
	if(front > rear || (front == -1 && rear == -1))
	   return true;
	return false;
}

void dequeue(){
	if(is_empty())
	   printf("No more elements can be removed.\n");
	else{
		front += 1;
	}
}

void display(){
	int i = front;
	if(is_empty())
	   printf("No elements to display. \n");
	else{
	   for(i = front; i <= rear; i++){
		   printf("%d ", queue[i]);
	}
	printf("\n");
}
}

void menu(){
	int category, next = 1;
	while(next){
	printf("Enter the operation number you want to implement : ");
	scanf("%d", &category);
	switch(category){
		
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			if(is_full())
			   printf("The queue is full.\n");
			else
			   printf("The queue is not full.\n");
			
			break;
		case 4:
			if(is_empty())
			   printf("The queue is empty.\n");
			else
			   printf("The queue is not empty.\n");
			
			break;
		case 5:
			display();
			break;
		case 6:
			next = 0;
			break;
		}
	}
			
	}

