#include <stdio.h>
#include <iostream>
using namespace std;
long long n, m;
int f[4][4]={0};
int main(){
	f[1][1]=0;
	f[1][2]=0;
	f[1][3]=0;
	f[2][1]=1;
	f[2][2]=2;
	f[2][3]=2;
	f[3][1]=1;
	f[3][2]=3;
	f[3][3]=4;
	long long ans=0;
	scanf("%lld%lld", &n, &m);
	long long mini=min(n, m);
	long long tmp=(mini-1)/2;
	ans=tmp*4;
	n-=tmp*2;
	m-=tmp*2;
	if(n>3){
		if(m==1) ++ans;
		if(m==2) ans+=3;
	}
	else if(m>3){
		if(n==2) ans+=3;
	}
	else ans+=f[n][m];
	printf("%lld\n", ans);
	return 0;
}
