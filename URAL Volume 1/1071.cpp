//#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b;
int x, y;

void changeBase(int key, int base)
{
//	int tmp;
	if(key==1)
	{
		int xx=x;
		a.clear();
		while(xx!=0)
		{
//			tmp=xx%base;
			a.push_back(xx%base);
			xx/=base;
		}
	}
	else
	{
		int yy=y;
		b.clear();
		while(yy!=0)
		{
//			tmp=yy%base;
			b.push_back(yy%base);
			yy/=base;
		}
	}
}

int main()
{
	scanf("%d%d", &x, &y);
	int maxk = x > y ? x+1 : y+1;
	int astep, bstep;
	bool flag=false;
	for(int i=2;i<=maxk;++i)
	{
//		cout<<i<<endl;
		changeBase(1, i);
		changeBase(2, i);

		astep=0;
		bstep=0;

		while(1)
		{
			if(a[astep]==b[bstep])
			{
				++astep;
				++bstep;
			}
			else
				++astep;

			if(bstep==b.size())
				flag=true;
			if(astep==a.size() || bstep==b.size())
				break;
		}

		if(flag)
		{
			printf("%d\n", i);
			return 0;
		}
	}

	if(!flag)
	{
		printf("No solution\n");
		return 0;
	}

}