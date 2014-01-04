//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 10022
#define maxm 52

bool f[maxn];
int k[maxm];

int main(){
	memset(f, false, sizeof(f));
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;++i) scanf("%d", &k[i]);

	f[0]=true;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(i>=k[j] && !f[i-k[j]]) f[i]=true;

	if(f[n]) printf("1\n");
	else printf("2\n");
	return 0;
}
