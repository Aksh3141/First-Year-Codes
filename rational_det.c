/* NAME : ANKUR KUMAR
   ROLL NUMBER : 21043
   LAB WEEK 11
   DATE : 9th JULY 2022
   TO find the DETERMINANT of a rational matrix of arbitrary precision 
   use the README file for instructions */

#include<stdio.h>
#include<stdlib.h>

/*-------------------------------------------------------------------------------------------------------------
        TAKING STRING INPUT AND DEFINE OPERATIONS LIKE ADDITION, SUBTRACTION, MULTIPLICATION AND DIVISION */
        
//STRUCTURE FOR INTEGERS         
struct my_int{
	int sign;
	char * digits;
	int last_index;}x;
	
/*THIS FUNCTION CALCULATES NO OF DIGITS IN AN INTEGER */
int no_of_digits(char a[]){
	int i;
	for(i=0; a[i]!='\0'; i++);
	return i;}
	
/* COMPARES TWO INTEGERS(STRUCTURES) AND RETURNS 1 IF INTEGER IN FIRST ARGUMENT IS LARGER */	
int larger_string(struct my_int a,struct my_int b){
	if(a.last_index>b.last_index){
		return 1;}
	if(a.last_index<b.last_index){
		return 0;}
	if(a.last_index==b.last_index){
		int i=0;
		while(a.digits[i]==b.digits[i]){
			i++;}
		if(a.digits[i]=='\0'){
			return 1;}
		if(a.digits[i]>b.digits[i]){
			return 1;}
		else{
			return 0;}}
	}
	
/* COMPARES TWO STRING AND RETURNS 1 IF STRING IN FIRST ARGUMENT IS LARGER(NUMERICALLY) */
int larger_number(char a[], char b[]){
	int a1=no_of_digits(a); int a2=no_of_digits(b);
	if(a1>a2){
		return 1;}
	if(a2>a1){
		return 0;}
	if(a1==a2){
		int i=0;
		while(a[i]==b[i] && a[i]!='\0'){
			i++;}
		if(a[i]=='\0'){
			return 1;}
		if(a[i]>b[i]){
			return 1;}
		else{
			return 0;}}
	}
	
/* THIS FUNCTION REMOVES LEADING ZEROS FROM A STRING */	
char * remove_zero(char a[]){
	char *b;
	int n=no_of_digits(a);
	int i;
	for(i=0; i<n ;i++){
		if(a[i]!='0'){
			i--;
			break;}}
	b=(char *)calloc((n-i+2),sizeof(char));
	if(n!=i){
	for(int j=0; j<n-i; j++){
		b[j]=a[j+i+1];}}
	if(n==i){
		b[0]='0'; b[1]=='\0';}
	return b;
	}

/* THIS FUNCTION APPENDS A CHARACTER IN THE END OF A STRING*/	
char * append(char a[], char b){
	int a1=no_of_digits(a);
	char * new;
	new= (char *)calloc((a1+2),sizeof(char));
	for(int i=0; i<=a1+1; i++){
		if(i<a1)
			new[i]=a[i];
		if(i==a1)
			new[i]=b;
		if(i==a1+1)
			new[i]='\0';	
		}
	return new;
	}
	
/*THIS CODE BLOCK DISPLAYS INTERGERS (MY_INT STRUCTURE) */
void display_int(struct my_int display){
	printf("%d\n",display.sign);
	printf("%d\n",display.last_index);	
	for(int i=0; i<=display.last_index;i++){
		printf("%c",display.digits[i]);}
	printf("\n");
	}
	
/*FUCNTION TO READ A INTEGER i.e. TAKE INPUT FROM USER */
struct my_int read_int(int var){
	char a[100];
	if(var==0){printf("Enter numerator: ");}
	if(var==1){printf("Enter denominator: ");}
	scanf("%s",a);
	
	if(a[0]=='-'){
		x.sign=-1;}
	else{
		x.sign=1;}
	
