//#include "stdafx.h"
#include <iostream>
using namespace std;
const int maxn=101002;
int a[maxn], n, ans;
int main()
{
	while(cin>>n && n!=0){
		a[0]=0;
		a[1]=1;
		ans=1;
		for(int i=1;i<=n/2;++i){
			a[2*i]=a[i];
			if(2*i<=n && a[2*i]>ans)
				ans=a[2*i];
			a[2*i+1]=a[i]+a[i+1];
			if(2*i+1<=n && a[2*i+1]>ans)
				ans=a[2*i+1];
		}
		cout<<ans<<endl;
//		for(int i=0;i<n;++i)
//			cout<<a[i]<<' ';
//		cout<<endl;
	}
	return 0;
}