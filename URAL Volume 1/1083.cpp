//#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int n, k;
string str;
int main()
{
	cin>>n;
	cin>>str;
	k=0;
	for(int i=0;i<str.length(); ++i)
		if(str[i]=='!')
			++k;
	unsigned long long ans=1;
	while(n>0){
		ans*=n;
		n-=k;
	}

	cout<<ans<<endl;
	return 0;
}