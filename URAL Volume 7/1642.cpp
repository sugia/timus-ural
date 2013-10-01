//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 1022
int n, x, lef, rig, tmp;
int main()
{
	scanf("%d%d", &n, &x);
	lef=-maxn;
	rig=maxn;

	for(int i=0;i<n;++i)
	{
		scanf("%d", &tmp);
		if(tmp<0 && tmp>lef)
			lef=tmp;
		else
			if(tmp>0 && tmp<rig)
				rig=tmp;
	}

	if(x<lef || x>rig)
		printf("Impossible\n");
	else
	{
		if(x<0)
			printf("%d %d\n", rig*2-x, -x);
		else
			printf("%d %d\n", x, (-lef)*2+x);
	}
	return 0;
}