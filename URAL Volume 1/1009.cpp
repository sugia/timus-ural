#include <stdio.h>
#define maxn 20
int f[maxn], i, j, k, n;
int main(){
	scanf("%d%d", &n, &k);
	f[1]=k-1;
	f[2]=(f[1]+1)*(k-1);
	for(i=3;i<=n;++i) f[i]=(f[i-1]+f[i-2])*(k-1);
	
	printf("%d\n", f[n]);
	return 0;
}
