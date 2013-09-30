//#include "stdafx.h"
#include <iostream>
using namespace std;

const int maxn=25022;
int que[maxn], n;

void qs(int s, int t)
{
	int i=s, j=t, x=que[(s+t)/2], tmp;
	while(i<=j)
	{
		while(que[i]<x)
			++i;
		while(x<que[j])
			--j;
		if(i<=j)
		{
			tmp=que[i];
			que[i]=que[j];
			que[j]=tmp;
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
		cin>>que[i];
	qs(1, n);

	for(int i=n;i>=1;--i)
		cout<<que[i]<<endl;
	return 0;
}