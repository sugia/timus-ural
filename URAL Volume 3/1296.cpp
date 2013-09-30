//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans=0, tmp=0, x;
	for(int i=0;i<n;++i)
	{
		scanf("%d", &x);
		tmp+=x;
		if(tmp<0)
			tmp=0;
		if(ans<tmp)
			ans=tmp;
	}

	printf("%d\n", ans);
	return 0;
}