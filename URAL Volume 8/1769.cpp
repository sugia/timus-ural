#include <cstdio>
#include <string>
const int maxn = 1000022;
bool vi[maxn];
char str[maxn];
int main(){
    while(scanf("%s",str)!=EOF){
        memset(vi, 0, sizeof(vi));
        for(int i=0;str[i];++i){
            int tmp=0;
            for(int j=1;j<=6 && str[i+j-1];++j){tmp=10*tmp+str[i+j-1]-'0', vi[tmp]=1;}
        }
        for(int i=1;i<maxn;i++)
            if(!vi[i]){
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}