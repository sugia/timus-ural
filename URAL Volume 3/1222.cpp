#include <iostream>
using namespace std;
#define maxn 3022
int n, step;
int ans[maxn];
int main(){
	scanf("%d", &n);
	if(n==1){
		printf("1\n");
		return 0;
	}
	ans[0]=1;
	if(n%3==0){
		ans[1]=1;
	}
	if(n%3==1){
		ans[1]=4;
		n-=4;
	}
	if(n%3==2){
		ans[1]=2;
		n-=2;
	}
	step=n/3;
	for(int i=1;i<=step;++i){
		for(int j=1;j<=ans[0];++j) ans[j]*=3;
		for(int j=1;j<=ans[0]+1;++j){
			ans[j+1]+=ans[j]/10;
			ans[j]%=10;
		}
		int k=ans[0];
		while(ans[k+1]!=0) ++k;
		ans[0]=k;
	}
	for(int i=ans[0];i>=1;--i) printf("%d", ans[i]);
	printf("\n");
	return 0;
}
