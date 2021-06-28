#include <stdio.h>
#include <stdlib.h>

int *arr;
int key; 
int count;
int low = 0;
int high;

int binary_search();

int main(){
	int i, value;
	printf("Enter the number of elements in array : ");
	scanf("%d", &count);
	arr = (int *)malloc(count * sizeof(int));
	printf("Enter %d elements : \n ", count);
	high = count;
	for(i = 0; i < count; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the key to find : \n");
	scanf("%d", &key);
	value = binary_search();
	value == -1? printf("Element not in the array!\n") : printf("%d is present in %d position\n", key, value);
	
}

// recursive approach
int binary_search(){
	int mid = (low + high)/2;
	if(key == arr[mid])
	   return mid + 1;
	else if(low >= high || high <= low)
	   return -1;
	else {
	    if(key > arr[mid]){
	    	low = mid + 1;
	    	binary_search();
		}
		else{
			high = mid - 1;
			binary_search();
		}
	}
}

