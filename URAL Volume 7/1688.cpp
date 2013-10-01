#include <cstdio>
#define maxn 3022
long long n, m, tmp, tot=0;
int main(){
	scanf("%lld%lld", &n, &m);
	for(int i=1;i<=m;++i){
        scanf("%d", &tmp);
        tot+=tmp;
		if(tot>n*3){
			printf("Free after %d times.\n", i);
			return 0;
		}
	}
	printf("Team.GOV!\n");
	return 0;
}