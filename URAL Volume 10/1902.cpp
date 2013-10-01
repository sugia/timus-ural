#include <stdio.h>
#include<stdlib.h>

int main(){ 
    int n;
    double y,x,i,s,t;;
    scanf("%d%lf%lf",&n,&t,&s); 
    for(i=1;i<=n;i++){
        scanf("%lf",&x);
        y=(t+s+x)/2;
        printf("%.6lf\n",y);
    }
     return 0;
}
