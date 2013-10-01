#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 122
long long girl[maxn], boy[maxn], n, m, ans, tmp, len;
bool cmp(long long x, long long y){return x>y;}
int main(){
	scanf("%d%d", &n, &m);
	for(long long i=0;i<n;++i) scanf("%d", &girl[i]);
	for(long long i=0;i<m;++i) scanf("%d", &boy[i]);
	sort(girl, girl+n, cmp);
	sort(boy, boy+m, cmp);
	ans=2147483647;
	len=min(n, m);
	for(long long i=0;i<=len;++i){
		tmp=0;
		for(long long j=i;j<len;++j) tmp+=girl[j]+boy[j]*i;
		if(len==n)
			for(long long j=len;j<m;++j) tmp+=boy[j]*i;
		if(len==m)
			for(long long j=len;j<n;++j) tmp+=girl[j];
		if(tmp<ans) ans=tmp;
	}
	printf("%d\n", ans);
	return 0;
}