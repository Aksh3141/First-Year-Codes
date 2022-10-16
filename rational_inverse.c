/* NAME: ANKUR KUMAR
   ROLL NUMBER: 21043
   PLEASE REFER readme(rational_inverse).txt
   INVERSE OF A RATIONAL MATRIX */
   
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
	scanf("%d %d",&a,&b);
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
struct rational_number add(struct rational_number a,struct rational_number b){
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
	return sum;
	}
	
//subtracting rational numbers 
struct rational_number subtract(struct rational_number a,struct rational_number b){
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
	return diff;
	}
// multiplying rational numbers 	
struct rational_number multiply(struct rational_number a,struct rational_number b){
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
	return multi;	
	}
// dividing rational numbers 
struct rational_number divison(struct rational_number a,struct rational_number b){
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
	return div;		
	}
//function to free a matrix
void free_matrix(struct rational_number ** arr, int n){
	for(int i=0; i<n; i++){
		free(arr[i]);}
	free(arr);}
//function to read a matrix and allocate memeory 
struct rational_number ** read_matrix(int n){
	struct rational_number ** mat;
	mat= (struct rational_number **)malloc(n*sizeof(struct rational_number *));
	for(int i=0; i<n; i++){
		mat[i]= (struct rational_number *)malloc(n*sizeof(struct rational_number));
		}
	struct rational_number a;	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("Enter the element in row %d and column %d: ",i+1,j+1);
			a=enter_num(0);
			mat[i][j]=a;}}
			
	return mat;}
// function to display matrix
void display_matrix(struct rational_number ** arr, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%c%d/%-8d",arr[i][j].sign,arr[i][j].numerator,arr[i][j].denominator);printf("\t");
			}
		printf("\n");}}
//function to create a sub matrix and remove a given row and column 		
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
	
// function to compute determinant of a given matrix
struct rational_number determinant(struct rational_number ** arr, int n){
	if(n==1){
		return arr[0][0];}
	if(n==2){
		return subtract(multiply(arr[0][0],arr[1][1]),multiply(arr[0][1],arr[1][0]));}	
	if(n>2){
		struct rational_number det; struct rational_number ** submat;
		det.numerator=0;det.denominator=1;det.sign='+';
		for(int i=0;i<n;i++){
			if(i%2==0){
				submat=sub_matrix(arr,n,0,i);
				det=add(det,multiply(arr[0][i],determinant(submat,n-1)));
				free_matrix(submat,n-1);}
			else{
				submat=sub_matrix(arr,n,0,i);
				det=subtract(det,multiply(arr[0][i],determinant(submat,n-1)));
				free_matrix(submat,n-1);}
			}
		return det;
		}}
//function to find adjoint, transpose and divide each element by det i.e. give the inverse		
struct rational_number ** adjoint(struct rational_number ** arr, int n,struct rational_number ans){
	struct rational_number ** adjoint;struct rational_number ** sub;struct rational_number det;
	adjoint = (struct rational_number **)malloc(n*sizeof(struct rational_number *));
	for(int i=0; i<n; i++){
		adjoint[i]=(struct rational_number *)malloc(n*sizeof(struct rational_number));}
	if(n==1){
	        adjoint[0][0].numerator=arr[0][0].denominator;adjoint[0][0].denominator=arr[0][0].numerator;
	        adjoint[0][0].sign=arr[0][0].sign;
	        adjoint[0][0]=simplify(adjoint[0][0]);
	        return adjoint;}
	
	else{
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			sub=sub_matrix(arr,n,i,j);
			det=determinant(sub,n-1);
			free_matrix(sub,n-1);
			struct rational_number negative;
			negative.sign='-';negative.numerator=1;negative.denominator=1;
			if((i+j)%2==0){
				adjoint[i][j]=det;}
			else{
				adjoint[i][j]=multiply(det,negative);}
			}
		}
	struct rational_number ** tpose;
	tpose = (struct rational_number **)malloc(n*sizeof(struct rational_number *));
	for(int i=0; i<n; i++){
		tpose[i]=(struct rational_number *)malloc(n*sizeof(struct rational_number));}
	for(int i=0;i<n;i++){
		for(int j=0; j<n; j++){
			tpose[i][j]=(divison((adjoint[j][i]),ans));
			}}
	free_matrix(adjoint,n);
	return tpose;}
	} 

int main(){
	int num; struct rational_number ** mat;struct rational_number ans; struct rational_number ** final;
	printf("Enter the number of rows/columns in you matrix: ");
	scanf("%d",&num);
	mat=read_matrix(num);
	if(num==0){
	        printf("Matrix can't have zero order!!\n");
	        exit(1);}
	printf("The matrix you entered is: \n");
	display_matrix(mat,num);
	ans=determinant(mat,num);
	if(ans.numerator==0){
		printf("INVERSE FOR THIS MATRIX DOES NOT EXIST!!\n");
		exit(1);}
	final=adjoint(mat,num,ans);
	printf("The inverse of the entered matrix is:\n");
	display_matrix(final,num);
	free_matrix(final,num);	
	free_matrix(mat,num);
	return 0;
	}

