//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 10022
#define maxint 1e9
int d[maxn]={0}, f[maxn];

int main(){
	for(int i=0;i<maxn;++i)	f[i]=maxint;
	int n, l1, l2, l3, c1, c2, c3, s, t;
	scanf("%d%d%d%d%d%d", &l1, &l2, &l3, &c1, &c2, &c3);
	scanf("%d", &n);
	scanf("%d%d", &s, &t);
	
	if(s>t){
		int tmp=s;
		s=t;
		t=tmp;
	}

	for(int i=2;i<=n;++i)
		scanf("%d", &d[i]);


	f[s]=0;
	for(int i=s;i<t;++i){
		int j=1;
		while(d[i+j]-d[i]<=l3){
			if(d[i+j]-d[i]<=l1) f[i+j]=min(f[i+j], f[i]+c1);
			if(d[i+j]-d[i]<=l2) f[i+j]=min(f[i+j], f[i]+c2);
			if(d[i+j]-d[i]<=l3) f[i+j]=min(f[i+j], f[i]+c3);
			++j;
		}
	}

	printf("%d\n", f[t]);
	return 0;
}