	char b[100];
	if(a[0]=='-'){
		for(int i=0; i<no_of_digits(a); i++){
			b[i]=a[i+1];}}	
	else{
		for(int i=0; i<=no_of_digits(a); i++){
			b[i]=a[i];}}
	
	x.last_index=no_of_digits(b)-1;
	x.digits=(char *)malloc(sizeof(char)*(x.last_index+2));
	for(int i=0; i<=x.last_index+1; i++){
		x.digits[i]=b[i];}
	return x;
	}

// FUNCTION TO ADD TWO STRINGS TOGETHER 	
char * add(char *str1, char *str2){
	int a=no_of_digits(str1);
	int b=no_of_digits(str2);
	char *num3; char *num4;
	num3=(char *)calloc((a+2),sizeof(char));
	num3[a+1]='\0';	
	char num1[a+1],num2[a+1];
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
	num4=remove_zero(num3);
	free(num3);
	return num4;
	}
	
//FUNCTION TO SUBTRACT TWO INTEGERS	
char * subtract(char str1[], char str2[]){
	int a=no_of_digits(str1);
	int b=no_of_digits(str2);
	char *num3; char *num4;
	num3=(char *)calloc((a+2),sizeof(char));
	num3[a+1]='\0';
	char num1[a+1],num2[a+1];
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
	num4=remove_zero(num3);
	free(num3);
	return num4;
	}
	
// TO MULTIPLY TWO STRINGS(NUMBERS)
char * multiply(char a[],char b[]){          /*function to multiply the numbers*/
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
	char *answer; char *ranswer;
	answer = (char *)calloc((a1+b1+1),sizeof(char));
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
	ranswer=remove_zero(answer);
	free(answer);
	return ranswer;
	}
	
//FUNCTION TO DIVIDE TWO NUMBERS 	
char * division(char a[], char b[]){
	char * answer;
	if(larger_number(a,b)==0){
		answer=(char *)calloc(2,sizeof(char));
		answer[0]='0'; answer[1]='\0';}
	else{
		int a1,a2,a3,j=0;
		a1=no_of_digits(a);
		a2=no_of_digits(b);
		char *quotient; char *work; char *worker;
		quotient=(char *)calloc((a1+1),sizeof(char));
		work=(char *)calloc((a2+1),sizeof(char));
		worker=(char *)calloc((a2+1),sizeof(char));
		for(int i=0; i<a2; i++){
			work[i]=a[i];}
		char mul[2]; mul[1]='\0'; char new;
		while(a[a2+j-1]!='\0'){
			for(int i=9;i>=0;i--){
				mul[0]=(char)(i+48);
				worker=multiply(b,mul);
				if(larger_number(work,worker)==1){
					quotient[j]=mul[0];
					new= a[a2+j];
					work=append(subtract(work,worker),new);
					work=remove_zero(work);
					j++;	
					break;}}
				}
		quotient[j]='\0';
		answer=remove_zero(quotient);
		free(quotient); free(worker); free(work);
		}
	return answer;
	}

//FUNCTION TO COMPUTE REMAINDER USING THE DIVISION FUNCTION	
char * remain(char a[], char b[]){
	char * remain; char * multi; char * quot;
	quot=division(a,b);
	multi=multiply(b,quot);
	remain=subtract(a,multi);
	return remain;
	
	}

