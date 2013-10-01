//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int n, k;
int main()
{
	scanf("%d%d", &n, &k);
	if(k>n/2)
		k=n-k+1;

	if(n-k-2<0)
		printf("0\n");
	else
		printf("%d\n", n-k-2);
	return 0;
}