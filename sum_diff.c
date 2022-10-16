/* 
   TO ADD TWO GIVEN NUMBERS AS STRING 
   This program takes two numbers as input and gives the sum and difference of those
   numbers as output.
   It can add or subtract numbers of arbitrary length.  */


#include<stdio.h>

// function to calculate the length of a string

int no_of_digits(char a[]){
	int i=0;
	while(a[i]!='\0'){
		i+=1;}
	return i;
	}
	
// function to add two numbers as string

void add(char str1[], char str2[], int a, int b){
	char num1[a+1],num2[a+1],num3[a+2];
	num3[a+1]='\0';
	num1[a]='\0';
	num2[a]='\0';
	int i=0;
	while(i<a){
		num1[a-1-i]=(char)(str1[a-1-i]);
		if(i<b){
			num2[a-1-i]=(char)(str2[b-1-i]);}
		else{
			num2[a-1-i]=(char)(48);}
		i+=1;	
		}
	int alpha,beta,carry=0;
	for(int j=0; j<=a; j++){
		if (a-j>0){
			alpha=num1[a-1-j]+num2[a-1-j]-48+carry;
			if(alpha>57){
				beta=alpha-10;
				num3[a-j]=(char)(beta);
				carry=1;}
			if(alpha<=57){
				num3[a-j]=(char)(alpha);
				carry=0;}}
		if(a-j==0){
			num3[0]=(char)(48+carry);}
		}
	printf("The sum of the two numbers is:\n");
	printf("%s\n",num3);
	}
	
// function to subtract two numbers as string
	
void difference(char str1[], char str2[], int a, int b){
	char num1[a+1],num2[a+1],num3[a+2];
	num3[a+1]='\0';
	num1[a]='\0';
	num2[a]='\0';
	int i=0;
	while(i<a){
		num1[a-1-i]=(char)(str1[a-1-i]);
		if(i<b){
			num2[a-1-i]=(char)(str2[b-1-i]);}
		else{
			num2[a-1-i]=(char)(48);}
		i+=1;	
		}
	int alpha,carry=0;
	for(int j=0; j<a; j++){
		if ((num1[a-1-j]-carry)>=num2[a-1-j]){
			alpha=num1[a-1-j]-carry-num2[a-1-j]+48;
			num3[a-j]=(char)(alpha);
			carry=0;}
		if ((num1[a-1-j]-carry)<num2[a-1-j]){
			alpha=num1[a-1-j]-carry+10-num2[a-1-j]+48;
			num3[a-j]=(char)(alpha);
			carry=1;}
		}
	num3[0]=(char)(48);
	printf("The difference of the two numbers is:\n");
	printf("%s\n",num3);
	}


int main(){
	char str1[1000],str2[1000];
	int len1,len2;
	printf("Enter the number 1:\n");
	scanf("%s",str1);
	printf("Enter the number 2:\n");
	scanf("%s",str2);
	len1=no_of_digits(str1);
	len2=no_of_digits(str2);
	if (len1>=len2){
		add(str1,str2,len1,len2);
		difference(str1,str2,len1,len2);}
	if (len2>len1){
		add(str2,str1,len2,len1);
		difference(str2,str1,len2,len1);}
	return 0;
	}
