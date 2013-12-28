#include <iostream>
#include <vector>
using namespace std;
const int maxn=10022;
const int maxint=2100000022;
vector<int> elist[maxn];
int n, k;
bool leaf[maxn], used[maxn];
int que[maxn], dis[maxn], ansdis[maxn];
void init(){
	memset(leaf, true, sizeof(leaf));
	scanf("%d", &n);
	for(int i=2;i<=n;++i){
		scanf("%d", &k);
		if(i!=2)leaf[k]=false;
		elist[i].push_back(k),elist[k].push_back(i);
	}
	memset(ansdis, 0, sizeof(ansdis));
}

int nex(int x){
	++x;
	return x>=maxn?0:x;
}

void bfs(int x){
	memset(used, false, sizeof(used));
	memset(dis, 62, sizeof(dis));
	int s=0, t=1, h=x;
	que[1]=h,used[h]=true,dis[h]=0;
	while(nex(t)!=s){
		s=nex(s),h=que[s];
		for(int i=0;i<elist[h].size();++i)
			if(!used[elist[h][i]] && dis[elist[h][i]]>dis[h]+1){
				dis[elist[h][i]]=dis[h]+1;
				used[elist[h][i]]=true;
				t=nex(t);
				que[t]=elist[h][i];
			}
	}
	for(int i=1;i<=n;++i)
		if(!leaf[i]) ansdis[i]= ansdis[i] > dis[i] ? ansdis[i] : dis[i];
}

void print(){
	int ans=maxint, len=0;
	for(int i=1;i<=n;++i){
		if(ansdis[i]==0)ansdis[i]=maxint;
		if(ans>ansdis[i]){ans=ansdis[i],len=1;}
		else if(ans==ansdis[i])++len;
	}
	for(int i=1;i<=n;++i)
		if(ansdis[i]==ans){
			--len;
			len?printf("%d ", i):printf("%d\n", i);
		}
}

int main(){
	init();
	for(int i=1;i<=n;++i)if(leaf[i])bfs(i);
	print();
	return 0;
}
