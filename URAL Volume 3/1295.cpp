//#include "stdafx.h"
#include <iostream>
using namespace std;
const int mo=10000;
int n, a[5], ans, t;
int main()
{
	cin>>n;
	ans=0;
	for(int i=1;i<=4;++i)
		a[i]=1;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=4;++j)
			a[j]=a[j]*j%mo;

	for(int i=1;i<=4;++i)
		ans+=a[i];
	
	t=0;
	while(ans%10==0)
	{
		++t;
		ans/=10;
	}

	cout<<t<<endl;
	return 0;
}