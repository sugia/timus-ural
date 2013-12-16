//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 500022
int len, n, a[maxn];

void qs(int s, int t){
	if(t-s<20){
		for(int i=s;i<t;++i)
			for(int j=i+1;j<=t;++j)
				if(a[i]>a[j]){
					int tmp=a[i];
					a[i]=a[j];
					a[j]=tmp;
				}
	}
	else{
		int i=s, j=t, x=a[(s+t)/2];
		while(i<=j){
			while(a[i]<x)
				++i;
			while(x<a[j])
				--j;
			if(i<=j){
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;

				++i;
				--j;
			}
		}
		if(i<t)
			qs(i, t);
		if(s<j)
			qs(s, j);
	}
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
		scanf("%d", &a[i]);

	qs(1, n);

	//for(int i=1;i<=n;++i)
	//	printf("%d ", a[i]);
	//printf("\n");

	int ans=1, sum=0, s=1, t=1;
	while(s<=n){
		while(a[t+1]==a[s])
			++t;
		int tmp=t-s+1;
		if(sum<tmp){
			sum=tmp;
			ans=a[s];
		}

		s=t+1;
		t=s;
	}

	printf("%d\n", ans);
	return 0;
}
