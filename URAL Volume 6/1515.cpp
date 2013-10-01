//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 122
int a[maxn], n;

int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;++i)
		scanf("%d", &a[i]);

	int ans=0;
	for(int i=0;i<n;++i)
		if(a[i]>ans+1)
		{
			printf("%d\n", ans+1);
			return 0;
		}
		else
			ans+=a[i];

	printf("%d\n", ans+1);
	return 0;
}