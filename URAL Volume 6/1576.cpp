//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 1022
int n1, c1, n2, t, c2, n3, mm, ss, k, a, b, c, sum;

int main()
{
	scanf("%d%d", &n1, &c1);
	scanf("%d%d%d", &n2, &t, &c2);
	scanf("%d", &n3);
	scanf("%d", &k);
	sum=0;
	for(int i=1;i<=k;++i)
	{
		scanf("%d:%d", &mm, &ss);
		
//		cout<<mm<<':'<<ss<<endl;

		if(mm==0 && ss<=6)
			ss=0;
		if(ss>0)
			++mm;

		sum+=mm;

//		cout<<sum<<endl;
	}

//	cout<<sum<<endl;

	a=n1+sum*c1;
	if(sum<=t)
		b=n2;
	else
		b=n2+(sum-t)*c2;
	c=n3;

	printf("Basic:     %d\n", a);
	printf("Combined:  %d\n", b);
	printf("Unlimited: %d\n", c);

	return 0;

	
}