//#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
const int maxn=15004;
int sushu[maxn], tmp, top, k, n;
bool flag;
int main()
{
	sushu[1]=2;
	sushu[2]=3;
	sushu[3]=5;
	sushu[4]=7;
	top=4;
	tmp=9;
	while(top<15000){
		tmp+=2;
		flag=true;
		for(int i=2;i<=sqrt((double)tmp);++i)
			if(tmp%i==0){
				flag=false;
				break;
			}
			if(flag)
				sushu[++top]=tmp;
	}
	cin>>k;
	while(k--){
		cin>>n;
		cout<<sushu[n]<<endl;
	}
	return 0;
}