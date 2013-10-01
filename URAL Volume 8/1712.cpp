//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 5
char ch, map[maxn][maxn];
bool b[maxn][maxn]={false};

void write()
{
	for(int i=1;i<maxn;++i)
		for(int j=1;j<maxn;++j)
			if(b[i][j])
				printf("%c", map[i][j]);
}

void rotate()
{
	bool c[maxn][maxn];
	for(int i=1;i<maxn;++i)
		for(int j=1;j<maxn;++j)
			c[i][j]=b[maxn-j][i];

	for(int i=1;i<maxn;++i)
		for(int j=1;j<maxn;++j)
			b[i][j]=c[i][j];
}

int main()
{
	for(int i=1;i<maxn;++i)
		for(int j=1;j<maxn;++j)
		{
			cin>>ch;
			if(ch=='X')
				b[i][j]=true;
		}

	for(int i=1;i<maxn;++i)
		for(int j=1;j<maxn;++j)
			cin>>map[i][j];

	write();
	rotate();
	write();
	rotate();
	write();
	rotate();
	write();
	printf("\n");
	return 0;
}