#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
using namespace std;

const int maxn=122;
const int maxint=50022;

int d[maxn];
int a[maxn][maxn];
int list[maxn];
int que[maxn];
int fa[maxn];
int ans, top, n, m;

bool inque[maxn];
bool b[maxn][maxn];

int nex(int x){
	return ++x>=maxn?0:x;
}

void print(){
	if(top==0)
		printf("No solution.\n");
	else{
		printf("%d", list[top]);
		for(int i=top-1;i>0;--i)
			printf(" %d", list[i]);
		printf("\n");
	}
}

void done(int x, int y){
	int s=0;
	int t=1;
	int h;
	b[x][y]=false;
	b[y][x]=false;
	for(int i=1;i<=n;++i){
		d[i]=maxint;
		fa[i]=i;
		inque[i]=false;
	}
	d[x]=0;
	que[1]=x;
	inque[x]=true;
	while(nex(t)!=s){
		s=nex(s);
		h=que[s];
		inque[h]=false;
		for(int i=1;i<=n;++i)
			if(b[h][i] && d[i]>d[h]+a[h][i]){
				d[i]=d[h]+a[h][i];
				fa[i]=h;
				if(!inque[i]){}
					t=nex(t);
				que[t]=i;
				inque[i]=true;
			}

	}

	if(ans>d[y]+a[x][y]){
		ans=d[y]+a[x][y];
		top=0;
		while(y!=fa[y]){
			list[++top]=y;
			y=fa[y];
		}
		list[++top]=y;
	}
	b[x][y]=true;
	b[y][x]=true;

}

int main(){
	scanf("%d", &n);
	while(n!=-1){
		scanf("%d", &m);
		top=0;
		ans=maxint;
		memset(b, false, sizeof(b));
		int x, y, z;
		for(int i=0;i<m;++i){
			scanf("%d%d%d", &x, &y, &z);
			if(!b[x][y]){
				a[x][y]=z;
				a[y][x]=z;
				b[x][y]=true;
				b[y][x]=true;
			}
			else if(a[x][y]>z){
				a[x][y]=z;
				a[y][x]=z;
			}
		}
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				if(b[i][j])
					done(i, j);
		print();
		scanf("%d", &n);
	}
	return 0;
}