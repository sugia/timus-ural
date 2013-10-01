//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define maxn 3
int que[maxn], k, ans, color[maxn]={0}, tmp[maxn];
string str;

int main()
{
	for(int i=0;i<maxn;++i)
		scanf("%d", &que[i]);
	scanf("%d", &k);
	for(int i=0;i<k;++i)
	{
		cin>>str;
		if(str[0]=='B')
			++color[0];
		else
			if(str[0]=='R')
				++color[1];
			else
				++color[2];
	}

	for(int i=0;i<maxn;++i)
		if(color[i]!=0)
			tmp[i]=que[i]/color[i];
		else
			tmp[i]=1;

	ans=1;
	for(int i=0;i<maxn;++i)
		ans*=tmp[i];

	printf("%d\n", ans);
	return 0;
}