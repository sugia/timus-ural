//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int a, b, c, d;
bool flag=true;
int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if(a>=c)
	{
		printf("%d\n", a);
		return 0;
	}

	while(a<c && a+b<=c)
	{
		a+=b;
		flag=false;
		if(a<=c-d)
		{
			c-=d;
			flag=true;
		}
		if(!flag)
			break;
	}

	if(flag)
		printf("%d\n", c);
	else
		printf("%d\n", a);
	return 0;
}