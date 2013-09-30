//#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
long long n, delta, a;

long long sqr(long long x)
{
	return x*x;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a;
		if(i!=1)
			cout<<' ';
		delta=sqrt((double)(8*a-7));
		if(sqr(delta)==8*a-7 && delta%2==1)
			cout<<1;
		else
			cout<<0;
	}
	cout<<endl;
	return 0;
}