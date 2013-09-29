//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 10022
int x[maxn], y[maxn], id[maxn];

void qs(int s, int t)
{
	int tmp;
	if(t-s<=20)
	{
		for(int i=s;i<t;++i)
			for(int j=i+1;j<=t;++j)
				if(x[i]>x[j])
				{
					tmp=x[i];
					x[i]=x[j];
					x[j]=tmp;

					tmp=y[i];
					y[i]=y[j];
					y[j]=tmp;

					tmp=id[i];
					id[i]=id[j];
					id[j]=tmp;

				}
		return ;
	}

	int i=s, j=t, h=x[(s+t)/2];
	while(i<=j)
	{
		while(x[i]<h)
			++i;
		while(h<x[j])
			--j;
		if(i<=j)
		{
			tmp=x[i];
			x[i]=x[j];
			x[j]=tmp;

			tmp=y[i];
			y[i]=y[j];
			y[j]=tmp;

			tmp=id[i];
			id[i]=id[j];
			id[j]=tmp;

			++i;
			--j;
		}
	}
	if(i<t)
		qs(i, t);
	if(s<j)
		qs(s, j);
}


int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d", &x[i], &y[i]);
		id[i]=i;
	}

	qs(1, n);
	for(int i=1;i<n;i+=2)
		printf("%d %d\n",id[i], id[i+1]);
	return 0;
}