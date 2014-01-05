//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 150022
int id[maxn], ran[maxn], step[maxn], n;

void qs(int s, int t){
	int i=s, j=t, x=ran[(s+t)/2], y=step[(s+t)/2], tmp;
	while(i<=j){
		while(ran[i]>x || (ran[i]==x && step[i]<y))
			++i;
		while(x>ran[j] || (x==ran[j] && y<step[j]))
			--j;

		if(i<=j){
			tmp=ran[i];
			ran[i]=ran[j];
			ran[j]=tmp;

			tmp=id[i];
			id[i]=id[j];
			id[j]=tmp;

			tmp=step[i];
			step[i]=step[j];
			step[j]=tmp;

			++i;
			--j;
		}
	}
	if(i<t)
		qs(i, t);
	if(s<j)
		qs(s, j);
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;++i){
		scanf("%d%d", &id[i], &ran[i]);
		step[i]=i;
	}
	qs(0, n-1);
	for(int i=0;i<n;++i)
		printf("%d %d\n", id[i], ran[i]);

	return 0;
}
