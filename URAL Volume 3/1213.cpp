//#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#define maxn 32
char name[maxn][maxn];
int ans=-1;

void ins(char *s)
{
	int i;
	for(i=0;i<=ans;++i)
		if(strcmp(name[i], s)==0)
			return ;

	strcpy(name[++ans], s);
}

int main()
{
	char s[maxn], s1[maxn], s2[maxn];
	gets(s);
	ins(s);
	scanf("%s", s);
	int i, j;
	while(strcmp(s, "#")!=0)
	{
		for(i=0;s[i]!='-';++i)
			s1[i]=s[i];
		s1[i]='\0';
		++i;
		j=i;
		for(;s[i]!='\0';++i)
			s2[i-j]=s[i];
		s2[i-j]='\0';
		ins(s1);
		ins(s2);
		scanf("%s", s);
	}
	printf("%d\n", ans);
	return 0;
}