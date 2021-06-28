// Tree traversal  

#include<stdio.h>
#include<stdlib.h>
struct rec{
	int data;
	struct rec *left;
	struct rec *right;
};
struct rec *tree = NULL;
struct rec *insert(struct rec *tree, int num);

void inorder(struct rec *tree);
void postorder(struct rec *tree);
void preorder(struct rec *tree);

int count = 0;

int main(){
	int choice;
	int digit;
	while(1){
		printf("\n1.Insert 2.Inorder 3.Postorder 4.Preorder 5.Exit\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the digit : To quit enter 999\n");
				scanf("%d",&digit);
				while(digit != 999){
					tree = insert(tree,digit);
					scanf("%d",&digit);
				}
				break;
			case 2:
			    printf("Inorder traversal is \n");
				inorder(tree);
				break;
			case 3:
				printf("Postorder traversal is \n");
				postorder(tree);
				break;
			case 4:
				printf("Preorder traversal is \n");
				preorder(tree);
				break;
			case 5:
				exit(1);				
		}
	}
	return 0;
}

struct rec *insert(struct rec *tree, int digit){
	if(tree == NULL){
		tree = (struct rec*)malloc(sizeof(struct rec));
		tree->left = tree->right = NULL;
		tree->data = digit;
		count++;
	}
	else{
		if(count % 2 == 0)
			tree->left = insert(tree->left, digit);
		else
			tree->right = insert(tree->right, digit);
	}
	return(tree);
}

void inorder(struct rec *tree){
	if(tree != NULL){
		inorder(tree->left);
		printf("%d->",tree->data);
		inorder(tree->right);
	}
}

void postorder(struct rec *tree){
	if(tree != NULL){
		postorder(tree->left);
		postorder(tree->right);
		printf("%d->",tree->data);
	}
}

void preorder(struct rec *tree){
	if(tree != NULL){
		printf("%d->",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}
