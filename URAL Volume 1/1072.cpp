//#include "stdafx.h"
#include<cstdio>
 
unsigned int o[91][6];
int map[91][91];
int  f[91]={0};
bool use[91]={0};
int pre[91]={0};
 
void init(int w,int r)
{
    unsigned tmp=0,x1=0,x2=0;
    char ch;
    for(int i=0;i<4;i++)
    {
        scanf("%u%c",&tmp,&ch);
        x1=x1<<8;
        x1+=tmp;
    }
    for(int i=0;i<4;i++)
    {
        scanf("%u%c",&tmp,&ch);
        x2=x2<<8;
        x2+=tmp;
    }
    o[w][r]=(x1&x2);
}
 
int main()
{
    int n,s,t;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        o[i][0]=k;
        for(;k>0;k--)
            init(i,k);
    }
    scanf("%d %d",&s,&t);
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) 
            if(i!=j)
            {
                for(int k=1;k<=o[i][0];k++)
                    for(int l=1;l<=o[j][0];l++)
                        if(o[i][k]==o[j][l])
                        {
                            map[i][j]=1;
                            break;
                        }
                if(map[i][j]!=1)
                    map[i][j]=100;
            }
            else
                map[i][j]=100;
    for(int i=1;i<=n;i++)
    {
        f[i]=map[s][i];
        if(f[i]!=100)
            pre[i]=s;
    }
    f[s]=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=100,u=s;
        for(int j=1;j<=n;j++)
            if((!use[j])&&(tmp>f[j]))
            {
                tmp=f[j];
                u=j;
            }
        use[u]=true;
        for(int j=1;j<=n;j++)
            if((!use[j]))
                if(f[j]>map[u][j]+f[u])
                {
                    f[j]=map[u][j]+f[u];
                    pre[j]=u;
                }
    }        
    if(use[t])
    {
        printf("Yes\n");
        int ans[91];
        ans[0]=1;
        ans[1]=t;
        while(t!=0)
        {
           ans[0]+=1;
           ans[ans[0]]=pre[t];
           t=pre[t];
        }
        ans[0]-=1;
        for(int i=ans[0];i>1;i--)
            printf("%d ",ans[i]);
        printf("%d",ans[1]);
    }
    else
        printf("No");
     return 0;
}