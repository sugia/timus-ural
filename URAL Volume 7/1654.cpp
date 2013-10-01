//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 200022
int n;
char ch, str[maxn]={' '};

int main()
{
	n=0;
	while(cin>>ch)
	{
		str[++n]=ch;
		if(str[n]==str[n-1])
			n-=2;
	}
	
	for(int i=1;i<=n;++i)
		printf("%c", str[i]);
	printf("\n");
	return 0;
	
}