#include<stdio.h>
#include<stdlib.h>
struct stack{
	int data;
	struct stack* next;
};
struct stack* top = NULL;

int main(){
	//printf("%d", sizeof(top));
	struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
	temp->data = 23;
	temp->next = top;
	top = temp;
	temp = (struct stack*)malloc(sizeof(struct stack));
	temp->data = 53;
	temp->next = top;
	top = temp;
	temp = top;
	while(temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	
	return 0;
}
