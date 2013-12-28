#include<stdio.h>
int main(){
    int m,n,ans;
    scanf("%d %d",&m,&n);
    if ((m==1)||(n==1)) ans=int((m+n)/2);
    else{
        if (((m*n)%3)==0) ans=2;
        else ans=1;
    }    
    printf("%d\n",ans);
    return 0;
}
