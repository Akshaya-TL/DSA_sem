//Bubble sort
#include<stdio.h>

void bubbleSort(int arr[], int n);
void swap(int* n1, int* n2);
void display(int arr[], int n);

int main(){
	int n, i;
	printf("Enter number of elements to be sorted : ");
	scanf("%d", &n);
	
	int array[n];
	printf("Enter %d elements \n", n);
	for(i = 0; i < n; i++)
		scanf("%d", array + i);
	 
	bubbleSort(array, n);
	
	display(array, n);
	
	return 0;
}

void bubbleSort(int arr[], int n){
	int i, j;
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if(arr[j] > arr[j+1])
				swap(arr + j, arr + j+1);
		}
	}
}

void swap(int* n1, int* n2){
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void display(int arr[], int n){
	int i;
	printf("The sorted elements are : \n");
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
