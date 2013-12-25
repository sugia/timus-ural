//#include "stdafx.h"
#include <iostream>
using namespace std;

const int maxn=32;

int p[maxn], data[maxn];
int from, tmp, target, now, q;

void swap(int &a, int &b){
	int tmp=a;
	a=b;
	b=tmp;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;++i) scanf("%d", &data[i]);
	for(int i=0;i<n;++i) p[i]=(1<<i)-1;
	from=1;
	tmp=3;
	target=2;
	now=0;
	for(int i=n;i>=1;--i){
		if(data[i]==tmp){
			printf("-1\n");
			return 0;
		}
		if(data[i]==from) swap(tmp, target);
		else{
			swap(from, tmp);
			now+=p[i-1]+1;
		}
	}
	printf("%d\n", now);
	return 0;
}
