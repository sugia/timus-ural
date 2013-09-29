#include <iostream>
using namespace std;
const int maxn=522, maxint=2100000022;
int data[maxn], white[maxn], black[maxn], f[maxn][maxn];
int cal(int x, int y){return(white[y]-white[x-1])*(black[y]-black[x-1]);}
int main(){
    int n, m;
    cin>>n>>m;
    white[0]=0,black[0]=0;
    for(int i=1;i<=n;++i){
        cin>>data[i];
        white[i]=white[i-1],black[i]=black[i-1];
        data[i]?++black[i]:++white[i];
    }   
    for(int i=1;i<=n;++i)
        f[i][0]=maxint;
    for(int i=1;i<=m;++i)
        f[0][i]=maxint;
    f[0][0]=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=min(i, m);++j){
            f[i][j]=maxint;   
            for(int k=1;k<=i;++k)
                if(i-k>=j-1)
                    f[i][j]=min(f[i][j], f[i-k][j-1]+cal(i-k+1, i));     
        }
    cout<<f[n][m]<<endl;
    return 0;
}