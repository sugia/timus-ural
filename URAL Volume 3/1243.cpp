//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define maxn 222
string str;
int a[maxn], len;

int main()
{
	cin>>str;
	a[0]=0;
	len=str.length();
	for(int i=0;i<len;++i)
		a[i]=int(str[i]-'0');

	//for(int i=1;i<=len;++i)
	//	cout<<a[i];
	//cout<<endl;

	for(int i=0;i<len;++i)
	{
		a[i]-=(a[i]/7)*7;
		a[i+1]+=a[i]*10;
	}

	cout<<a[len-1]<<endl;
	return 0;
}