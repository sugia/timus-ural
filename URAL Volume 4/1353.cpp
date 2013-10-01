//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 82
long a[maxn];

int main()
{
	a[0]=1;
	for(int i=1;i<=9;++i)
		for(int j=9*i;j>=1;--j)
			for(int k=1;k<=9;++k)
			{
				if(k>j)
					break;
				a[j]+=a[j-k];
			}
	++a[1];
	int n;
	scanf("%ld", &n);
	printf("%ld\n", a[n]);
	return 0;
}