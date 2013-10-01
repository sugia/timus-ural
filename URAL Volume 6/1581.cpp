//#include "stdafx.h"
#include <iostream>
using namespace std;
const int maxn=1022;
int a[maxn], c[maxn], top, n, tmp;
int main()
{
	cin>>n;
	cin>>a[1];
	top=1;
	c[1]=1;
	for(int i=2;i<=n;++i)
	{
		cin>>tmp;
		if(tmp==a[top])
			++c[top];
		else
		{
			a[++top]=tmp;
			c[top]=1;
		}
	}

	cout<<c[1]<<' '<<a[1];
	for(int i=2;i<=top;++i)
		cout<<' '<<c[i]<<' '<<a[i];
	cout<<endl;
	return 0;
}