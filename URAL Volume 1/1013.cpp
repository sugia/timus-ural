#include <stdio.h>
#include <iostream>
using namespace std;

#define maxn 2222
#define maxm 3

int n, k, f[maxm][maxn], len[maxm];

void writeln(int x){

	for(int i=len[x];i>=1;--i)
		printf("%d", f[x][i]);
	printf("\n");
}

int prev(int x){
	int y=x-1;
	if(y<0)
		y+=maxm;
	return y;
}

int next(int x){
	int y=x+1;
	if(y>=maxm)
		y-=maxm;
	return y;
}

void done(const int x){
	len[x]= len[prev(x)] > len[prev(prev(x))] ? len[prev(x)] : len[prev(prev(x))];

	for(int i=1;i<=len[x];++i)
		f[x][i]=0;
	for(int i=1;i<=len[x];++i){
		f[x][i]+=f[prev(x)][i]+f[prev(prev(x))][i];
		f[x][i+1]+=f[x][i]/10;
		f[x][i]%=10;
	}
	while(f[x][len[x]+1]!=0)
		++len[x];

	for(int i=1;i<=len[x];++i)
		f[x][i]*=(k-1);

	while(f[x][len[x]+1]!=0)
		++len[x];

	for(int i=1;i<=len[x];++i){
		f[x][i+1]+=f[x][i]/10;
		f[x][i]%=10;
	}

	while(f[x][len[x]+1]!=0)
		++len[x];


//	writeln(x);
}


int main(){
	scanf("%d%d", &n, &k);
	memset(f, 0, sizeof(f));
	memset(len, 0, sizeof(len));

	f[0][1]=1;
	len[0]=1;
	f[1][1]=k-1;
	len[1]=1;

//	writeln(0);
//	writeln(1);
	for(int i=2;i<=n;++i)
		done(i%maxm);

	writeln(n%maxm);
	return 0;
}