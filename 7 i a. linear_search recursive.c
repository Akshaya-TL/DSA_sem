// linear search recursive

#include <stdio.h>
#include <stdlib.h>

int *a;
int values_count;
int value;

int linear_search();
int main(void) {
	
	printf("Enter number of values : ");
    scanf("%d", &values_count);
    a = (int* )malloc(values_count*sizeof(int));
    int i = 0, check_value;
    printf("Enter %d values : \n", values_count);
	
	for( i = 0; i < values_count; i++)
	    scanf("%d", &a[i]);
	
	printf("Enter the value to be found : ");
	scanf("%d", &value);
	
	check_value = linear_search();
	if(check_value)
	    printf("%d is found at position %d", value, check_value);
	else
	    printf("%d is not found", value);
	return 0;
}
int i = 0;

int linear_search(){
	if(a[i] == value){
		return i + 1;
	}
	else if( i == values_count)
	   return 0;
	else{
		i = i + 1;
		linear_search();
	}
    
}



