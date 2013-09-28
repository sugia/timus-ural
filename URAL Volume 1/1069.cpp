//#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using std::sort;
using std::set;
const int maxn=7510;
int n=1,t,tot=0,a[maxn],e[maxn]={0},out[maxn];
int h[maxn]={0},node[maxn<<1],next[maxn<<1];
set<int> x;
void add(int a,int b)
{
    node[++tot]=b;
    next[tot]=h[a];
    h[a]=tot;
}
int main()
{
    int i,j;
    while (scanf("%d",&a[n++]) != EOF);
    --n;
    for (i=1;i<n;++i)  ++e[a[i]];
    for (i=1;i<=n;++i)
        if (!e[i])
            x.insert(i);
    for (i=1;i<n;++i)
    {
        t=*x.begin();
        x.erase(t);
        add(t,a[i]);
        add(a[i],t);
        if (!(--e[a[i]]))  x.insert(a[i]);
    }
    for (i=1;i<=n;++i)
    {
        printf("%d:",i);
        for (tot=0,j=h[i];j;j=next[j])
            out[tot++]=node[j];
        sort(out,out+tot);
        for (j=0;j<tot;++j)  printf(" %d",out[j]);
        printf("\n");
    }
    return 0;
}