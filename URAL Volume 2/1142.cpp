#include <iostream>
using namespace std;
#define maxn 12
int f[maxn][maxn]={0}, ans[maxn]={0};
int main(){
	int n;
	f[1][1]=1;
	for(int i=1;i<maxn-1;++i)
		for(int j=1;j<=i;++j){
			f[i+1][j]+=f[i][j]*j;
			f[i+1][j+1]+=f[i][j]*(j+1);
		}
	for(int i=1;i<maxn-1;++i)
		for(int j=1;j<=i;++j)
			ans[i]+=f[i][j];
	scanf("%d", &n);
	while(n!=-1){
		printf("%d\n", ans[n]);
		scanf("%d", &n);
	}
	return 0;
}
