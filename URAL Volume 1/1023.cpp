//#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;
int n;
bool flag;

int main()
{
	cin>>n;
	flag=false;

	for(int i=3;i<=sqrt((double)n);++i)
		if(n%i==0)
		{
			cout<<i-1<<endl;
			flag=true;
			return 0;
		}

	if(!flag)
	{
		while(n%2==0 && n>4)
			n/=2;

		cout<<n-1<<endl;
	}

	return 0;
}