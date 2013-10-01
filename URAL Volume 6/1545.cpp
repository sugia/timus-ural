//#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

#define maxn 1022
int n;
string str[maxn];
char ch;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>str[i];

	cin>>ch;


	for(int i=1;i<=n;++i)
		if(str[i][0]==ch)
			cout<<str[i]<<endl;;
	return 0;
}