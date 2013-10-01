//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int n, m;
int main()
{
	cin>>n>>m;
	cout<<1;
	for(int i=2;i<=n;++i)
		cout<<' '<<i;
	cout<<endl;

	cout<<n+1;
	for(int i=2;i<=m;++i)
		cout<<' '<<i*n+1;
	cout<<endl;

	return 0;
}