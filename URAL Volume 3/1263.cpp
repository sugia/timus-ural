//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=10022;
int n, m, a[maxn], tmp;
double pc[maxn];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>tmp;
		++a[tmp];
	}

	for(int i=1;i<=n;++i)
		pc[i]=(double)a[i]/m*100;

	for(int i=1;i<=n;++i)
	{
		printf("%.2lf", pc[i]);
		cout<<"%\n";
	}

	return 0;
}