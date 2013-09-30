//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 262
char c[maxn], ch;
int top=0;
bool flag;

int main()
{
	while(scanf("%c", &ch)!=EOF)
	{
		flag=false;
		if(isalpha(ch))
			c[++top]=ch;
		else
		{
			for(int i=top;i>0;--i)
				printf("%c", c[i]);
			printf("%c", ch);
			top=0;
			flag=true;
		}
	}

	if(!flag)
	{
		for(int i=top;i>0;--i)
			printf("%c", c[i]);
	}

	return 0;
}