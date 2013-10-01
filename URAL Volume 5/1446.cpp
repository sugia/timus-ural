//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define maxn 1022
int n, id[maxn];
string str[maxn], name, tmp;

int main()
{
	scanf("%d\n", &n);
	for(int i=1;i<=n;++i)
	{
		getline(cin, name);
		getline(cin, tmp);

		//cout<<name<<endl;
		//cout<<tmp<<endl;
		str[i]=name;

		if(tmp=="Slytherin")
			id[i]=1;
		else
			if(tmp=="Hufflepuff")
				id[i]=2;
			else
				if(tmp=="Gryffindor")
					id[i]=3;
				else
					if(tmp=="Ravenclaw")
						id[i]=4;
	}

	printf("Slytherin:\n");
	for(int i=1;i<=n;++i)
		if(id[i]==1)
			cout<<str[i]<<endl;

	cout<<endl;

	printf("Hufflepuff:\n");
	for(int i=1;i<=n;++i)
		if(id[i]==2)
			cout<<str[i]<<endl;

	cout<<endl;

	printf("Gryffindor:\n");
	for(int i=1;i<=n;++i)
		if(id[i]==3)
			cout<<str[i]<<endl;

	cout<<endl;

	printf("Ravenclaw:\n");
	for(int i=1;i<=n;++i)
		if(id[i]==4)
			cout<<str[i]<<endl;

	return 0;
}