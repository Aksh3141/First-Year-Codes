/* NAME: ANKUR KUMAR
   ROLL NUMBER: 21043
   To give the product of two integral polynomials
   DATE: 24 MAY 2022 */


#include<stdio.h>
int main(){
	int num1[10],num2[10],num3[20];
	int a,b,c,d;
	printf("Enter the degree of first polynomial: ");      /*taking coefficients of the first polynomial*/
	scanf("%d",&a);
	printf("\n");
	for(int i=a; i>=0; i--){
		printf("Enter the coefficient of term with degree %d: ",i);
		scanf("%d",&c);
		num1[i]=c;}
	printf("\n\n");
	printf("Enter the degree of second polynomial: ");     /*taking coefficients of the second polynomial*/
	scanf("%d",&b);
	printf("\n");
	for(int j=b; j>=0; j--){
		printf("Enter the coefficient of term with degree %d: ",j);
		scanf("%d",&d);
		num2[j]=d;}
	for(int o=0; o<=a+b; o++){                              /*loop to calculate coefficients of the product of polynomials */
	int ans=0;
	for(int m=a; m>=0; m--){
		for(int n=b; n>=0; n--){
			if(m+n==o){
				ans=(num1[m]*num2[n])+ans;}
			}
		}
	num3[o]=ans;}
	printf("\n\n");
	printf("THE PRODUCT OF THESE POLYNOMIALS IS:\n");         /*printing the final result */
	for(int k=0; k<=a+b; k++){
		printf("Coefficient of term with degree %d is : %d\n",k,num3[k]);
		
		}
	return 0;}
