#include <cstdio>
int main(){
    long long m, d1, d2, sum;
	scanf("%lld%lld%lld", &m, &d1, &d2);
	sum=m*d1;	
	printf("%lld", sum/d2);
	sum-=sum/d2;
	for(int i=d2-1;i>=1;--i){
		printf(" %lld", sum/i);
		sum-=sum/i;
	}
	printf("\n");
	return 0;
}