#include <stdio.h>
#include <iostream>
using namespace std;

#define maxn 222

int n, k, f[maxn][maxn], len[maxn];

void writeln(int x){
	for(int i=len[x];i>=1;--i)
		printf("%d", f[x][i]);
	printf("\n");
}

void done(int x){
	len[x]= len[x-1] > len[x-2] ? len[x-1] : len[x-2];
	for(int i=1;i<=len[x];++i){
		f[x][i]+=f[x-1][i]+f[x-2][i];
		f[x][i+1]+=f[x][i]/10;
		f[x][i]%=10;
	}
	while(f[x][len[x]+1]!=0) ++len[x];

	for(int i=1;i<=len[x];++i) f[x][i]*=(k-1);

	while(f[x][len[x]+1]!=0) ++len[x];

	for(int i=1;i<=len[x];++i){
		f[x][i+1]+=f[x][i]/10;
		f[x][i]%=10;
	}

	while(f[x][len[x]+1]!=0) ++len[x];
}



int main(){
	scanf("%d%d", &n, &k);
	memset(f, 0, sizeof(f));
	memset(len, 0, sizeof(len));

	f[0][1]=1;
	len[0]=1;
	f[1][1]=k-1;
	len[1]=1;

	for(int i=2;i<=n;++i) done(i);

	writeln(n);
	return 0;
}
