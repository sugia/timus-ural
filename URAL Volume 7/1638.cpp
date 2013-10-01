#include <cstdio>
int a, b, c, d;
int main(){
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int ans=0;
	if(c<d) ans=(d-c-1)*(a+b+b)+b+b;
	else if(c>d) ans=(c-d)*(a+b+b)+a;
         else ans=a;
	printf("%d\n", ans);
	return 0;
}