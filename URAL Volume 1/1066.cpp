//#include "stdafx.h"
#include <stdio.h>
#include <math.h>
 
int main(void)
{
    double k, h1, ans, p = 10000000;
    int n;
    scanf("%d %lf", &n, &h1);
    ans = (n - 1) * (n - 2);
    k = ceil(sqrt(h1));
    if(k <= n - 1)
        p = h1 / k + k;
    k = floor(sqrt(h1));
    if(k <= n - 1 && p > h1 / k + k)
        p = h1 / k + k;
    if(p == 10000000)
        p = h1 / (n - 1) + n - 1;
    p = -p + 1;
    ans += p * (n - 1) + h1;
    printf("%.2lf", ans);
    return 0;
}