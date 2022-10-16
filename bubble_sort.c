/* 
   DATE : 10 JUNE 2022
   TO SORT A GIVEN ARRAY (Bubble sort was used) */

#include<stdio.h>
#include<stdlib.h>
extern int n;
void swap(int * x, int * y){                           /* funtion to swap two gives values */
	int c;
	c=*x;
	*x=*y;
	*y=c;	
	}
void bubble_sort(int * arr, int n){                     /* Function to sort the array; using BUBBLE SORT */
	for(int i=n-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);}
			}
		}
	}

int main(){
	int n;
	printf("Enter the size of the array: ");          /* taking input and doing dynamic allocation for its memory */
	scanf("%d",&n);
	int *array;
	array= (int *) malloc(n*sizeof(int));
	for(int i=0; i<n; i++){
		printf("Enter the element %d of the array: ",i+1);
		scanf("%d",&array[i]);
		}
	printf("\n");
	
	
	printf("The array you entered is:\n");           /*printing array before sorting */
	for(int i=0; i<n; i++){
		printf("%d  ",array[i]);}
	printf("\n");
	
	bubble_sort(array,n);                            /* calling function to sort array */
	
	printf("The array after sorting is:\n");         /* printing array after sorting */
	for(int i=0; i<n; i++){
		printf("%d  ",array[i]);}
	printf("\n");
	
	free(array);                                     /* freeing the allocated memory*/
	return 0;
	
	}


