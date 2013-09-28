#include <iostream>
using namespace std;

#define maxn 122
int a[maxn][maxn], f[maxn][maxn];
bool flag[maxn][maxn]={0}, visited[maxn]={0};
int n, m;

void init(){
	scanf("%d%d", &n, &m);
	int x, y, z;
	for(int i=1;i<n;++i){
		scanf("%d%d%d", &x, &y, &z);
		a[x][y]=z;
		flag[x][y]=true;
		a[y][x]=z;
		flag[y][x]=true;
	}
}

void search(int x){
	visited[x]=true;
	int l=0, r=0;
	for(int j=1;j<=n;++j)
		if(flag[x][j] && !visited[j]){
			if(l==0)
				l=j;
			else
				r=j;
			search(j);
		}

	if(!(l==0 && r==0)){
		for(int j=0;j<=m;++j)
			for(int k=0;k<=m;++k)
				if(j+k+2<=m && f[l][j]+f[r][k]+a[x][l]+a[x][r]>f[x][j+k+2])
					f[x][j+k+2]=f[l][j]+f[r][k]+a[x][l]+a[x][r];
		for(int j=0;j<=m;++j)
			if(j+1<=m && f[l][j]+a[x][l]>f[x][j+1])
				f[x][j+1]=f[l][j]+a[x][l];
		for(int k=0;k<=m;++k)
			if(k+1<=m && f[r][k]+a[x][r]>f[x][k+1])
				f[x][k+1]=f[r][k]+a[x][r];
	}
}

void print(){
	printf("%d\n", f[1][m]);
}

int main(){
	init();
	search(1);
	print();
	return 0;
}