// TO ADD TWO INTEGER STRUCTURES(MY_INT)	
struct my_int add_int(struct my_int a, struct my_int b){
	struct my_int c;
	if(a.sign ==1 && b.sign == 1){
		if(a.last_index >= b.last_index){
			c.digits=add(a.digits,b.digits);
			c.sign=1;}
		else{
			c.digits=add(b.digits,a.digits);
			c.sign=1;}
			}
	if(a.sign ==-1 && b.sign ==-1){
		if(a.last_index >= b.last_index){
			c.digits=add(a.digits,b.digits);
			c.sign=-1;}
		else{
			c.digits=add(b.digits,a.digits);
			c.sign=-1;}
			}
	if(a.sign==1 && b.sign==-1){
		if(larger_string(a,b)==1){
			c.digits=subtract(a.digits,b.digits);
			c.sign=1;}
		else{
			c.digits=subtract(b.digits,a.digits);
			c.sign=-1;}
			}
	if(a.sign==-1 && b.sign==1){
		if(larger_string(a,b)==1){
			c.digits=subtract(a.digits,b.digits);
			c.sign=-1;}
		else{
			c.digits=subtract(b.digits,a.digits);
			c.sign=1;}
			}
	c.last_index=no_of_digits(c.digits)-1;
	return c;
		}
		
//TO MULTIPLY TWO STRUCTURES(MY_INT)
struct my_int multiply_int(struct my_int a, struct my_int b){
	struct my_int c;
	if(a.sign*b.sign==1){
		c.sign=1;}
	if(a.sign*b.sign==-1){
		c.sign=-1;}
	c.digits=multiply(a.digits,b.digits);
	c.last_index=no_of_digits(c.digits)-1;
	return c;
	}

//TO SUBTRACT TWO STRUCTURES
struct my_int subtract_int(struct my_int a, struct my_int b){
	if(b.sign==1){
		b.sign=-1;}
	else{
		b.sign=1;}	
	struct my_int d;
	d=add_int(a,b);
	return d;	
	}

//TO FIND THE QUOTIENT AFTER DIVISION OF TWO INTEGERS 
struct my_int quotient_int(struct my_int a, struct my_int b){
	struct my_int d;
	if(a.sign*b.sign==1){
		d.sign=1;
		d.digits=division(a.digits,b.digits);
		d.last_index=no_of_digits(d.digits)-1;}
		
	if(a.sign*b.sign==-1){
		d.sign=-1;
		d.digits=division(a.digits,b.digits);
		d.last_index=no_of_digits(d.digits)-1;}
	return d;	
	}
	
//TO FIND THE REMAINDER AFTER DIVISION 
struct my_int remain_int(struct my_int a, struct my_int b){
	struct my_int d;
	d.sign=1;
	d.digits=remain(a.digits,b.digits);
	d.last_index=no_of_digits(d.digits)-1;
	return d;	
	}

//TO FIND THE HCF OF TWO NUMBERS(CHARACTER ARRAYS)
char * hcf(char a[], char b[]){
	char * r1; char *r2; char *r3;
	r1=a; r2=b;
	while(r2[0] != '0'){
		r3=r1;
		r1=r2;
		r2=remain(r3,r2);
		}
	return r1;
	}
/*----------------------------------------------------------------------------------------------------------
	CODE BLOCK TO DEFINE STRUCTURE OF RATIONAL NUMBER AND ITS ARITHMETIC OPERATIONS */
	
struct rational_number{
	struct my_int numerator,denominator;
	char sign_rat;	
	}y;
	
void free_matrix(struct rational_number ** matrix, int n){
	for(int i=0; i<n; i++){
			free(matrix[i]);}
		free(matrix);}
		
//TO DISPLAY A RATIONAL NUMBER 
void display_rational(struct rational_number a){
	printf("%c%s/%s\n", a.sign_rat,a.numerator.digits,a.denominator.digits);}
		
/*THIS FUNCTIONS RETURN THE NUMBER 0 AS A STRUCTURE OF RATIONAL NUMBER WHICH CAN BE STORED IN A VARIABLE 
               THIS WILL BE USED TO STORE THE VALUE 0 IN DETERMINANT VARIABLE INITIALLY*/ 
struct rational_number zero_rat_num(int i){
	struct rational_number a;
	char *b; b=(char *)calloc(3,sizeof(char)); b[0]='0'; b[1]='\0';
	char *c; c=(char *)calloc(3,sizeof(char)); c[0]='1'; c[1]='\0';
	a.sign_rat='+';
	a.numerator.sign=1;
	a.numerator.digits=b;
	a.numerator.last_index=no_of_digits(a.numerator.digits)-1;
	
