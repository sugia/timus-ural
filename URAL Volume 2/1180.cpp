#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 262
int a[maxn], len;
int main(){
	len=0;
	char ch;
	while(cin>>ch) a[++len]=int(ch-'0');

	for(int i=len;i>=1;--i){
		a[i]-=(a[i]/3)*3;
		a[i-1]+=a[i]*10;
	}

	if(a[1]%3==0){
		cout<<2<<endl;
	}

	if(a[1]%3==1){
		cout<<1<<endl;
		cout<<1<<endl;
	}

	if(a[1]%3==2){
		cout<<1<<endl;
		cout<<2<<endl;
	}
	return 0;
}
