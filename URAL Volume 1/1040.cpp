//#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

const int maxn=1022;

int d[maxn][maxn], s[maxn*maxn][3];
bool a[maxn][maxn], f[maxn];
int m, n, p, q, k=0;

void dfs(int x){
	f[x]=true;
	for(int i=1;i<=n;++i)
		if(a[x][i] && d[x][i]==0){
			++k;
			d[x][i]=k;
			d[i][x]=k;
			if(!f[i])
				dfs(i);
		}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;++i){
		scanf("%d%d", &p, &q);
		s[i][1]=p;
		s[i][2]=q;
		a[p][q]=true;
		a[q][p]=true;
	}
	dfs(1);
	printf("YES\n");
	for(int i=1;i<m;++i) printf("%d ", d[s[i][1]][s[i][2]]);
	printf("%d\n", d[s[m][1]][s[m][2]]);
	return 0;
}
