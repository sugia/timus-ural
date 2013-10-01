//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

const double k=sqrt(double(2))/2;
int tmp;
double x, y;
int main()
{
	x=0, y=0;
	char ch;
	while(cin>>ch)
	{
		tmp=int(ch-'0');
		if(tmp==0)
		{
			printf("%.10lf %.10lf\n", x, y);
			return 0;
		}
		else
			if(tmp==1)
			{
				x-=k;
				y-=k;
			}
			else
				if(tmp==2)
					--y;
				else
					if(tmp==3)
					{
						x+=k;
						y-=k;
					}
					else
						if(tmp==4)
							--x;
						else
							if(tmp==6)
								++x;
							else
								if(tmp==7)
								{
									x-=k;
									y+=k;
								}
								else
									if(tmp==8)
										++y;
									else
										if(tmp==9)
										{
											x+=k;
											y+=k;
										}
	}

	printf("%.10lf %.10lf\n", x, y);
	return 0;
}