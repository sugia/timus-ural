//#include "stdafx.h"
#include<iostream>
#define maxn 500
#define maxq 10000
#define mx 1000000
using namespace std;
long c[maxn][maxn]={0},g[maxn][maxn]={0},d[maxn]={0};
int q[maxq]={0},pre[maxn]={0};
bool vis[maxn]={0};
bool b=1;
long n,s=1,t;
long p=0;
void augment(){
    int i=t;
    long a=mx;
    while (i>s){
        if (c[pre[i]][i]<a) a=c[pre[i]][i];
        i=pre[i];
    }
    i=t;
    while (i>s){
        c[pre[i]][i]-=a;
        c[i][pre[i]]+=a;
        i=pre[i];
    }
}
void SPFA(){
    memset(q,0,sizeof(q));
    memset(vis,0,sizeof(vis));
    memset(pre,0,sizeof(pre));
    int l=1,r=1;
    for (int i=1;i<=t;++i) d[i]=mx;
    d[s]=0;
    q[1]=s;
    vis[s]=1;
    while (l<=r){
        if (l==1 && r==maxq) break;
        long x=q[l];
        for (int i=1;i<=t;++i)
        if (d[x]+g[x][i]<d[i] && c[x][i]>0){
            d[i]=d[x]+g[x][i];
            pre[i]=x;
            if (!vis[i]){vis[i]=1;++r;if (r>maxq) r=1;q[r]=i;}
        }
        vis[x]=0;
        ++l;if (l>maxq) l=1;
    }
    if (d[t]!=mx) {p+=d[t];augment();b=1;return;}
    b=0;
}
int main(){
    cin>>n;
    t=2*n+2;
    for (int i=1;i<=n;++i){
        int s=0;
        for (int j=1;j<=n;++j){
            c[1+i][1+n+j]=1;
            cin>>g[1+i][1+n+j];
            s+=g[1+i][1+n+j];
        }
        for (int j=1;j<=n;++j){
            g[1+i][1+n+j]=s-g[1+i][1+n+j];
            g[1+n+j][1+i]=-g[1+i][1+n+j];
        }
    }
    for (int i=1;i<=n;++i){
        c[1][1+i]=1;
        c[1+n+i][t]=1;
    }
    b=1;
    while (b) SPFA();
    cout<<p<<"\n";
    return 0;
}
