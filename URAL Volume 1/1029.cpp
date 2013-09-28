//#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

const int maxn=122;
const int maxm=522;
const int maxlist=100022;
int d[maxn][maxm], map[maxn][maxm], n, m, a[maxlist], b[maxlist], mini;

void search(int x, int y, int sum)
{
	if(mini<sum)
		return ;
	if(d[x][y]<=sum)
		return ;
	else
		d[x][y]=sum;

	if(x==n)
	{
		if(sum<mini)
			mini=sum;
		for(int i=1;i<=a[0];++i)
			b[i]=a[i];
		b[0]=a[0];
		return ;
	}

	if(x<n && sum+map[x+1][y]<mini)
	{
		++a[0];
		a[a[0]]=y;
		search(x+1, y, sum+map[x+1][y]);
		--a[0];
	}
	if(y<m && sum+map[x][y+1]<mini)
	{
		++a[0];
		a[a[0]]=y+1;
		search(x, y+1, sum+map[x][y+1]);
		--a[0];
	}
	if(y>1 && sum+map[x][y-1]<mini)
	{
		++a[0];
		a[a[0]]=y-1;
		search(x, y-1, sum+map[x][y-1]);
		--a[0];
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d", &map[i][j]);
	memset(d, 62, sizeof(d));
	mini=d[0][0];
	memset(a, 0, sizeof(a));
	for(int i=1;i<=m;++i)
		if(map[1][i]<mini)
		{
			++a[0];
			a[a[0]]=i;
			search(1, i, map[1][i]);
			--a[0];
		}

	for(int i=1;i<b[0];++i)
		printf("%d ", b[i]);
	printf("%d\n", b[b[0]]);
	return 0;
}