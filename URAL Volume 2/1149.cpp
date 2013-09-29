//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

long n;

void a(long x)
{
	for(int i=1;i<=x;++i)
	{
		printf("sin(%d", i);
		if(i!=x)
		{
			if(i%2==0)
				printf("+");
			else
				printf("-");
		}
	}
	for(int i=1;i<=x;++i)
		printf(")");
}

void s(long x)
{
	for(int i=1;i<x;++i)
		printf("(");
	for(int i=1;i<=x;++i)
	{
		a(i);
		printf("+%d", n-i+1);
		if(i!=n)
			printf(")");
	}
}

int main()
{
	scanf("%d", &n);
	s(n);
	printf("\n");
	return 0;
}