//#include "stdafx.h"
#include <cstdio>
#include <cstring>
 
const int oo=301*201,maxn=202;
 
int n,m,x,y,e[oo],next[oo],lis[maxn],tot,stack[maxn],l,level[maxn],p;
bool mk[maxn];
 
inline void Add(int x,int y)
{	e[++l]=y;next[l]=lis[x];lis[x]=l;	}
 
void Dfs(int u){
	mk[u]=1;
	int v;
	for (int i=lis[u];i;i=next[i]){
		v=e[i];
		if (!mk[v])	Dfs(v);
	}
}
 
void dfs(int u){
	stack[++tot]=u;level[u]=tot;mk[u]=1;
	int v;
	for (int i=lis[u];i;i=next[i]){
		v=e[i];
		if (!mk[v])	dfs(v);
		else{
			if (level[u]-level[v]>1){
				printf("%d",level[u]-level[v]+1);
				for (int j=level[v];j<=level[u];j++)
					printf(" %d",stack[j]);
				printf("\n");
			}
		}
	}
	tot--;
}
 
int main(){
	//freopen("s.in","r",stdin);
	//freopen("s.out","w",stdout);
 
	scanf("%d%d",&n,&m);
 
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		Add(x,y),Add(y,x);
	}
 
 
	for (int i=1;i<=n;i++)
	if (!mk[i])
		p++,Dfs(i);
 
	printf("%d\n",m-n+p);
	memset(mk,0,sizeof(mk));
 
	for (int i=1;i<=n;i++)
	if (!mk[i])
		dfs(i);
 
	return 0;
}