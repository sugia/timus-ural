//#include "stdafx.h"
#include <iostream>
using namespace std;

#define g 981
double w, h, l, t;

int main()
{
	scanf("%lf%lf%lf", &l, &h, &w);

	if(l/2>h)
	{
		printf("butter\n");
		return 0;
	}

	t=sqrt(double(2*(h-l/2)/g));
	w=w*t/60;

	while(w>1)
		w-=1;

//	cout<<w<<endl;

	if((0<=w && w<=0.25) || (0.75<=w && w<=1))
		printf("butter\n");
	else
		printf("bread\n");

	return 0;
}