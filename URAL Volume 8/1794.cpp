#include <cstdio>
#define maxn 200022
int a[maxn], f[maxn], ti[maxn], n, best=0, sum=0;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;++i){
		scanf("%d", &a[i]);
		a[n+i]=a[i], f[i]=i-a[i];	
		if(f[i]<0) f[i]+=n;
		if(f[i]>n) f[i]-=n;
		f[n+i]=f[i], ++ti[f[i]];
	}
	for(int i=0;i<=n*2;++i)
		if(ti[i]>sum){best=i, sum=ti[i];}
	printf("%d\n", best+1);
	return 0;

}