#include <cstdio>
const int maxn=1e4+22;
double data[maxn];
int main(){
    int n;
    scanf("%d", &n);
    double y=0,x=0;       
    for(int i=1;i<=n;++i){
        scanf("%lf", &data[i]);
        y+=data[i],x+=i;
    } 
    y/=n,x/=n;
    double alpha=0,beta=0;
    for(int i=1;i<=n;++i){alpha+=(i-x)*(data[i]-y), beta+=(i-x)*(i-x);}        
    double b=alpha/beta,a=y-b*x;
    printf("%.8lf %.8lf\n", b+a, b);
    return 0;
}