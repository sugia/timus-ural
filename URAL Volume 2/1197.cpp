//#include "stdafx.h"
#include <iostream>
using namespace std;
char ch;
int x, y, n, ans;

bool yes(int a, int b)
{
	return (a>=1 && a<=8 && b>=1 && b<=8);
}
int main()
{
	cin>>n;
	while(n--){
		cin>>ch>>y;
		x=ch-'a'+1;
		ans=0;
		if(yes(x+1, y+2)) ++ans;
		if(yes(x+2, y+1)) ++ans;
		if(yes(x+2, y-1)) ++ans;
		if(yes(x+1, y-2)) ++ans;
		
		if(yes(x-1, y-2)) ++ans;
		if(yes(x-2, y-1)) ++ans;
		if(yes(x-2, y+1)) ++ans;
		if(yes(x-1, y+2)) ++ans;

		cout<<ans<<endl;
	}
	return 0;
}