#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.1415926535
int main(){
	double v, a, k;
	scanf("%lf%lf%lf", &v, &a, &k);
	double ans=v*v*sin(a*pi/90)/10*k/(k-1);
	printf("%.2lf\n", ans);
	return 0;
}
