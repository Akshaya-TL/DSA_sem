// Heap sort
#include<stdio.h>
#include<stdlib.h>

// Heap related funcs
void max_heapify(int A[], int n, int i);
void heapSort(int A[], int n);
void swap(int* n1, int* n2);

int main(){
	
	int n, i, *arr;
	printf("Enter number of elements to sort: ");
	scanf("%d", &n);
	arr = (int* )malloc(n*sizeof(int));
	
	printf("Enter the elements to sort: \n");
	for(i = 0; i < n; i++){
		printf("Enter element %i: ", i+1);
		scanf("%d", (arr+i));
	}
	
	heapSort(arr, n);
	
	printf("Sorted elements: \n");
	for(i = 0; i < n; i++){
		printf("%d ", *(arr+i));
	}

	return 0;
}

void max_heapify(int A[], int n, int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
		
	if((left < n) && (A[left] > A[largest])){
		largest = left;
	}
	if((right < n) && (A[right] > A[largest])){
		largest = right;
	}
	
	if(largest != i){
		swap(&A[largest], &A[i]);
		max_heapify(A, n, largest);
	}
}

void heapSort(int A[], int n){
	int i, j;
	for(i = n/2; i >= 0; i--){
		max_heapify(A, n, i);
	}
	
	for(i = n-1; i >= 0; i--){
		swap(&A[0], &A[i]);
		max_heapify(A, i, 0);
	}

}

void swap(int* n1, int* n2){
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}



