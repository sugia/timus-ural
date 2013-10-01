//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string str;
int n, step, hungry=0, satisfied=10;
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;++i)
	{
		cin>>step>>str;
		if(str=="hungry")
			hungry= hungry > step? hungry : step;
		else
			satisfied= satisfied < step? satisfied : step;

	}
	
	if(hungry>=satisfied)
	{
		printf("Inconsistent\n");
		return 0;
	}

	printf("%d\n", satisfied);
	return 0;
}