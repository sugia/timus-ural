#include <cstdio>
int a[2022], n, m;
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;++i){
		scanf("%d", &a[i]);
		a[i+n]=a[i];
	}
	for(int i=m%n+1;i<m%n+11;++i)printf("%d", a[i]);
	printf("\n");
	return 0;
}