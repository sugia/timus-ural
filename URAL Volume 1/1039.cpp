//#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
const int maxn=6000+2; const int maxint=2100000000;
int F[maxn][2]; int value[maxn];
int n,root; int brother[maxn]={0},son[maxn]={0},fa[maxn]={0};
void Init()
{
     memset(F,255,sizeof(F));
     scanf("%d",&n); int i; for (i=1;i<=n;i++) scanf("%d",&value[i]);
     int a,b;
     while (1)
     {
        scanf("%d%d",&a,&b); if (a==0) break;
        fa[a]=b; brother[a]=son[b]; son[b]=a;
     }
     root=n+1; 
     for (i=1;i<=n;i++) if (fa[i]==0) {fa[i]=root; brother[i]=son[root]; son[root]=i;}
}
 
int Mdfs(int k,int flag)
{
    if (F[k][flag]!=-1) return F[k][flag];
    if (k==0) {F[k][flag]=0; return 0;}
    if (flag) F[k][flag]=Mdfs(son[k],0)+Mdfs(brother[k],1);
    else F[k][flag]=max(Mdfs(son[k],1)+value[k],Mdfs(son[k],0))+Mdfs(brother[k],0);
    return F[k][flag];
}
 
int main()
{
    Init();
    Mdfs(root,1);
    printf("%d",F[root][1]);
    return 0;
}