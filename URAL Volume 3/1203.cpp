#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
const int maxn=100022;
int st[maxn], et[maxn];
void qs(int s, int t){
	int tmp;
	if(t-s<=20){
		for(int i=s;i<t;++i)
			for(int j=i+1;j<=t;++j)
				if(et[i]>et[j]){
					tmp=et[i];
					et[i]=et[j];
					et[j]=tmp;
					tmp=st[i];
					st[i]=st[j];
					st[j]=tmp;
				}
		return ;
	}
	int i=s, j=t, x=et[(s+t)/2];
	while(i<=j){
		while(et[i]<x) ++i;
		while(x<et[j]) --j;
		if(i<=j){
			tmp=et[i];
			et[i]=et[j];
			et[j]=tmp;
			tmp=st[i];
			st[i]=st[j];
			st[j]=tmp;
			++i;
			--j;
		}

	}
	if(s<j) qs(s, j);
	if(i<t) qs(i, t);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
		scanf("%d%d", &st[i], &et[i]);
	qs(1, n);
	int last=0, ans=0;
	for(int i=1;i<=n;++i)
		if(st[i]>last){
			++ans;
			last=et[i];
		}
	printf("%d\n", ans);
	return 0;
}
