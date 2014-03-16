#include <iostream>
using namespace std;
const int maxn=10000022;
int f[maxn];
int main(){
	int k, p;
	scanf("%d%d", &k, &p);
	f[1]=0;
	f[2]=1;
	for(int i=3;i<=k;++i){
		f[i]=f[i-1];
		if(i&1^1) f[i]=(f[i]+f[i>>1])%p;
	}
	printf("%d\n", f[k]%p);
	return 0;
}
