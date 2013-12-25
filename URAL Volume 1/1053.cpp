//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 1022
long long a, b;
int n;

inline long long gcd(long long x, long long y){
	if(x==0 || y==0) return 0;
	
	if(x==1 || y==1) return 1;

	long long r;
	while(y!=0){
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}

int main(){
	scanf("%d", &n);
	scanf("%lld", &a);
	if(n==1){
		printf("%lld\n", a);
		return 0;
	}
	scanf("%lld", &b);
	a=gcd(a, b);
	for(int i=3;i<=n;++i){
		scanf("%lld", &b);
		a=gcd(a, b);
	}
	printf("%lld\n", a);
	return 0;
}
