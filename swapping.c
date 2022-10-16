/* NAME : ANKUR KUMAR
   ROLL NUMBER : 21043
   program to swap location of two numbers in memory 
   DATE : 10 JUNE 2022 */




#include<stdio.h>
/* The function that swaps any two given numbers */
void swap(int *x, int *y){
	int c;
	c=*x;
	*x=*y;
	*y=c;}
int main(){
	int a,b;int *pa;int *pb;
	pa=&a;pb=&b;
	printf("Enter the value of variable 1: ");
	scanf("%d",&a);
	printf("Enter the value of variable 2: ");
	scanf("%d",&b);
	printf("The value of variable 1 is %d and its address is %p\n",*pa,pa); /* printing the numbers before swapping */
	printf("The value of variable 2 is %d and its address is %p\n",*pb,pb);
	printf("------------------------------------------------\n");
	swap(pa,pb);  /* This function will swap the two numbers */
	printf("The value of variable 1 is %d and its address is %p\n",*pa,pa); /* printing the numbers after swapping */
	printf("The value of variable 2 is %d and its address is %p\n",*pb,pb);
	return 0;}


