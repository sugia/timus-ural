//#include "stdafx.h"
#include <iostream>
using namespace std;

int a, b, ans;
int main()
{
	cin>>a>>b;
	ans=0;
	for(int i=a;i<=b;++i)
		if(i%2==1)
			++ans;

	cout<<ans<<endl;
	return 0;
}