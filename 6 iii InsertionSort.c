//Insertion sort 
#include<stdio.h>

void insertionSort(int arr[], int n);
void display(int arr[], int n);

int main(){
	int n, i;
	printf("Enter number of elements to be sorted : ");
	scanf("%d", &n);
	
	int array[n];
	printf("Enter %d elements \n", n);
	for(i = 0; i < n; i++)
		scanf("%d", array + i);
		
	insertionSort(array, n);
	
	display(array, n);

}

void insertionSort(int arr[], int n){
	int i, j, value;
	for(i = 0; i < n; i++){
		value = arr[i];
		for(j = i-1; j >= 0; j--){
			if(arr[j] > value)
				arr[j+1] = arr[j];
			else
				break;
		}
		arr[j+1] = value;
	}
}

void display(int arr[], int n){
	int i;
	printf("The sorted elements are : \n");
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}
