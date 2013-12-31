//#include "stdafx.h"
#include <iostream>
using namespace std;

template<class T>
T sqr(T x){
	return x*x;
}

int main(){
	double xa, ya, za, xb, yb, zb, xc, yc, zc, r;
	scanf("%lf%lf%lf", &xa, &ya, &za);
	scanf("%lf%lf%lf", &xb, &yb, &zb);
	scanf("%lf%lf%lf", &xc, &yc, &zc);
	scanf("%lf", &r);

	double ab=sqrt(sqr(xa-xb) + sqr(ya-yb) + sqr(za-zb));
	double ac=sqrt(sqr(xa-xc) + sqr(ya-yc) + sqr(za-zc));
	double bc=sqrt(sqr(xb-xc) + sqr(yb-yc) + sqr(zb-zc));

	double c=acos((sqr(ac) + sqr(bc) - sqr(ab)) / (2*ac*bc));
	double a=acos(r/ac);
	double b=acos(r/bc);

	if(a+b>=c) printf("%.2lf\n", ab);
	else printf("%.2lf\n", (c-a-b)*r + sqrt(sqr(ac) - sqr(r)) + sqrt(sqr(bc) - sqr(r)));
	return 0;
}
