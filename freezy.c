/* A program made for FUN :)*/

#include<stdio.h>
#include<stdlib.h>
int * convert_to_bin(long int x, long int req){
    int * arr;
    arr= (int *)malloc(req*sizeof(int));
    for(int i=0; i<req; i++){
        arr[i]=x%2;
        x=x/2;
    }
    return arr;   
}
long int power(long int x, long int y){
    long int prod =1;
    for(long int i=0; i<y; i++){
        prod=prod*x;
    }
    return prod;
}




int main(){
    long int a,b,alt;
    scanf("%ld %ld",&a,&b);
    alt=b; long int req=0;
    while(alt!=0){
        alt=alt/2;
        req=req+1;
    }
    int * my_arr;
    my_arr = convert_to_bin(b,req);
    long long int sum=0;
    for(long int i=0; i<req; i++){
        if (my_arr[i]==1){
            sum=sum+power(a,i);
        }}
    if(sum<(power(10,9)+7)){
        printf("%lld\n",sum);
    }
    if(sum>=(power(10,9)+7)){
        printf("%lld\n",sum%(power(10,9)+7));
    }
    free(my_arr);
    return 0;
}
