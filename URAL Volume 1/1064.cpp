//#include "stdafx.h"
#include <iostream>
using namespace std;

const int maxn=10000;
int first[maxn+22], last[maxn+22];
bool b[maxn]={0};

int main()
{
	int n, l;
	scanf("%d%d", &n, &l);
	int lef, rig, x, t;
	for(int i=1;i<=maxn;++i)
	{
		t=0;
		lef=0;
		rig=i-1;

		while(lef<=rig)
		{
			x=(lef+rig)/2;
			++t;
			if(t>l)
				break;
			if(x==n && t==l)
				b[i]=true;
			if(x>n)
				rig=x-1;
			else
				lef=x+1;
		}

	}

	int k=0;
	for(int i=1;i<=maxn;++i)
	{
		if(b[i] && !b[i-1])
		{
			++k;
			first[k]=i;
			last[k]=i;
		}
		if(b[i] && b[i-1])
			last[k]=i;
	}

	printf("%d\n", k);
	for(int i=1;i<=k;++i)
		printf("%d %d\n", first[i], last[i]);

	return 0;
}