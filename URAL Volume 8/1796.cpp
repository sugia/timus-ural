#include <cstdio>
#define maxn 12
int ticket[maxn], prize[maxn], sum=0, step=0, single;
long long a[5022]={0}, top=0, start;
int main(){
	for(int i=1;i<=6;++i) scanf("%d", &ticket[i]);
	prize[1]=10, prize[2]=50, prize[3]=100, prize[4]=500, prize[5]=1000, prize[6]=5000;
	scanf("%d", &single);
	for(int i=1;i<=6;++i) sum+=ticket[i]*prize[i];
	for(int i=1;i<=6;++i)
		if(ticket[i]>0){
			step=i;
			break;
		}
	start=sum-prize[step], step=0;
	while(step+single<=sum){
		step+=single;
		if(step>start) a[++top]=step/single;
	}
	printf("%lld\n%lld", top, a[1]);
	for(int i=2;i<=top;++i) printf(" %lld", a[i]);
	return 0;
}