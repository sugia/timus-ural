//#include "stdafx.h"
#include <iostream>
using namespace std;

long n, k, ex, ans;
int main()
{
	scanf("%ld%ld", &n, &k);
	if(n==1)
	{
		printf("%d\n", 0);
		return 0;
	}
	if(n==2)
	{
		printf("%d\n", 1);
		return 0;
	}

	ans=1;
	ex=1;
	n-=2;

	while(n>0 && ex*2<k)
	{
		ex*=2;
		n-=ex;
		++ans;
	}

	if(n>0)
	{
		if(n%k==0)
			ans+=n/k;
		else
			ans+=n/k+1;
	}

	printf("%d\n", ans);
	return 0;
}