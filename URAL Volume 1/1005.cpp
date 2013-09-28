#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
using namespace std;

const int maxn=2000022;
int n, sum;
int f[maxn];
int a[maxn];

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;++i){
		scanf("%d", &a[i]);
		sum+=a[i];
	}
	memset(f, 0, sizeof(f));
	for(int i=1;i<=n;++i)
		for(int j=sum/2;j>=a[i];--j)
			f[j]=max(f[j], f[j-a[i]]+a[i]);
	printf("%d\n", sum-f[sum/2]*2);
	return 0;
}