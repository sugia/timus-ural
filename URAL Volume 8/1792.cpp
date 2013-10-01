#include <cstdio>
#define maxn 7
int a[maxn], step=0;
bool finish(){
	if(a[6]!=(a[0]+a[1]+a[3])%2 || a[5]!=(a[0]+a[2]+a[3])%2 || a[4]!=(a[1]+a[2]+a[3])%2) return false;
	return true;
}
int main(){
	for(int i=0;i<maxn;++i) scanf("%d", &a[i]);
	while(!finish() && step<maxn){
		if(step!=0) a[step-1]=1-a[step-1];
		a[step]=1-a[step], ++step;
	}
	printf("%d", a[0]);
	for(int i=1;i<maxn;++i) printf(" %d", a[i]);
	printf("\n");
	return 0;
}


	