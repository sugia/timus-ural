//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define maxn 22
int n, ran[maxn];
string str[maxn][4], ans[maxn];
bool flag;

template <class T>

void swap(T &x, T &y)
{
	T tmp=x;
	x=y;
	y=tmp;
}

int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=3;++j)
			cin>>str[i][j];

		if(str[i][1]>str[i][2])
			swap(str[i][1], str[i][2]);

		if(str[i][1]>str[i][3])
			swap(str[i][1], str[i][3]);

		if(str[i][2]>str[i][3])
			swap(str[i][2], str[i][3]);
	}

	for(int i=1;i<=n;++i)
		scanf("%d", &ran[i]);

	//for(int i=1;i<=n;++i)
	//{
	//	for(int j=1;j<=3;++j)
	//		cout<<str[ran[i]][j]<<' ';
	//	cout<<endl;
	//}

	ans[0]="";
	flag=false;
	for(int i=1;i<=n;++i)
	{
		int j=1;
		while(j<=3 && str[ran[i]][j]<ans[i-1])
			++j;
		if(j>3)
		{
			//cout<<i<<' '<<ran[i]<<endl;
			printf("IMPOSSIBLE\n");
			return 0;
		}

		ans[i]=str[ran[i]][j];
	}

	for(int i=1;i<=n;++i)
		cout<<ans[i]<<endl;
	return 0;
}