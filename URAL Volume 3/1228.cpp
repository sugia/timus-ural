#include <iostream>
#include<stdio.h>
int main(){ 
    long long n, s, a, b;
	scanf("%lld%lld", &n, &s);
	scanf("%lld", &a);
	printf("%lld", s/a-1);
	--n;
	while(n>0){
		scanf("%lld", &b);
		printf(" %lld", a/b-1);
		a=b;
		--n;
	}
	printf("\n");
	return 0;
}
