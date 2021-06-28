 #include <stdio.h>
 #include <stdlib.h>

 typedef struct list{
     int data;
     struct list *link;
 }NODE;

 NODE *front = NULL;
 NODE *rear = NULL;
 NODE *current;
 NODE *temp;

 void enqueue();
 void dequeue();
 void display();
 _Bool isempty();

 int main() {
     while(1){
         int choice;

         printf("1. Enqueue \n2. Dequeue \n3. Display \n4. Quit\n");
         printf("Enter your choice ");
         scanf("%d", &choice);

         switch(choice){
             case 1: enqueue();
                     break;
             case 2: dequeue();
                     break;
             case 3: display();
                     break;
             case 4: exit(1);
                     break;
           }
     }
 }

 void display(){
     if(isempty())
         printf("There are no elements to be displayed, stack is empty\n");
     else{
        /* for(temp = front; temp != rear; temp = temp->link){
             printf("data is %d\n", temp->data);
         }
         printf("data is %d\n", temp->data);*/
        temp = front;
        while(temp!=NULL){
        	printf("%d ", temp->data);
        	temp = temp->link;
		}
		printf("\n");
     }
 }

 void enqueue() {
     current = (NODE*)malloc(sizeof(NODE));
     current->link = NULL;

    printf("Enter the data: ");
    scanf("%d", &current->data);
    if(isempty())
        front = rear = current;
    else{
        rear->link = current;
        rear = current;
    }
}

void dequeue() {
    if(isempty())
        printf("Queue is empty\n");
    else{
        temp = front;
        front = front->link;
        if(front == NULL)
        	rear = NULL;
        free(temp);
    }
}
_Bool isempty() {
    return (front == NULL && rear == NULL);
}
