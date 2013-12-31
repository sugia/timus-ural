//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 60022
int f[maxn], n;
int main(){
	scanf("%d", &n);
	memset(f, 22, sizeof(f));
	f[0]=0;
	for(int i=1;i<=int(sqrt(double(n)));++i)
		for(int j=i*i;j<=n;++j)
			f[j]= f[j] < f[j-i*i]+1 ? f[j] : f[j-i*i]+1;

	printf("%d\n", f[n]);
	return 0;
}
