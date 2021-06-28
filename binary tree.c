#include<stdio.h>
#include<stdlib.h>


struct rec{
	int data;
	struct rec* left;
	struct rec* right;
	int count;         // count to know how many children the node has
};

// Insertion logic:

// if parent == NULL
//	1> create a node and insert the given data
// if parent->count == 0
//	1> create a node and insert it at parent->left 
// if parent->count == 1
// 	1> create a node and insert it at parent->right
// if parent->count = 2
//  1> if parent->left->count < 2
//		a> insert(parent->left, element)
//  2> else
//      a> insert(parent->right, element)

void insert(struct rec* , int element);
struct rec* bin_treeRoot = NULL;

int main(){
	printf("Insert function working test-\n");
	int ele;
	while(1){
		printf("Enter data to insert: ");
		scanf("%d", &ele);
		if(ele == 999){
			exit(0);
		}
		insert(bin_treeRoot, ele);
	}
	return 0;	
}

void insert(struct rec* tree, int element){
	struct rec* current_node = tree;
	if(current_node == NULL){
		current_node = (struct rec*)malloc(sizeof(struct rec));
		current_node->data = element;
		current_node->left = current_node->right = NULL;
		current_node->count = 0;
	}
	
	else if(current_node->count == 0){
		current_node->count += 1;
		insert(current_node->left, element);
	}
	
	else if(current_node->count == 1){
		current_node->count += 1;
		insert(current_node->right, element);
	}
	
	else {
		// current_node->count == 2
		if(current_node->left->count < 2){
			insert(current_node->left, element);
		}
		else if(current_node->right->count < 2){
			insert(current_node->right, element);
		}		
		else{
			insert(current_node->left, element);
	    }	
	}
}



