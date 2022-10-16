/* Name: Ankur Kumar
   Roll number: 21043
   To print all possible permutations of a given string */



#include<stdio.h>
int no_of_char(char a[]){
	int i;
	for(i=0; a[i] != '\0'; i++);
	return i;
	}
	
int swapping_required(char a[], int x, int y){
	for(int i=x; i<y;i++){
		if(a[i]==a[y]){
			return 0;}
		}	
	return 1;
	}
void swap(char * a, char * b){
	char temp;
	temp = *a;
	*a=*b;
	*b=temp;}
	
void permutation(char a[], int first, int last){
	if(first == last){
		printf("%s\n",a);}
		
	else{
		for(int i=first; i<=last; i++){
			if(swapping_required(a,first,i)==1){
				swap(&a[first],&a[i]);
				permutation(a,first+1,last);
				swap(&a[first],&a[i]);
				}
			}
		}
	}
int main(){
	char a[100];
	int n;
	printf("Enter the string: ");
	scanf("%s",a);
	n=no_of_char(a);
	permutation(a,0,n-1);
	return 0;
	}













