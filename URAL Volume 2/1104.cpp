//#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#define maxn 1000022
char s[maxn];

int main()
{
	int ans, len;
	char c='/';
	scanf("%s", s);
	ans=0;
	len=strlen(s);
	for(int i=0;i<len;++i)
	{
		if(s[i]>c)
			c=s[i];
		if('0'<=s[i] && s[i]<='9')
			ans+=s[i]-'0';
		else
			ans+=s[i]-'A'+10;
	}

	int i;
	if(c<='9')
		i=c-'0';
	else
		i=c-'A'+10;
	++i;
	if(i<2)
		i=2;
	for(;i<=36;++i)
		if(ans%(i-1)==0)
			break;
	if(i>36)
		printf("No solution.\n");
	else
		printf("%d\n", i);
	return 0;
}