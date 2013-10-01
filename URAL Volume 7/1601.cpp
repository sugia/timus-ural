//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

char ch;
bool fe=true;
int main()
{
	while(scanf("%c", &ch)!=EOF)
	{
		if(ch=='\n')
		{
			printf("\n");
			scanf("%c", &ch);
		}
		if(fe && ch>='A' && ch<='Z')
		{
			printf("%c", ch);
			fe=false;
//			cout<<"change1"<<endl;
		}
		else
			printf("%c", tolower(ch));
		
		if(ch=='.' || ch=='!' || ch=='?')
		{
			fe=true;
//			cout<<"change2"<<endl;
		}
	}
	return 0;
}