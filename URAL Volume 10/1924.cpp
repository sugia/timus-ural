#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
int main(){
    scanf("%d",&n);
    n=(1+n)*n/2;
    n=n%2!=0?1:2;
    if(n==1) printf("grimy");
    else if(n==2) printf("black"); 
    return 0;
}
