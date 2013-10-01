//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int n;
long double tmp, sum(0);

int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lf", &tmp);
		sum+=tmp;
	}

	printf("%.6lf\n", sum/n);
	return 0;
}