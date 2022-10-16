/* NAME : ANKUR KUMAR
   ROLL NUMBER : 21043
   DATE : 23 MAY 2022
   TO CALCULATE THE HCF AND LCM OF TWO GIVEN NUMBERS) */



#include<stdio.h>
long int hcf(long int a, long int b){        /*function to calculate hcf by euclids algorithm*/
	long int r2;
	do{
		r2=a%b;
		a=b;
		b=r2;
		}
	while(r2!=0);
	return a;
	}


void lcm(long int a, long int b){           /*function to calculate lcm of two numbers*/
	long int ans;
	ans=(a*b)/hcf(a,b);
	printf("The LCM of the numbers is : %ld\n",ans);    /*this is a void function and it doesn't returns any value*/
	}


  
int main(){                                  /*main function to take the input and print the answer*/
	long int num1,num2,ans1;
	printf("Enter the number 1:\n");
	scanf("%ld",&num1);
	printf("Enter the number 2:\n");
	scanf("%ld",&num2);
	if(num1>=num2){
		ans1=hcf(num1,num2);
		printf("The HCF of the numbers is : %ld\n",ans1);
		lcm(num1,num2);}
	else{
		ans1=hcf(num2,num1);
		printf("The HCF of the numbers is : %ld\n",ans1);
		lcm(num1,num2);}
	return 0;}
