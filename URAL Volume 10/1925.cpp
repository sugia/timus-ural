#include<stdio.h>
int main(){
    int n,i,x,y,sum;
    scanf("%d%d",&n,&sum);
    sum-=(n+1)*2;
    for(i=1; i<=n; i++){
        scanf("%d%d",&x,&y);
        sum=sum+x-y;
    }
    if(sum<0) printf("Big Bang!");
    else printf("%d\n",sum);
    return 0;
}
