//#include "stdafx.h"
#include <iostream>
using namespace std;

const int maxn=122;

int ran[maxn], size[maxn], x[maxn], y[maxn];
int l, a, m, w;

bool yes()
{
	int p, q;
	bool flag;
	for(int i=0;i<=m;++i)
		if(ran[i]>w)
			for(int j=0;j<=m;++j)
				if(ran[j]>w)
				{
					p=x[i]+size[i];
					if(p+a>l)
						continue;

					q=y[j]+size[j];
					if(q+a>l)
						continue;

					flag=true;
					for(int k=1;k<=m;++k)
						if(ran[k]>w && p<x[k]+size[k] && x[k]<=p+a && q<y[k]+size[k] && y[k]<=q+a)
						{
							flag=false;
							break;
						}
					if(flag)
						return flag;
				}
	return flag;
}

int main()
{
	scanf("%d%d", &l, &a);
	scanf("%d", &m);

	--a;
	for(int i=1;i<=m;++i)
		scanf("%d%d%d%d", &ran[i], &size[i], &x[i], &y[i]);

	ran[0]=255;
	size[0]=1;
	x[0]=0;
	y[0]=0;
	int u=1, v=101;

	while(u!=v)
	{
		w=(u+v)/2;
		if(yes())
			v=w;
		else
			u=w+1;
	}

	if(u>100)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", u);
	return 0;
}