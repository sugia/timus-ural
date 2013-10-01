//#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

const double jingdu=0.001;

template<class T>
T abs(T tmp)
{
	tmp>=0? return tmp : return -tmp;
}

template<class T>
T sqr(T tmp)
{
	return tmp*tmp;
}

template<class T>
T dis(T ex, T ey, T rx, T ry)
{
	return sqrt(sqr(ex-rx) + sqr(ey-ry));
}

int main()
{
	double ax, ay, bx, by, x, y, len;
	scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by);
	scanf("%lf%lf%lf", &x, &y, &len);

	double m, n;
	if(ax==bx && ay==by)
	{
		double tmp=dis(x, y, ax, ay);
		printf("%.2lf\n", tmp>len? tmp-len : 0);
		printf("%.2lf\n", tmp>len? tmp-len : 0);
		return 0;
	}
	else
		if(ax==bx)
		{
			m=ax;
			n=y;
		}
		else
			if(ay==by)
			{
				m=x;
				n=ay;
			}
			else
			{
				double m1=(bx-ax)/(by-ay)*x;
				double m2=(by-ay)/(bx-ax)*bx;
				double m3=(bx-ax)/(by-ay);
				double m4=(by-ay)/(bx-ax);
				m = (m1 + y + m2 - by) / (m3 + m4);

				double n1=(by-ay)/(bx-ax)*y;
				double n2=(ax-bx)/(by-ay)*by;
				double n3=(by-ay)/(bx-ax);
				double n4=(bx-ax)/(by-ay);
				n = (n1 + x - n2 - bx) / (n3 + n4);
			}

	double maxi=dis(x, y, ax, ay);
	double mini=dis(x, y, bx, by);
	if(maxi<mini)
	{
		double tmp=maxi;
		maxi=mini;
		mini=tmp;
	}

	double d;
	if(abs(dis(ax, ay, bx, by) - dis(m, n, ax, ay) - dis(m, n, bx, by)) <jingdu)
	{
//		cout<<"done"<<endl;
		double a=by-ay;
		double b=ax-bx;
		double c=ay*bx - by*ax;

		d=abs(a*x + b*y + c)/sqrt(sqr(a) + sqr(b));


		//cout<<d<<endl;
		//cout<<m<<' '<<n<<endl;

		printf("%.2lf\n", d>len? d-len : 0);
		printf("%.2lf\n", maxi>len? maxi-len : 0);
	}
	else
	{
		d=0;
		printf("%.2lf\n", mini>len? mini-len : 0);
		printf("%.2lf\n", maxi>len? maxi-len : 0);
	}

	//cout<<d<<endl;
	//cout<<mini<<endl;
	//cout<<maxi<<endl;
	//cout<<len<<endl;
	//cout<<m<<' '<<n<<endl;
	//cout<<m1<<' '<<m2<<' '<<m3<<' '<<m4<<endl;
	//cout<<n1<<' '<<n2<<' '<<n3<<' '<<n4<<endl;
	return 0;
}