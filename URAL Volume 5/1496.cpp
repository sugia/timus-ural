//#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
const int maxn=122;

int n, top;
string str[maxn], que[maxn];
bool b[maxn];

void qs(int s, int t)
{
	int i=s, j=t;
	string x=str[(s+t)/2], tmp;
	while(i<=j)
	{
		while(str[i]<x)
			++i;
		while(x<str[j])
			--j;
		if(i<=j)
		{
			tmp=str[i];
			str[i]=str[j];
			str[j]=tmp;
			++i;
			--j;
		}
	}
	if(i<t)
		qs(i, t);
	if(s<j)
		qs(s, j);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>str[i];

	qs(1, n);

	memset(b, false, sizeof(b));
	for(int i=1;i<n;++i)
		if(str[i]==str[i+1])
			b[i+1]=true;

	top=0;
	for(int i=1;i<=n;++i)
		if(b[i])
			que[++top]=str[i];

	memset(b, true, sizeof(b));

	for(int i=1;i<top;++i)
		if(que[i]==que[i+1])
			b[i+1]=false;

	for(int i=1;i<=top;++i)
		if(b[i])
			cout<<que[i]<<endl;

	return 0;
}