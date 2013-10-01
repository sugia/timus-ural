#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int maxn=1e4+22;
int n;
int data[maxn];

int lowbit(int x)
{
    return (x)&(-x);    
}

void add(int step, int delta)
{
    while(step<=n)
    {
        data[step]+=delta;
        step+=lowbit(step);              
    }     
}

int sum(int step)
{
    int ret=0;
    while(step>0)
    {
        ret+=data[step];
        step-=lowbit(step);             
    }     
    return ret;
}

int main()
{
    memset(data, 0, sizeof(data));
    scanf("%d", &n);
    int tmp;
    for(int i=1;i<=n;++i)
    {
        scanf("%d", &tmp);
        add(i, tmp);        
    }    
    
    int q, x, y;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", sum(y)-sum(x-1));
    }
    
    //system("pause");
    return 0;
}