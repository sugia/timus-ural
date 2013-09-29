//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int maxn=2022;
int len, j;
string str;
char ch[maxn];
int main()
{
	cin>>str;
	for(int i=0;i<str.length();++i)
		ch[i+1]=str[i];
	len=str.length();

	for(int i=1;i<=len/2;++i)
		if(ch[i]>ch[len-i+1])
			ch[len-i+1]=ch[i];
		else
			if(ch[i]<ch[len-i+1])
			{
				ch[len-i+1]=ch[i];
				ch[len-i]=(char)((int)ch[len-i]+1);
				
				j=len-i;
				while(ch[j]>'9')
				{
					ch[j]='0';
					ch[j-1]=(char)((int)(ch[j-1]+1));
					--j;
				}
				--i;
			}

	for(int i=1;i<=len;++i)
		cout<<ch[i];
	cout<<endl;
	return 0;
}