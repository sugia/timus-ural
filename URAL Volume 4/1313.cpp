//#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
const int maxn=102;
int n, a[maxn][maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		cin>>a[i][j];

	cout<<a[1][1];
	int i, j;
	for(int k=2;k<=n;++k){
		i=k;
		j=1;
		for(int t=1;t<=k;++t){
			cout<<' '<<a[i][j];
			--i;
			++j;
		}
	}

	for(int k=2;k<=n;++k){
		i=n;
		j=k;
		for(int t=1;t<=n+1-k;++t){
			cout<<' '<<a[i][j];
			--i;
			++j;
		}
	}
	cout<<endl;
	return 0;
}