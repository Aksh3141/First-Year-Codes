/* NAME : ANKUR KUMAR
   ROLL NUMBER : 21043
   LAB WEEK 9
   DATE : 19 JUNE 2022 */

#include<stdio.h>
#include<stdlib.h>
struct rational_number{
	int numerator,denominator;
	char sign;	
	}x,y,c,ans;
// function to find modulus of given number 
int mod(int x){
	if(x>=0){
		return x;}
	else{
		return -1*x;}}	
// function to fin the HCF of two given numbers 
int hcf(int a, int b){
	int r1,r2,t;
	r1=a; r2=b;
	while(r2!=0){
		t=r1;
		r1=r2;
		r2=t%r2;
		}
	return r1;}
// function to write a rational number in its simplest form
struct rational_number simplify(struct rational_number a){
	struct rational_number simple;
	int divide;
	divide=hcf(mod(a.numerator),mod(a.denominator));
	simple.numerator=mod(a.numerator/divide); simple.denominator=mod(a.denominator/divide);	
	simple.sign=a.sign;
	return simple;
	}
// defining a structure for rational number and taking input
struct rational_number enter_num(int i){
	int a,b;
	char ch;
	printf("Enter the numerator of the number %d: ",i);
	scanf("%d",&a);
	printf("Enter the denominator of the number %d: ",i);
	scanf("%d",&b);
	if(b==0){
		printf("ERROR!! INVALID INPUT\n");
		exit(1);}
	int divide;
	divide=hcf(mod(a),mod(b));
	x.numerator=mod(a/divide); x.denominator=mod(b/divide);
	if(a*b>=0){
		x.sign='+';}
	else{
		x.sign='-';}
	return x;} 
//adding rational numbers 
void add(struct rational_number a,struct rational_number b){
	if(a.sign=='-'){
		a.numerator=-1*a.numerator;}
	if(b.sign=='-'){
		b.numerator=-1*b.numerator;}
	struct rational_number sum;
	sum.numerator= a.numerator*b.denominator+b.numerator*a.denominator;
	sum.denominator= a.denominator*b.denominator;
	if(sum.numerator>=0){
		sum.sign='+';}
	else{
		sum.sign='-';}
	sum.numerator=mod(sum.numerator); sum.denominator=mod(sum.denominator);
	sum=simplify(sum);	
	printf("The sum of the two given numbers is: %c%d/%d\n",sum.sign,mod(sum.numerator),mod(sum.denominator));
	}
	
//subtracting rational numbers 
void subtract(struct rational_number a,struct rational_number b){
	if(a.sign=='-'){
		a.numerator=-1*a.numerator;}
	if(b.sign=='-'){
		b.numerator=-1*b.numerator;}
	struct rational_number diff;
	diff.numerator= a.numerator*b.denominator-b.numerator*a.denominator;
	diff.denominator= a.denominator*b.denominator;
	if(diff.numerator>=0){
		diff.sign='+';}
	else{
		diff.sign='-';}
	diff.numerator=mod(diff.numerator); diff.denominator=mod(diff.denominator);
	diff=simplify(diff);	
	printf("The difference of the two given numbers is: %c%d/%d\n",diff.sign,mod(diff.numerator),mod(diff.denominator));
	}
// multiplying rational numbers 	
void multiply(struct rational_number a,struct rational_number b){
	if(a.sign=='-'){
		a.numerator=-1*a.numerator;}
	if(b.sign=='-'){
		b.numerator=-1*b.numerator;}
	struct rational_number multi;
	multi.numerator= a.numerator*b.numerator;
	multi.denominator= a.denominator*b.denominator;
	if(multi.numerator>=0){
		multi.sign='+';}
	else{
		multi.sign='-';}
	multi.numerator=mod(multi.numerator); multi.denominator=mod(multi.denominator);
	multi=simplify(multi);	
	printf("The multiplication of the two given numbers is: %c%d/%d\n",multi.sign,mod(multi.numerator),mod(multi.denominator));	
	}
// dividing rational numbers 
void divison(struct rational_number a,struct rational_number b){
	if(a.sign=='-'){
		a.numerator=-1*a.numerator;}
	if(b.sign=='-'){
		b.denominator=-1*b.denominator;}
	struct rational_number div;
	div.numerator= a.numerator*b.denominator;
	div.denominator= a.denominator*b.numerator;
	if(div.numerator>=0){
		div.sign='+';}
	else{
		div.sign='-';}
	div.numerator=mod(div.numerator); div.denominator=mod(div.denominator);
	div=simplify(div);	
	printf("The division of the two given numbers is: %c%d/%d\n",div.sign,mod(div.numerator),mod(div.denominator));		
	}
int main(){
	struct rational_number num1,num2;
	num1=enter_num(1);
	num2=enter_num(2);
	add(num1,num2);
	subtract(num1,num2);
	multiply(num1,num2);
	divison(num1,num2);
	return 0;}






















