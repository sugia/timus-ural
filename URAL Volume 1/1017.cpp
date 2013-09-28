#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 522
int n;
double f[maxn];

int main(){
	scanf("%ld", &n);
	memset(f, 0, sizeof(f));
	f[0]=1;
	for(int i=1;i<n;++i)
		for(int j=n-i;j>=0;--j)
			f[i+j]+=f[j];

	printf("%.0lf\n", f[n]);
	return 0;
}