//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int a[10005], t[10005];
int n, st;
void merge(int l, int m, int r)
{
    int p = 0, i = l, j = m+1;
    while(i <= m && j <= r)
    {
        if(a[i] > a[j])
        {
            t[p ++] = a[j++];
            st += m-i+1;
        }
        else t[p ++] = a[i++];
    }
    while(i <= m) t[p ++] = a[i ++];
    while(j <= r) t[p ++] = a[j ++];
    for(i = 0; i < p; i ++) a[l+i] = t[i];
}
void mergesort(int l, int r)
{
    int m;
    if (l < r)
    {
        m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}
int main()
{
    int n, k, i, ans = 0, t= 1, j;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= k; i ++)
    {
        for(j = 0; j < n; j ++)
            scanf("%d", &a[j]);
        st = 0;
        mergesort(0, n-1);
        if(st > ans) ans = st, t = i;
    }
    printf("%d\n", t);
}