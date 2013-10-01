//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define maxn 322
int n, que[maxn], ans[maxn], top;
bool map[maxn][maxn]={0}, used[maxn]={0};
string name[maxn], tmpa, tmpb, tmpc;

template <class T>

void change(T &x, T &y)
{
	T tmp=x;
	x=y;
	y=tmp;
}

int prev(int y)
{
	++y;
	if(y>=maxn)
		y=0;

	return y;
}


int main()
{
	int a, b, c;
	top=0;
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
	{
		cin>>tmpa>>tmpb>>tmpc;
		for(a=1;a<=top;++a)
			if(name[a]==tmpa)
				break;
		if(a==top+1)
			name[++top]=tmpa;

		for(b=1;b<=top;++b)
			if(name[b]==tmpb)
				break;
		if(b==top+1)
			name[++top]=tmpb;

		for(c=1;c<=top;++c)
			if(name[c]==tmpc)
				break;
		if(c==top+1)
			name[++top]=tmpc;

		map[a][b]=true;
		map[a][c]=true;
		
		map[b][a]=true;
		map[b][c]=true;

		map[c][a]=true;
		map[c][b]=true;

	}

	int x, s, t;
	for(x=1;x<=top;++x)
		if(name[x]=="Isenbaev")
			break;

	que[1]=x;
	used[x]=true;
	ans[x]=0;
	t=1;
	s=0;

	while(prev(t)!=s)
	{
		s=prev(s);
		x=que[s];
		for(int i=1;i<=top;++i)
			if(!used[i] && map[x][i])
			{
				t=prev(t);
				que[t]=i;
				used[i]=true;
				ans[i]=ans[x]+1;
			}
	}

	for(int i=1;i<top;++i)
		for(int j=i+1;j<=top;++j)
			if(name[i]>name[j])
			{
				change(name[i], name[j]);
				change(ans[i], ans[j]);
				change(used[i], used[j]);
			}

	for(int i=1;i<=top;++i)
		if(used[i])
			cout<<name[i]<<' '<<ans[i]<<endl;
		else
			cout<<name[i]<<' '<<"undefined"<<endl;

	return 0;
}