	a.denominator.sign=1;
	a.denominator.digits=c;
	a.denominator.last_index=no_of_digits(a.denominator.digits)-1;
	return a;
	}

//FUNCTION THAT DIVIDES INTEGERS BY THEIR HCF, BASICALLY TO SIMPLIFY RATIONAL NUMBERS
struct rational_number simplify(struct rational_number a){
	struct rational_number simple;
	struct my_int divide;
	divide.digits=hcf(a.numerator.digits,a.denominator.digits);
	divide.last_index=no_of_digits(divide.digits)-1; divide.sign=1;
	simple.numerator=quotient_int(a.numerator,divide);
	simple.denominator=quotient_int(a.denominator,divide);	
	simple.sign_rat=a.sign_rat;
	return simple;}
	

//FUNCTION TO TAKE RATIONAL NUMBER AS INPUT AND STORE IT A VARIABLE AND RETURN IT	
struct rational_number enter_num(int i){
	struct rational_number alpha;
	struct my_int a,b;
	a=read_int(0);
	b=read_int(1);
	
	if(a.sign*b.sign==1){
		alpha.sign_rat='+';}
	if(a.sign*b.sign==-1){
		alpha.sign_rat='-';}
	b.digits=remove_zero(b.digits);
	if(b.digits[0]=='0'){
		printf("Zero denominator not allowed!!\n");
		exit(1);}
	alpha.numerator=a;
	alpha.denominator=b;
	alpha=simplify(alpha);
	return alpha;
	} 
	
//FUNCTION TO ADD TWO RATIONAL NUMBERS USES THE FUNCTIONS FROM INTEGER PART
struct rational_number add_rational(struct rational_number a,struct rational_number b){
	struct rational_number sum;
	sum.numerator= add_int(multiply_int(a.numerator,b.denominator),multiply_int(b.numerator,a.denominator));
	sum.denominator= multiply_int(a.denominator,b.denominator);
	if(sum.numerator.sign*sum.denominator.sign==1){
		sum.sign_rat='+';}
	else{
		sum.sign_rat='-';}
	sum=simplify(sum);	
	return sum;}
	
//FUNCTION TO SUBTRACT TWO RATIONAL NUMBERS 
struct rational_number subtract_rational(struct rational_number a, struct rational_number b){
	struct rational_number diff;
	diff.numerator= subtract_int(multiply_int(a.numerator,b.denominator),multiply_int(b.numerator,a.denominator));
	diff.denominator= multiply_int(a.denominator,b.denominator);
	if(diff.numerator.sign*diff.denominator.sign==1){
		diff.sign_rat='+';}
	else{
		diff.sign_rat='-';}
	diff=simplify(diff);	
	return diff;}
	
//FUNCTION TO MULTIPLY TWO RATIONAL NUMBERS
struct rational_number multiply_rational(struct rational_number a, struct rational_number b){
	struct rational_number multi;
	multi.numerator=multiply_int(a.numerator,b.numerator);
	multi.denominator=multiply_int(a.denominator,b.denominator);
	if(multi.numerator.sign*multi.denominator.sign==1){
		multi.sign_rat='+';}
	else{
		multi.sign_rat='-';}	
	multi=simplify(multi);
	return multi;
	}

//FUNCTION TO DIVIDE TWO RATIONAL NUMBERS 
struct rational_number divide_rational(struct rational_number a, struct rational_number b){
	if(b.numerator.digits[0]=='0'){
		printf("division by zero!!\n");
		exit(1);}
	struct rational_number div;
	div.numerator=multiply_int(a.numerator,b.denominator);
	div.denominator=multiply_int(a.denominator,b.numerator);
	if(div.numerator.sign*div.denominator.sign==1){
		div.sign_rat='+';}
	else{
		div.sign_rat='-';}	
	div=simplify(div);
	return div;
	}		

