#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
const double pi=3.1415926535;
const int maxn=122;

double sqr(double x){
	return x*x;
}

double x[maxn], y[maxn], r, ans;
int n;

int main(){
	cin>>n>>r;
	for(int i=1;i<=n;++i)
		cin>>x[i]>>y[i];

	ans=2*pi*r;
	
	for(int i=2;i<=n;++i)
		ans+=sqrt(sqr(x[i]-x[i-1])+sqr(y[i]-y[i-1]));

	ans+=sqrt(sqr(x[1]-x[n])+sqr(y[1]-y[n]));

	printf("%.2lf\n", ans);
	return 0;
}

	