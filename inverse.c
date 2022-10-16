/* NAME: ANKUR KUMAR
   ROLL NUMBER: 21043
   LAB WEEK 9
   FINDING INVERSE OF A GIVEN MATRIX 
   DATE : 19 JULY 2022 */

#include<stdio.h>
#include<stdlib.h>
//function to free a matrix
void free_matrix(int ** arr, int n){
	for(int i=0; i<n; i++){
		free(arr[i]);}
	free(arr);}
//function to read a matrix and allocate memeory 
int ** read_matrix(int n){
	int ** mat;
	mat= (int **)malloc(n*sizeof(int *));
	for(int i=0; i<n; i++){
		mat[i]= (int *)malloc(n*sizeof(int));
		}
	int a;	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("Enter the element in row %d and column %d: ",i+1,j+1);
			scanf("%d",&a);
			mat[i][j]=a;}}
			
	return mat;}
// function to display matrix
void display_matrix(int ** arr, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%4d",arr[i][j]);
			}
		printf("\n");}}
//function to create a sub matrix and remove a given row and column 		
int ** sub_matrix(int ** arr,int n, int row, int col){
	int ** sub;
	sub=(int **)malloc((n-1)*sizeof(int *));
	for(int i=0; i<n-1; i++){
		sub[i]=(int *)malloc((n-1)*sizeof(int));
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
int determinant(int ** arr, int n){
	if(n==1){
		return arr[0][0];}
	if(n==2){
		return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];}	
	if(n>2){
		long long int det=0; int ** submat;
		for(int i=0;i<n;i++){
			if(i%2==0){
				submat=sub_matrix(arr,n,0,i);
				det=det+arr[0][i]*determinant(submat,n-1);
				free_matrix(submat,n-1);}
			else{
				submat=sub_matrix(arr,n,0,i);
				det=det-arr[0][i]*determinant(submat,n-1);
				free_matrix(submat,n-1);}
			}
		return det;
		}}
//function to find adjoint, transpose and divide each element by det i.e. give the inverse		
float ** adjoint(int ** arr, int n,int ans){
	int ** adjoint;int ** sub;int det;
	adjoint = (int **)malloc(n*sizeof(int *));
	for(int i=0; i<n; i++){
		adjoint[i]=(int *)malloc(n*sizeof(int));}
	
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			sub=sub_matrix(arr,n,i,j);
			det=determinant(sub,n-1);
			free_matrix(sub,n-1);
			if((i+j)%2==0){
				adjoint[i][j]=det;}
			else{
				adjoint[i][j]=-det;}
			}
		}
	float ** tpose;
	tpose = (float **)malloc(n*sizeof(float *));
	for(int i=0; i<n; i++){
		tpose[i]=(float *)malloc(n*sizeof(float));}
	for(int i=0;i<n;i++){
		for(int j=0; j<n; j++){
			tpose[i][j]=((float)(adjoint[j][i])/ans);
			}}
	free_matrix(adjoint,n);
	return tpose;
	}

int main(){
	int num; int ** mat;int ans; float ** final;
	printf("Enter the number of rows/columns in you matrix: ");
	scanf("%d",&num);
	mat=read_matrix(num);
	printf("The matrix you entered is: \n");
	display_matrix(mat,num);
	ans=determinant(mat,num);
	if(ans==0){
		printf("INVERSE FOR THIS MATRIX DOES NOT EXIST!!\n");
		exit(1);}
	final=adjoint(mat,num,ans);
	printf("The inverse of the entered matrix is:\n");
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			printf("%8.2f",final[i][j]);}
		printf("\n");}
		
	for(int i=0; i<num; i++){
		free(final[i]);}
	free(final);
	free_matrix(mat,num);
	return 0;
	}



















