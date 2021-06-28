#include<stdio.h>
#include<stdlib.h>
int count = -1;

struct rec{
	int data;
	struct rec* left;
	struct rec* right;
};

int digit;
struct rec* tree = NULL;

struct rec* insert(struct rec*, int);

void inorder(struct rec*);
void preorder(struct rec*);
void postorder(struct rec*);

int main(){
	int choice;
	while(1){
		printf("1. Insert 2. Inorder 3. Preorder 4. Postorder 5. Exit\n ");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice){
		   case 1:
				printf("Enter a digit or 999 to exit: ");
				scanf("%d", &digit);
				while(digit!=999){
					tree = insert(tree, digit);
					scanf("%d", &digit);
				}
				break;
			case 2:
				printf("Inorder sequence\n");
				inorder(tree);
				break;
			case 3:
				printf("Preorder sequence\n");
				preorder(tree);
				break;
			case 4:
				printf("Postorder sequence\n");
				postorder(tree);
				break;
			case 5:
				exit(100);	
					}
	}
	return 0;
}

struct rec* insert(struct rec* tree1, int ele){
	if(tree1 == NULL){
		tree1 = (struct rec*)malloc(sizeof(struct rec));
		tree1->left = tree1->right = NULL;
		tree1->data = ele;
		count++;
	}
	else{
		if(count%2==0){
           tree1->left = insert(tree1->left, ele);  
		}
		else{
			tree1->right = insert(tree1->right, ele);
		}
		
	}
	return (tree1);
}

void inorder(struct rec* tree1){
	if(tree1!=NULL){
		inorder(tree1->left);
		printf("%d ", tree1->data);
		inorder(tree1->right);
	}
}
void postorder(struct rec* tree){
	if(tree!=NULL){
		postorder(tree->left);
		postorder(tree->right);
		printf("%d ", tree->data);
	}
}

void preorder(struct rec *tree){
	if(tree != NULL){
		printf("%d ", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}
