//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
 
double get(int f, int l)
{
    if(f == 1) return 2*l;
    if(f == 2) return l;
    return l*sqrt(3.0)/2.0;
}
int main()
{
    int n, f, ans;
    double l, d, b;
    while(scanf("%d%lf", &f, &l) != EOF)
    {
        d = get(f, l);
        if(f == 2) d = sqrt(2.0)*l;
        if(f == 3) d = l;
        scanf("%d", &n);
        ans = 0;
        while(n --)
        {
            scanf("%d%lf", &f, &l);
            if(d >= get(f, l)) ans ++;
        }
        printf("%d\n", ans);
    }
    return 0;
}