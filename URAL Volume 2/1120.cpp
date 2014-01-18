#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	for(int p=int(sqrt(double(n+n))); p>0;--p){
		int tmp=(n+n)-p*p;
		if(tmp%p==0 && (tmp/p)%2==1){
			int a=(tmp/p+1)/2;
			printf("%d %d\n", a, p);
			return 0;
		}
	}
}
