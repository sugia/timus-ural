//#include "stdafx.h"
#include <iostream>
using namespace std;
const int maxn=50022;
int n, m, a[maxn], b[maxn], l, r, mid, x;
bool flag;

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>b[i];
		b[i]=10000-b[i];
	}

	flag=false;
	for(int i=1;i<=n;++i){
		l=1;
		r=m;
		while(l<=r){
			mid=l+(r-l)/2;
			if(a[i]==b[mid]){
				cout<<"YES"<<endl;
				flag=true;
				return 0;
			}

			if(a[i]<b[mid])
				r=mid-1;
			else
				l=mid+1;
		}
	}
	if(!flag)
		cout<<"NO"<<endl;

	return 0;
}