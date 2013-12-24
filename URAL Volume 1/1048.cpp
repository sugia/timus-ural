//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 1000022
int n, a[maxn], x, y;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;++i){
		scanf("%d%d", &x, &y);
		a[i]=x+y;
	}
	for(int i=n;i>1;--i){
		a[i-1]+=a[i]/10;
		a[i]%=10;
	}
	for(int i=1;i<=n;++i)
		printf("%d", a[i]);
	printf("\n");
	return 0;
}
