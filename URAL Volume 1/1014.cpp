//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

#define maxn 32
int n, a[maxn], top;

int main(){
	top=0;
	scanf("%d", &n);
	if(n==0){
		printf("10\n");
		return 0;
	}
	if(n==1){
		printf("1\n");
		return 0;
	}
	for(int i=9;i>=2;--i){
		while(n%i==0){
			a[++top]=i;
			n/=i;
		}
	}
	if(n!=1) printf("-1");
	else for(int i=top;i>=1;--i) printf("%d", a[i]);

	printf("\n");
	return 0;
}
