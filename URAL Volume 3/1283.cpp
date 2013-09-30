#include <cstdio>
int main(){
	long long ans=0;
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	while(a>b){
		a-=a*c/100;
		++ans;
	}
	printf("%lld\n", ans);
	return 0;
}