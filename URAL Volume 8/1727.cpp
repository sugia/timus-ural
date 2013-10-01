//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 100022
int n,tot=0,a[maxn],b[maxn],c[maxn];
bool f[maxn]={false};

inline int get(int x)
{
    int sum=0;
    while (x)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int main()
{
    scanf("%d", &n);
    f[0]=true;
    for (int i=99999;i;--i)
    {
        int w=get(i);
        for (int j=n-w;j>=0;--j)
            if (f[j])
            {
                if (f[j+w])  continue;
                f[j+w]=true;
                a[j+w]=w;
                b[j+w]=i;
                if (f[n])  break;
            }
        if (f[n])  break;
    }
    while (n)
    {
        c[++tot]=b[n];
        n-=a[n];
    }
    cout << tot << endl;
    for (int i=1;i<tot;++i)
        cout << c[i] << ' ';
    cout << c[tot] << endl;
    return 0;
}