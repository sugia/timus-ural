//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	long n, m, k, s;
	cin>>n>>m;
	--n;
	--m;
	s=n+m;
	while(m!=0)
	{
		k=n%m;
		n=m;
		m=k;
	}
	cout<<s-n<<endl;
	return 0;
}