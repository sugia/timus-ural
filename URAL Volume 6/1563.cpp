//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

#define maxn 1022
int n;
string brand[maxn]={""};
int main()
{
	scanf("%d\n", &n);

	for(int i=0;i<n;++i)
		getline(cin, brand[i]);
	sort(brand, brand+n);

	int sum=0;
	for(int i=1;i<n;++i)
		if(brand[i]==brand[i-1])
			++sum;

	printf("%d\n", sum);

//	for(int i=1;i<=n;++i)
//		cout<<brand[i]<<endl;

	return 0;
}