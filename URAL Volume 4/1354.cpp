//#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define maxn 10022
string s, t;
int nextp[maxn];

void getnext()
{
	int j, k, m;
	m=t.length();
	j=0;
	k=-1;
	nextp[0]=-1;
	while(j<m)
	{
		if(k==-1 || t[j]==t[k])
		{
			++k;
			++j;
			nextp[j]=k;
		}
		else
			k=nextp[k];
	}
}

int find(int m)
{
	int n, i, j, ans=0;
	n=s.length();
	j=0;
	i=n-m-1;
	while(i<n && j<=m)
	{
		if(j==-1 || s[i]==t[j])
		{
			++i;
			++j;
		}
		else
			j=nextp[j];
	}
	if(j>m && i>=n)
		return 1;
	return 0;
}

int main()
{

	int i, j, len;
	while(cin>>s)
	{
		len=s.length();
		if(len==1)
		{
			cout<<s<<s<<endl;
			return 0;
		}
		t=s;
		reverse(t.begin(), t.end());
		getnext();
		for(i=len-2;i>=0;--i)
		{
			if(find(i))
				break;
		}

		cout<<s;
		for(int j=i+1;j<len;++j)
			cout<<t[j];
		cout<<endl;
	}
	return 0;
}