//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 1022
int n, m, y, x, len=0, a[maxn];

inline int sqr(int x){
	return x*x;
}

inline int mod(int x, int n, int m){
	if(n==0) return 1;
	
	if(n==1) return x%m;

	if(n%2==0) return sqr(mod(x, n/2, m)) % m;
	else return sqr(mod(x, n/2, m)) %m * x % m;
}

int main(){

	scanf("%d%d%d", &n, &m, &y);
	for(int i=0;i<m;++i)
		if(mod(i, n, m)==y) a[++len]=i;

	if(len==0){
		printf("-1\n");
		return 0;
	}

	printf("%d", a[1]);
	for(int i=2;i<=len;++i) printf(" %d", a[i]);
	printf("\n");

	return 0;
}
