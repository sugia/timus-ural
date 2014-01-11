//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 122
int que[maxn], color[maxn], n, s, t, h;
bool used[maxn]={0}, tutu[maxn][maxn]={0};

int nex(int x){
	++x;
	if(x==maxn) x=0;
	return x;
}

int pre(int x){
	--x;
	if(x<0)	x=maxn;
	return x;
}

int main(){
	scanf("%d", &n);
	int x;
	for(int i=1;i<=n;++i){
		scanf("%d", &x);
		if(x==0){
			printf("0\n");
			return 0;
		}
		while(x!=0){
			tutu[i][x]=true;
			tutu[x][i]=true;
			scanf("%d", &x);
		}
	}

	s=1, t=0;
	for(int i=1;i<=n;++i)
		if(!used[i]){
			color[i]=0;
			used[i]=true;

			t=nex(t);
			que[t]=i;
			s=pre(s);

			while(nex(t)!=s){
				s=nex(s);
				h=que[s];
				for(int j=1;j<=n;++j)
					if(!used[j] && tutu[h][j]){
						color[j]=1-color[h];
						used[j]=true;
						t=nex(t);
						que[t]=j;
					}
			}
		}

	int sum=0;
	for(int i=1;i<=n;++i)
		if(color[i]==0)	++sum;

	printf("%d\n", sum);
	sum=0;
	for(int i=1;i<=n;++i)
		if(color[i]==0){
			++sum;
			if(sum!=1) printf(" ");
			printf("%d", i);
		}
	printf("\n");
	return 0;
}
