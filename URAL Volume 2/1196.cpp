//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 15022
long long a[maxn], n, m, tmp, ans(0);

void bs(int x)
{
	int s=1, t=n, mid;
	while(s<=t)
	{
		mid=(s+t)/2;
		if(x==a[mid])
		{
			++ans;
			return ;
		}
		if(x<a[mid])
			t=mid-1;
		else
			if(x>a[mid])
				s=mid+1;
	}
}

int main()
{
	scanf("%lld", &n);
	for(int i=1;i<=n;++i)
		scanf("%lld", &a[i]);
	
	scanf("%lld", &m);
	for(int i=1;i<=m;++i)
	{
		scanf("%lld", &tmp);
		bs(tmp);
	}

	printf("%lld\n", ans);
	return 0;
}