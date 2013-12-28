//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 222
int n, x[maxn], y[maxn], ans, tmp;

bool online(int a, int b, int c){
	return (y[c]-y[a])*(x[b]-x[a]) == (x[c]-x[a])*(y[b]-y[a]);
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;++i) scanf("%d%d", &x[i], &y[i]);
	ans=0;
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j){
			tmp=0;
			for(int k=1;k<=n;++k)
				if(online(i, j, k)) ++tmp;
			if(ans<tmp) ans=tmp;
		}
	printf("%d\n", ans);
	return 0;
}
