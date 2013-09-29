//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 222
int n, m;
int a[maxn], f[maxn], level[maxn], list[maxn];
int d[22][maxn];
bool flag=false;

void init()
{
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;++i)
		scanf("%d", &a[i]);
	for(int i=1;i<=m;++i)
		scanf("%d", &f[i]);
}

void qs(int s, int t)
{
	if(t-s<=20)
	{
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				if(a[i]>a[j])
				{
					int tmp=a[i];
					a[i]=a[j];
					a[j]=tmp;
				}
	}
	else
	{
		int i=s, j=t, x=a[(s+t)/2], tmp;
		while(i<=j)
		{
			while(a[i]<x)
				++i;
			while(x<a[j])
				--j;
			if(i<=j)
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;

				++i;
				--j;
			}
		}

		if(i<t)
			qs(i, t);
		if(s<j)
			qs(s, j);
	}
}

void writeln()
{
	for(int i=1;i<=n;++i)
	{
		int j=level[i];
		++list[j];
		d[j][list[j]]=i;
	}

	for(int i=1;i<=m;++i)
	{
		printf("%d\n", list[i]);

		for(int j=1;j<list[i];++j)
			printf("%d ", a[d[i][j]]);
		printf("%d\n", a[d[i][list[i]]]);
	}

	flag=true;
}

void dfs(int dep)
{
	if(dep>m)
		writeln();
	if(flag)
		return ;

	for(int i=n;i>=1;--i)
		if(level[i]==0 && a[i]<=f[dep])
		{
			level[i]=dep;
			f[dep]-=a[i];
			if(f[dep]==0)
				dfs(dep+1);
			else
			dfs(dep);

			if(flag)
				return ;
			level[i]=0;
			f[dep]=f[dep]+a[i];
		}
}

int main()
{
	memset(level, 0, sizeof(level));
	memset(list, 0, sizeof(list));
	init();
	qs(1, n);
	//for(int i=1;i<=n;++i)
	//	cout<<a[i]<<' ';
	//cout<<endl;

	dfs(1);
	return 0;
}