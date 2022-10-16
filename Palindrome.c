/* Program to check whether a given string of characters is a Palindrome or not
   This program also ignores white spaces between strings if any */

#include<stdio.h>
#include<ctype.h>
int main(){
	printf("Enter your string:\n");
	char str[100];
	scanf("%[^\n]",str);
	char new[100];
	int i=0,k=0;
	while(str[i] != '\0'){
		if(str[i]!=' ' && str[i]!='\0'){
			new[k]=toupper(str[i]);
			k+=1;
			}
		if(str[i]=='\0'){
			new[k]='\0';}
		i+=1;
		}
	int flag=0;
	for(int m=0; m<=(k+1)/2; m++){
		if(new[m]!=new[k-m-1]){
			printf("NOT A PALINDROME\n");
			flag=1;
			break;}
		}
	if(flag==0){
		printf("PALINDROME\n");}
	return 0;
	}
