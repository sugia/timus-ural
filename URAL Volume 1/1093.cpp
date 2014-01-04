//#include "stdafx.h"
#include <iostream>
using namespace std;

const double g=10;
double cx, cy, cz;
double nx, ny, nz, r;
double sx, sy, sz;
double vx, vy, vz;

void init(){
	scanf("%lf%lf%lf", &cx, &cy, &cz);
	scanf("%lf%lf%lf%lf", &nx, &ny, &nz, &r);
	scanf("%lf%lf%lf", &sx, &sy, &sz);
	scanf("%lf%lf%lf", &vx, &vy, &vz);
}

template<class T>
inline T sqr(T x){
	return x*x;
}

template<class T>
inline T dis(T ax, T ay, T az, T bx, T by, T bz){
	return sqrt(sqr(ax-bx) + sqr(ay-by) + sqr(az-bz));
}

void done(){
	double a = - g / 2 * nz;
	double b = vx*nx + vy*ny + vz*nz;
	double c = (sx-cx)*nx + (sy-cy)*ny + (sz-cz)*nz;
	double t1, t2;
	if(a==0){
		if(b==0){
			printf("MISSED\n");
			return ;
		}
		else{
			t1=-c/b;
			t2=t1;
		}
	}
	else{
		if(b==0){
			t1=sqrt(-c/a);
			t2=t1;
		}
		else{
			double delta=sqr(b)-4*a*c;
			if(delta<0){
				printf("MISSED\n");
				return ;
			}
			else if(delta==0){
				t1=-b/(2*a);
				t2=t1;
			}
			else{
				t1=(-b-sqrt(delta))/(2*a);
				t2=(-b+sqrt(delta))/(2*a);
			}
		}
	}

	double mx, my, mz, len;
	if(t1>=0){
		mx = sx + vx*t1;
		my = sy + vy*t1;
		mz = sz + vz*t1 - g/2*sqr(t1);

		len=dis(mx, my, mz, cx, cy, cz);
		if(len<r){
			printf("HIT\n");
			return ;
		}
	}

	if(t2>=0){
		mx = sx + vx*t2;
		my = sy + vy*t2;
		mz = sz + vz*t2 - g/2*sqr(t2);

		len=dis(mx, my, mz, cx, cy, cz);
		if(len<r){
			printf("HIT\n");
			return ;
		}
	}
	printf("MISSED\n");
}

int main(){
	init();
	done();
	return 0;
}
