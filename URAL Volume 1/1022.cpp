//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 122
int n, tmp;
bool b[maxn][maxn], used[maxn], fe;
int chudu[maxn];

void writeln(int x)
{
	for(int i=1;i<=n;++i)
		if(!used[i] && b[i][x])
			writeln(i);

	if(!fe)
		printf(" ");
	fe=false;

	if(!used[x])
	{
		printf("%d", x);
		used[x]=true;
	}
}

int main()
{
	memset(b, false, sizeof(b));
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d", &tmp);
		while(tmp!=0)
		{
			b[i][tmp]=true;
			scanf("%d", &tmp);
		}
	}

	memset(used, false, sizeof(used));
	fe=true;

	memset(chudu, 0, sizeof(chudu));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(b[i][j])
				++chudu[i];


	for(int i=1;i<=n;++i)
		if(chudu[i]==0)
			writeln(i);

	printf("\n");
	return 0;
}