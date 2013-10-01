#include <cstdio>
int data[102]={0}, n, tmp, ans=0;
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;++i){scanf("%d", &tmp),++data[tmp-600];}    
    for(int i=0;i<=100;++i)ans+=data[i]/4;
    printf("%d\n", ans);
    return 0;
}