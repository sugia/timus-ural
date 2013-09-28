//#include "stdafx.h"
#include<iostream>
using namespace std;
float min(float a,float b,float c)
{
    float t=9999999;
    if ((a<t)&&(abs(a)<11)) t=a;
    if ((b<t)&&(abs(b)<11)) t=b;
    if ((c<t)&&(abs(c)<11)) t=c;
    return t;
}    
int deal(float x)
{
    if (x+0.5>=(int)x) return((int)x+1);
    return((int)x);
}    
int main(void)
{
    float a,b,x,x1,x2;
    cin>>a>>b;
    x1=min(a-b,a-b-24,a+24-b);
    cin>>a>>b;
    x2=min(a-b,a-b-24,a+24-b);
    x=abs(x1-x2);
    x=deal(x);
    cout<<(int)x/2;
    return 0;
}    
 