#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=122;
int a[maxn], n;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;++i) scanf("%d", &a[i]);
	sort(a, a+n);
	int ans=0, s=0, t=n-1;
	while(s<t){
		if(t-s==1){ans+=a[t], ++s, --t;}
		else if(t-s==2){ans+=a[t], --t, ans+=a[s], ans+=a[t], ++s, --t;}
			 else{ans+=min(a[s+1]+a[s]+a[t]+a[s+1], a[t]+a[s]+a[t-1]+a[s]), t-=2;}
	}
	printf("%d\n", ans);
	return 0;
}