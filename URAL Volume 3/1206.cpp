//#include "stdafx.h"
#include <iostream>
using namespace std;

#define maxn 10022
int a[maxn]={0};

void che()
{
     int y,t=0;
     for (y=1;y<=a[0];y++)
    {
		t=a[y]*55+t;
		a[y]=t%10;
		t=t/10;
    }	
    while (t!=0)
		a[0]++,a[a[0]]=t%10,t/=10;
}

int main()
{
    int k,i; 
	che();  
	scanf("%d",&k);
    a[0]=2,a[1]=6,a[2]=3;

    for(i=1;i<k;i++)
		che();

    for (i=a[0];i>=1;i--)
		printf("%d",a[i]);

    return 0;
}