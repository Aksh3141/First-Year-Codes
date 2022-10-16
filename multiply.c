/* NAME: ANKUR KUMAR
   ROLL NUMBER: 21043
   TO MULTIPLY TO NUMBERS (AS STRING)
   DATE: 23 MAY 2022 */



#include<stdio.h>
int no_of_digits(char a[]){         /*function to give no of digits in a number given as string */
	int i;
	for (i=0; a[i]!='\0'; i++);
	return i;}

void multiply(char a[],char b[]){          /*function to multiply the numbers*/
	int a1,b1,alpha,beta,carry=0;
	a1=no_of_digits(a);
	b1=no_of_digits(b);
	char arr[b1][a1+b1];
	int min=b1;
	for(int i=0; i<b1; i++){
		int max=a1;
		for(int j=0; j<a1+b1; j++){
			if(j<i){
				arr[i][a1+b1-1-j]=(char)(48);
				carry=0;
				continue;}
			if(j>=i && max-1>=0){
				alpha=(a[max-1]-48)*(b[min-1]-48)+carry;
				if(alpha>9){
					beta=alpha%10;
					carry=alpha/10;
					arr[i][a1+b1-1-j]=(char)(beta+48);}
				if(alpha<=9){
					carry=0;
					arr[i][a1+b1-1-j]=(char)(alpha+48);}}
			if(max-1<0){
				arr[i][a1+b1-1-j]=(char)(carry+48);
				carry=0;}
			max=max-1;}
		min=min-1;
		}
	/*column addition*/
	int carry2=0,ans;
	char answer[a1+b1+1];
	answer[a1+b1]='\0';
	for(int x=0; x<a1+b1; x++){
		int var=0;
		for(int y=0; y<b1; y++){
			var=(arr[y][a1+b1-1-x]-48)+var;
			}
		var=var+carry2;
		ans=var%10;
		carry2=var/10;
		answer[a1+b1-1-x]=(char)(ans+48);}
	printf("The product of the two numbers is:\n");
	printf("%s\n",answer);
	}


int main(){
	char str1[100],str2[100];
	int len1,len2;
	printf("Enter the number 1:\n");
	scanf("%s",str1);
	printf("Enter the number 2:\n");
	scanf("%s",str2);
	len1=no_of_digits(str1);
	len2=no_of_digits(str2);
	if (len1>=len2){
		multiply(str1, str2);}
	if (len2>len1){
		multiply(str2, str1);}
	return 0;	
	}
