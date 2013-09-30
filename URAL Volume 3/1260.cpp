//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 56
int n, f[maxn]={0};
int main()
{
	scanf("%d", &n);
	f[1]=1;
	f[2]=1;
	f[3]=2;
	for(int i=4;i<=n;++i)
		f[i]=f[i-1]+f[i-3]+1;
	printf("%d\n", f[n]);
	return 0;
}