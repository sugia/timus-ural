//#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const int maxn=122;
int len, que[maxn];
string str;

int main()
{
	cin>>str;
	len=str.length();
	for(int i=1;i<=len;++i)
		que[i]=str[i-1]-'a';

	que[0]=5;

	for(int i=len;i>=1;--i)
	{
		que[i]-=que[i-1];
		while(que[i]<0)
			que[i]+=26;
	}

	for(int i=1;i<=len;++i)
		printf("%c", que[i]+'a');
	cout<<endl;
	return 0;
}