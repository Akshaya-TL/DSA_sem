// Selection sort
#include <stdio.h>

void selectionSort(int arr[], int n);
void swap(int arr[], int i1, int i2);
void display(int arr[], int n);

int main(){
	int n, i;
	printf("Enter number of elements to be sorted : ");
	scanf("%d", &n);
	
	int array[n];
	printf("Enter %d elements \n", n);
	for(i = 0; i < n; i++)
		scanf("%d", array + i);
	 
	selectionSort(array, n);
	
	display(array, n);
	
	return 0;
}

void selectionSort(int arr[], int n){
	int i, j, min_index;
	for(i = 0; i < n-1; i++){
		min_index = i;
		for(j = i+1; j < n; j++){
			if (arr[j] < arr[min_index])
			   min_index = j;
		}
		swap(arr, i, min_index);
	}
	
}

void swap(int arr[], int i1, int i2){
	int temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}

void display(int arr[], int n){
	int i;
	printf("The sorted elements are : \n");
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}
