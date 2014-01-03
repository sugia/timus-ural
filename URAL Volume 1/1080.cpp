//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 122
int n, color[maxn], que[maxn], s, t, h;
bool used[maxn]={0}, tutu[maxn][maxn]={0};

int pre(int x){
	++x;
	if(x==maxn)
		x=0;
	return x;
}

int main(){
	scanf("%d", &n);
	int x;
	for(int i=1;i<=n;++i){
		while(scanf("%d", &x) && x!=0){
			tutu[i][x]=true;
			tutu[x][i]=true;
		}
	}

	s=0, t=1;
	que[1]=1;
	color[1]=0;
	used[1]=true;

	while(pre(t)!=s){
		s=pre(s);
		h=que[s];
		for(int i=1;i<=n;++i)
			if(tutu[h][i]){
				if(used[i]){
					if(color[i]==color[h]){
						printf("-1\n");
						return 0;
					}
				}
				else{
					used[i]=true;
					color[i]=1-color[h];
					t=pre(t);
					que[t]=i;
				}
			}
	}

	for(int i=1;i<=n;++i) printf("%d", color[i]);
	printf("\n");
	return 0;
}
