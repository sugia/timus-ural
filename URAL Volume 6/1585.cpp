//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int n, a(0), b(0), c(0);
string tmp, etc;

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>tmp>>etc;

		if(tmp[0]=='E')
			++a;
		else
			if(tmp[0]=='L')
				++b;
			else
				if(tmp[0]=='M')
					++c;
	}
	if(a>=b && a>=c)
		cout<<"Emperor Penguin"<<endl;
	else
		if(b>=a && b>=c)
			cout<<"Little Penguin"<<endl;
		else
			if(c>=a && c>=b)
				cout<<"Macaroni Penguin"<<endl;
	return 0;
}