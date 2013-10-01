#include <iostream>
using namespace std;
#define maxn 20022
unsigned long long a[maxn], tmp, x;
int s, t, ans=0, len=3;
int main(){
	for(int i=1;i<=len;++i) scanf("%lldu", &a[i]);
	for(int i=1;i<len;++i)
		for(int j=i+1;j<=len;++j)
			if(a[i]<a[j]) swap(a[i], a[j]);
	while(++ans){
		x=a[1];
		for(int i=2;i<=len;++i){
			if(a[i-1]-a[i]<x) x=a[i-1]-a[i];
			if(x==0){
				printf("%d\n", ans);
				return 0;
			}
		}
		a[++len]=x;
		int step=len;
		while(step>1 && a[step]>a[step-1]){swap(a[step], a[step-1]), --step;}
	}
	return 0;
}