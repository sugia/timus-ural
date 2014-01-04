#include <cstdio>
const int maxn=1022;
int nx[maxn], ny[maxn], parent[maxn], id[maxn], quex[maxn], quey[maxn], ans[maxn], n, target;
bool used[maxn]={0};

int nex(int x){
	++x;
	return x>=maxn?0:x;
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;++i){
		parent[i]=i;
		scanf("%d%d", &nx[i], &ny[i]);
	}
	scanf("%d", &target);
	scanf("%d%d", &nx[0], &ny[0]);
	if(target==nx[0] || target==ny[0]){
		printf("0\n");
		return 0;
	}
	int s=0, t=1, hx, hy, lev;
	quex[1]=nx[0], quey[1]=ny[0];
	used[0]=true, id[1]=0;
	while(nex(t)!=s){
		s=nex(s),hx=quex[s],hy=quey[s],lev=id[s];
		for(int i=1;i<=n;++i)
			if(!used[i] && (hx==nx[i] || hy==nx[i])){
				parent[i]=lev,t=nex(t),quex[t]=nx[i],quey[t]=ny[i],used[i]=true,id[t]=i;
				if(target==nx[i] || target==ny[i]){
					int len=0, tmp=i;
					while(parent[tmp]!=tmp){ans[++len]=tmp,tmp=parent[tmp];}
					printf("%d\n", len);
					for(int j=len;j>=1;--j)printf("%d\n", ans[j]);
					return 0;
				}
			}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}
