#include <cstdio>
#define maxn 2022
int a[maxn]={0}, b[maxn]={0}, que[maxn], n;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;++i)scanf("%d", &que[i]);
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			if(i<j && que[i]>que[j]){++a[que[i]], ++b[que[j]];}
	for(int i=1;i<=n;++i)printf("%d %d\n", b[i]+1, n-a[i]);
	return 0;
}