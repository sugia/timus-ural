//#include "stdafx.h"
#include <iostream>
using namespace std;

long long sqr(long long x)
{
	return x*x;
}

int main()
{
	long long r, x, y, ans=0;
	scanf("%lld", &r);
	x=r;
	for(y=1;y<=r;++y)
	{
		while(sqr(x-1) + sqr(y-1) >= sqr(r))
			--x;
		ans+=x;
	}

	printf("%lld\n", ans*4);
	return 0;
}