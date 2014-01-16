//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 1000022
int a[maxn]={0}, x, y, ans;
long double mini=(1+maxn)/2*maxn;
int main(){
//	cout<<mini<<endl;
	scanf("%d%d", &x, &y);
	if(x>y){
		int tmp=x;
		x=y;
		y=tmp;
	}
	if(x==1){
		printf("%d\n", 1);
		return 0;
	}

	for(int i=y;i>=x;--i){
		int tmp=0;
		for(int j=1;j<i;++j)
			if(i%j==0)
				tmp+=j;

		if(tmp==1){
			printf("%d\n", i);
			return 0;
		}

		double t=double(tmp)/i;

//		cout<<i<<' '<<t<<endl;

		if(t<mini){
			mini=t;
			ans=i;
		}
	}

	printf("%d\n", ans);
	return 0;
}
