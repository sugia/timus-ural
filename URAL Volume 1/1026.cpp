//#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int maxn=100022;

int a[maxn], n, num;
string str;

void qs(int s, int t)
{
	int i=s, j=t, x=a[(s+t)/2], tmp;
	while(i<=j)
	{
		while(a[i]<x)
			++i;
		while(x<a[j])
			--j;
		if(i<=j)
		{
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
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
		cin>>a[i];
	
	qs(1, n);
	cin>>str;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>num;
		cout<<a[num]<<endl;
	}

	return 0;
}