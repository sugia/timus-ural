//#include "stdafx.h"
#include <stdio.h>

const int maxx=32022;
const int maxn=15022;
int c[maxx]={0}, sum[maxn]={0};
int n;

int lowbit(int x)
{
	return x&(-x);
}

void inc(int x)
{
	while(x<maxx)
	{
		++c[x];
		x+=lowbit(x);
	}
}

int s(int x)
{
	int ans=0;
	while(x>=1)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

int main()
{
	int x, y;
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d", &x, &y);
		++x;
		++y;
		++sum[s(x)];
		inc(x);
	}
	for(int i=0;i<n;++i)
		printf("%d\n", sum[i]);
	return 0;
}