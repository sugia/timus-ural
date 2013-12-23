//#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int maxn=1022;

unsigned long long n, f[maxn], que[maxn], upbound[maxn], lowbound[maxn], top, tmp, head, t;
bool b[maxn];

int gcd(int x, int y){
	if(y==0) return x;
	else return gcd(y, x%y);
}

int main(){
	cin>>n;
	memset(b, true, sizeof(b));
	for(int i=1;i<=n;++i) cin>>f[i];

	top=0;
	t=n;
	while(t>0){
		tmp=1;
		while(!b[tmp]) ++tmp;

		que[++top]=1;
		b[tmp]=false;
		--t;
		head=tmp;

		while(f[tmp]!=head){
			tmp=f[tmp];
			b[tmp]=false;
			--t;
			++que[top];
		}
	}

	if(top==1) cout<<que[top]<<endl;
	else{
		lowbound[2]=gcd(que[1], que[2]);
		upbound[2]=que[1]/lowbound[2]*que[2];

		for(int i=3;i<=top;++i){
			lowbound[i]=gcd(upbound[i-1], que[i]);
			upbound[i]=upbound[i-1]/lowbound[i]*que[i];
		}

		cout<<upbound[top]<<endl;
	}
	return 0;
}
