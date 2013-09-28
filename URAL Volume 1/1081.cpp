//#include "stdafx.h"
#include <cstdio>
 
const int oo=50;
 
int a[oo],n,k,f[oo][2];
bool tt;
 
void dfs(int L,int s){
	if (L==0 || s==0)	return;
	if (s<=f[L][0])	dfs(L-1,s);
	else	a[L]=1,dfs(L-1,s-f[L][0]);
}
 
int main()
{ 

	scanf("%d%d",&n,&k);
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		f[i][0]=f[i-1][0]+f[i-1][1];
		f[i][1]=f[i-1][0];
		if (k<=f[i][0]+f[i][1]){
			tt=true;
			dfs(i,k);
			break;
		}
	}
 
	if (!tt)	printf("-1");
	else
	for (int i=n;i;i--)
		printf("%d",a[i]);
 
	printf("\n");
 
	return 0;
}