#include <cstdio>
#define maxn 102
int a[maxn], sum, k, n;
int main(){
	scanf("%d%d", &k, &n);
	a[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%d", &a[i]);
		a[i]+=a[i-1];
		a[i]-k>0?a[i]-=k:a[i]=0;
	}
	printf("%d\n", a[n]);
	return 0;
}