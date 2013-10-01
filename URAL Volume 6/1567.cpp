//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int ans=0;
char ch;
int main()
{
	while(scanf("%c", &ch)!=EOF)
	{
		if(ch=='a' || ch=='d' || ch =='g' || ch=='j' || ch=='m' || ch=='p'
			|| ch=='s' || ch=='v' || ch=='y' || ch=='.' || ch==' ')
			++ans;
		else
			if(ch=='b' || ch=='e' || ch =='h' || ch=='k' || ch=='n' || ch=='q'
				|| ch=='t' || ch=='w' || ch=='z' || ch==',')
				ans+=2;
			else
				if(ch=='c' || ch=='f' || ch =='i' || ch=='l' || ch=='o' || ch=='r'
					|| ch=='u' || ch=='x' || ch=='!')
					ans+=3;

	}

	printf("%d\n", ans);
	return 0;
}