/*-------------------------------------------------------------------------------------------------------------------
             DOING MATRIX OPERATIONS i.e. READING, DISPLAYING, FINDING SUB MATRIX AND COMPUTING DETERMINANT */


//FUNCTION TO TAKE INPUT FROM USER AND CONSTRUCT A MATRIX (2-D ARRAY)
struct rational_number ** read_matrix(int n){
	struct rational_number ** mat;
	mat= (struct rational_number **)malloc(n*sizeof(struct rational_number *));
	for(int i=0; i<n; i++){
		mat[i]= (struct rational_number *)malloc(n*sizeof(struct rational_number));
		}
	struct rational_number a;	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("Enter the element in row %d and column %d:\n",i+1,j+1);
			a=enter_num(0);
			mat[i][j]=a;}}
			
	return mat;}
	
// FUNCTION TO DISPLAY THE MATRIX; WILL NOT LOOK CLEAN IF VALUES ARE VERY BIG
void display_matrix(struct rational_number ** arr , int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%c%s/%s",arr[i][j].sign_rat,arr[i][j].numerator.digits,arr[i][j].denominator.digits);printf("\t");
			}
		printf("\n");}}
		
// FUNCTION TO CONSTRUCT A SUB MATRIX BY REMOVING A CERTAIN ROW AND COLUMN 
struct rational_number ** sub_matrix(struct rational_number ** arr,int n, int row, int col){
	struct rational_number ** sub;
	sub=(struct rational_number **)malloc((n-1)*sizeof(struct rational_number *));
	for(int i=0; i<n-1; i++){
		sub[i]=(struct rational_number *)malloc((n-1)*sizeof(struct rational_number));
		}
		
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i<row && j<col){
				sub[i][j]=arr[i][j];}
			if(i<row && j>col){
				sub[i][j-1]=arr[i][j];}
			if(i>row && j<col){
				sub[i-1][j]=arr[i][j];}
			if(i>row && j>col){
				sub[i-1][j-1]=arr[i][j];}	
			}
		}
	return sub;
	}

// FUNCTION TO ACTUALLY COMPUTE THE DETERMINANT 
struct rational_number determinant(struct rational_number ** arr, int n){
	if(n==1){
		return arr[0][0];}
	if(n==2){
		return subtract_rational(multiply_rational(arr[0][0],arr[1][1]),multiply_rational(arr[0][1],arr[1][0]));}	
	if(n>2){
		struct rational_number det; struct rational_number ** submat;
		det=zero_rat_num(0);
		for(int i=0;i<n;i++){
			if(i%2==0){
				submat=sub_matrix(arr,n,0,i);
				det=add_rational(det,multiply_rational(arr[0][i],determinant(submat,n-1)));
				free_matrix(submat,n-1);}
			else{
				submat=sub_matrix(arr,n,0,i);
				det=subtract_rational(det,multiply_rational(arr[0][i],determinant(submat,n-1)));
				free_matrix(submat,n-1);}
			}
		return det;}
		}
		
 /*------------------------------------------------------------------------------------------------------------
                              INT MAIN FOR TAKING ACTUAL INPUT FROM USER*/
			
int main(){
	int n;
	printf("Enter the number of rows/column: ");
	scanf("%d",&n);
	struct rational_number ** matrix; struct rational_number a;
	matrix = read_matrix(n);
	printf("\n");
	printf("----------------------------------------\n");
	display_matrix(matrix,n);
	printf("----------------------------------------\n");
	printf("\n");
	printf("The determinant of the matrix is: ");
	a=determinant(matrix,n);
	display_rational(a);
	free(a.numerator.digits); free(a.denominator.digits);
	free_matrix(matrix,n);
	return 0;}
	
	
	
	
	
	
	
	
	
