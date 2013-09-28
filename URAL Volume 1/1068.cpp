//#include "stdafx.h"
#include <iostream>
using namespace std;
int ans, n;
int main()
{
	cin>>n;
	ans=0;
	if(n>=1)
		for(int i=1;i<=n;++i)
			ans+=i;
	else
		for(int i=1;i>=n;--i)
			ans+=i;
	cout<<ans<<endl;
	return 0;
}