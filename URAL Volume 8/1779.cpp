#include <cstdio>
const int maxn=222222;
int x[maxn], y[maxn], sum[maxn]={0}, n;
int main(){
	scanf("%d", &n);
	int top=0, s=1, t=n;
	while(s<t){
		t-=2;
		for(int i=s+1;i<=t;++i){++top, x[top]=s, y[top]=i, ++sum[s], ++sum[i];}
		++s;
	}
	if(n%3==0){++top, x[top]=n/3, y[top]=n/3+1, ++sum[n/3], ++sum[n/3+1];}
	printf("%d\n", top);
	for(int i=1;i<=top;++i) printf("%d %d\n", x[i], y[i]);
	return 0;
}