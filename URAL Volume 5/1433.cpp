//#include "stdafx.h"
#include <iostream>
using namespace std;



int main()
{
	char a, b, c, d;
	scanf("%c%c%c%c", &a, &b, &c, &d);
	char ch;
	scanf("%c", &ch);
	char w, x, y, z;
	scanf("%c%c%c%c", &w, &x, &y, &z);

	bool flag=false;
	if(a==w)
	{
		if(b==x && c==y && d==z)
			flag=true;
		if(c==x && d==y && b==z)
			flag=true;
		if(d==x && b==y && c==z)
			flag=true;
	}

	if(b==w)
	{
		if(a==x && d==y && c==z)
			flag=true;
		if(d==x && c==y && a==z)
			flag=true;
		if(c==x && a==y && d==z)
			flag=true;
	}

	if(c==w)
	{
		if(b==x && d==y && a==z)
			flag=true;
		if(d==x && a==y && b==z)
			flag=true;
		if(a==x && b==y && d==z)
			flag=true;
	}

	if(d==w)
	{
		if(c==x && b==y && a==z)
			flag=true;
		if(b==x && a==y && c==z)
			flag=true;
		if(a==x && c==y && b==z)
			flag=true;
	}
	if(flag)
		printf("equal\n");
	else
		printf("different\n");
	return 0;
}