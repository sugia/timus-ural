//#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const int base[7]={4123, 2134, 1342, 1243, 2341, 1234, 1324};
char ch;
string s;
int x, n;
int b[12];

int main()
{
	cin>>n;
	for(int k=1;k<=n;++k)
	{
		memset(b, 0, sizeof(b));
		x=0;
		cin>>s;
		for(int i=0;i<s.size();++i)
			++b[int(s[i])-48];
		--b[1];
		--b[2];
		--b[3];
		--b[4];

		for(int i=1;i<=9;++i)
			for(int j=1;j<=b[i];++j)
				x = (x*10+i) % 7;

		x= x*10000 % 7;

		for(int i=1;i<=9;++i)
			for(int j=1;j<=b[i];++j)
				cout<<i;
		cout<<base[x];

		for(int i=1;i<=b[0];++i)
			cout<<0;
		cout<<endl;
	}

	return 0;
}