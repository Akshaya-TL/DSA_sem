#include <stdio.h>

int linear_search(int a[], int element);
int main(void) {
	int values_count;
	printf("Enter number of values : ");
    scanf("%d", &values_count);
    int arr[values_count], i = 0, value, check_value;
    printf("Enter %d values : \n", values_count);
	
	for( i = 0; i < values_count; i++)
	    scanf("%d", &arr[i]);
	
	printf("Enter the value to be found : ");
	scanf("%d", &value);
	
	check_value = linear_search(arr, value);
	if(check_value)
	    printf("%d is found at %d position", value, check_value);
	else
	    printf("%d is not found", value);
	return 0;
}

int linear_search(int a[], int element){
    int i, n = 10;
    for( i = 0; i < n; i++){
        if(a[i] == element)
           return i + 1;
    }
    return 0;
}



