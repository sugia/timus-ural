#include <cstdio>
int main(){
    int l, k, h, ans=0;
	scanf("%d%d%d", &l, &k, &h);
	while(l>=k){l-=k, ans+=h;}
    printf("%.8lf %.8lf\n", double(ans), l?double(ans+h):double(ans));
	return 0;
}