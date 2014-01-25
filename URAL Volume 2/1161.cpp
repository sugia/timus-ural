#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 122
double a[maxn];
int n;

bool cmp(double x, double y){
	return x>y;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;++i)
		scanf("%lf", &a[i]);

	if(n==1){
		printf("%.2lf\n", a[0]);
		return 0;
	}
	else if(n==2){
		printf("%.2lf\n", 2*sqrt(double(a[0]*a[1])));
		return 0;
	}

	sort(a, a+n, cmp);

	for(int i=1;i<n;++i){
		a[i]=2*sqrt(double((a[i-1]*a[i])));
		sort(a+i, a+n, cmp);
	}

	printf("%.2lf\n", a[n-1]);
	return 0;
}
	
