//#include "stdafx.h"
#include<stdio.h>

#define N 3000
float c[N+5];

int main(){
    int i,k,m;
    float sum,a0,an,t;
    scanf("%d",&m);
    scanf("%f%f",&a0,&an);
    for(i=1;i<=m;i++)
      scanf("%f",&c[i]);
    sum=0;
    k=m;
    for(i=1;i<=m;i++){
        sum=sum+k*c[i];
        k--;
    }
    sum=sum*2;
    t=(an+m*a0-sum)/(m+1);
    printf("%.2f",t);
    return 0;
}
