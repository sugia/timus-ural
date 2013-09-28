#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 100022
long long a[maxn], n, x;
double k[maxn], r;

int main()
{
	r=0;
	scanf("%lld", &n);
	scanf("%lld", &a[1]);
	for(int i=2;i<=n;++i)
	{
		scanf("%lld", &a[i]);
		k[i]=abs(a[i]-a[i-1]);
		if(k[i]>r)
		{
			r=k[i];
			x=i;
		}
	}

	printf("%lld %lld\n", x-1, x);
	return 0;
}