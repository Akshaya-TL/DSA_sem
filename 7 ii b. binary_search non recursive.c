// Non recursive method
#include <stdio.h>

int binary_search(int a[], int element, int n);

int main(void) {
	int elements_count;
	printf("Enter number of elements : ");
	scanf("%d", &elements_count);
	int arr[elements_count], i = 0, value, check_value;
	for( i = 0; i < elements_count; i++){
	   scanf("%d", &arr[i]);
	}
	printf("Enter the value to be found : ");
	scanf("%d", &value);
	check_value = binary_search(arr, value, elements_count);
	if(check_value)
	    printf("%d is found at %d position", value, check_value + 1);
	else
	    printf("%d is not found", value);
	return 0;
}

int binary_search(int a[], int element, int n){
    int i, mid, low = 0, high = n;
    while(low <= high){
   		mid = (low + high)/2;
   		if(element == a[mid])
           return mid;
   		if(element < a[mid])
           high = mid - 1;
        else
           low = mid + 1;
        }
    return 0;    
}


