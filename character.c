/* 
   Date: 11/05/2022
   This program converts a character (input for number given as string) to number (int) */

#include<stdio.h>

//function to convert character to number 
int char_to_int(char ch){
	char a;
	if (ch>=48 && ch<=57){
		a= ch-48;
		a=(int)a;
		return a;
		}
	}
// to take input 		
int main(){
	char input;
	int input2,count=1,number;
	
	scanf(" %c",&input);
	printf("%d\n",char_to_int(input));
	
	scanf("%d",&input2);
	number=input2;

	do{
		count=count+1;
		number=number/10;
	}while(number/10!=0);
	char word[count];
	for(int i=1; i<=count; i++){
		word[(count-i)]=(char)((input2%10)+48);
		input2=input2/10;}
	printf("%s\n",word);
	
	
	
	return 0;
	}
	
