//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 1022
#define ra 0.500000000

int x[maxn], y[maxn], bx, by, n;

inline double sqr(double x)
{
	return x*x;
}
int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;++i)
		scanf("%d%d", &x[i], &y[i]);


	double xx=ra, yy=ra, bdis=0;
	for(int k=1;k<=n;++k)
	{
		double tmp=sqrt(double( sqr(x[k]-xx) + sqr(y[k]-yy) ));
		if(tmp>bdis)
		{
			bdis=tmp;
			bx=x[k];
			by=y[k];
		}
	}
	printf("%.9lf %.9lf %.9lf\n",xx, yy, bdis);
	return 0;

}