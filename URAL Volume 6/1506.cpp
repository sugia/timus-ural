#include <cstdio>
const int maxn=102;
int data[maxn];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=1;i<=n;++i)
        scanf("%d", &data[i]); 
    k=n%k?n/k+1:n/k;   
    for(int i=1;i<=k;++i){
        int step=i;
        while(step<=n){
            printf("%4d", data[step]);
            step+=k;              
        }        
        printf("\n");
    }    
    return 0;
}