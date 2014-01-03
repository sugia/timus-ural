//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <math.h>
using namespace std;

const double pi=3.14159265358979;
int len, r;
double ans, duijiaoxian, slen;

double sqr(double x){
	return x*x;
}

int main(){
	cin>>len>>r;
	slen=len*1.0/2;
	duijiaoxian=sqrt((double)2*sqr(slen));
	if(r<=slen){
		ans=sqr(r)*pi;
		printf("%.3lf\n", ans);
		return 0;
	}

	if(r>=duijiaoxian){
		ans=len*len;
		printf("%.3lf\n", ans);
		return 0;
	}

	double a=sqrt((double)sqr(r)-sqr(slen));
	double delta=atan2(a, slen);
	double theta=pi/2-2*delta;

	ans=theta/(2*pi) *sqr(r)*pi;
	ans+=a*slen;
	ans*=4;
	printf("%.3lf\n", ans);
	return 0;
}
