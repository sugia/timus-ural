//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	if(m*n%2==0)
		printf("[:=[first]");
	else
		printf("[second]=:]");

	printf("\n");
	return 0;
}