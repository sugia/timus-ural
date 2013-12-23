//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 10022
int n, a[maxn], sum[maxn]={0}, f[maxn]={0};

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
		scanf("%d", &a[i]);

	for(int i=1;i<=n;++i){
		sum[i]=(a[i]+sum[i-1])%n;
		if(f[sum[i]] || (sum[i]==0)){
			printf("%d\n", i-f[sum[i]]);
			for(int j=f[sum[i]]+1;j<=i;++j)	printf("%d\n", a[j]);
			break;
		}
		f[sum[i]]=i;
	}
	return 0;
}
