//#include "stdafx.h"
#include <iostream>
using namespace std;
int a, b, c;

bool isluckly(int x){
	int sum1=0, sum2=0;
	for(int i=1;i<=3;++i){
		sum2+=x%10;
		x/=10;
	}
	for(int i=1;i<=3;++i){
		sum1+=x%10;
		x/=10;
	}
	if(sum1==sum2)
		return true;
	else
		return false;
}

int main(){
	cin>>b;

	if(isluckly(b-1) | isluckly(b+1)) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
