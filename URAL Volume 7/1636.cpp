//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int t1, t2, sum(0), tmp;
int main()
{
	scanf("%d%d", &t1, &t2);
	for(int i=1;i<=10;++i)
	{
		scanf("%d", &tmp);
		sum+=tmp;
	}

	if(t1>t2-sum*20)
		printf("Dirty debug :(");
	else
		printf("No chance.");

	printf("\n");
	return 0;
}