#include <stdio.h>
#include <iostream>
using namespace std;
#define maxn 52
unsigned long long f[maxn], n;
int main(){
	scanf("%d", &n);
	f[1]=2;
	f[2]=2;
	for(int i=3;i<=n;++i) f[i]=f[i-1]+f[i-2];
	printf("%lld\n", f[n]);
	return 0;
}
