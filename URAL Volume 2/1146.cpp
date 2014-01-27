#include <iostream>
using namespace std;

#define maxn 122
int a[maxn][maxn]={0};

int main(){
	int n;
	int r=-128;
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			scanf("%d", &a[i][j]);
			if(a[i][j]<=0 && r<a[i][j])
				r=a[i][j];
			a[i][j]+=a[i][j-1];
		}

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a[i][j]+=a[i-1][j];

	int tmp, ans=0;
	for(int lef=1;lef<=n;++lef)
		for(int rig=lef;rig<=n;++rig)
			for(int up=1;up<=n;++up)
				for(int dow=up;dow<=n;++dow){
					tmp=a[dow][rig]-a[dow][lef-1]-a[up-1][rig]+a[up-1][lef-1];
					if(ans<tmp)
						ans=tmp;
				}

	if(ans==0) ans=r;
	printf("%d\n", ans);
	return 0;
}
