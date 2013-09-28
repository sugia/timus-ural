#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	long ans=0, mini=1, maxi=0;
	double p, q;
	scanf("%lf%lf", &p, &q);
	if(p>q){
		double tmp=p;
		p=q;
		q=tmp;
	}

	while(mini>=maxi){
		++ans;
		mini=long(ans*p*100)/10000+1;
		maxi=long(ans*q*100)/10000;
		if(long(ans*q*100)%10000!=0)
			++maxi;
	}

	printf("%ld\n", ans);
	return 0;
}