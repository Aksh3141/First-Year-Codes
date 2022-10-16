/* 
   TO CALCULATE DETERMINANT OF A GIVEN MATRIX 
   DATE : 31 MAY 2022 */

#include<stdio.h>
int det_n(int m, int n,int arr1[m][n]){
	int answer=0;
	if (m>2){
	for(int i=0; i<m; i++){
		int small_array[m-1][n-1];
		for(int x=0,q=0;x<m-1,q<m;q++,x++){
			for(int y=0,w=0;y<n-1,w<m;w++,y++){
				if(q!=0 || w!=i){
					small_array[x][y]=arr1[q][w];}
				if(w==i){
					y--;}}
			if(q==0){
				x--;}}
		if(i%2==0){
			answer=answer+(arr1[0][i]*det_n(m-1,n-1,small_array));}
		else{
			answer=answer-(arr1[0][i]*det_n(m-1,n-1,small_array));}
		}}
	if (m==2){
		return (arr1[0][0]*arr1[1][1])-(arr1[1][0]*arr1[0][1]);}
	return answer;
	}
int main(){
	int a,element,det;
	printf("Enter the number of rows/column in your matrix: ");
	scanf("%d",&a);
	int arr[a][a];
	for(int i=1; i<=a; i++){
		for(int j=1; j<=a; j++){
			printf("Enter the element in row %d and column %d : ",i,j);
			scanf("%d",&element);
			arr[i-1][j-1]=element;}}
	printf("\n So your matrix is: \n");
	for(int m=0; m<a; m++){
		for(int n=0; n<a; n++){
			printf("%4d ",arr[m][n]);}
		printf("\n");}
	printf("\n");
	printf(" The DETERMINANT of your matrix is: %d\n",det_n(a,a,arr));
	return 0;}
	
	
	
