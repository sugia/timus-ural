#include <iostream>
#include <string.h>
#include <string>
using namespace std;
const int maxn=102;
int n, a[maxn][maxn], tmp;
int main(){
	cin>>n;
	a[1][1]=1;
	tmp=1;
	int i, j;
	for(int k=2;k<=n;++k){
		i=1;
		j=k;
		for(int t=1;t<=k;++t){
			a[i][j]=++tmp;;
			++i;
			--j;
		}
	}
	for(int k=2;k<=n;++k){
		i=k;
		j=n;
		for(int t=1;t<=n+1-k;++t){
			a[i][j]=++tmp;;
			++i;
			--j;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=n;j>=1;--j){
			if(j!=n) cout<<' ';
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
