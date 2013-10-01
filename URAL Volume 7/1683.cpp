//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 122
int n, step=0, ans[maxn];
int main()
{
    scanf("%d", &n);
    while (n > 1)
    {
        n=n-(n>>1);
        ans[++step]=n;
    }
    
    printf("%d\n", step);

    for (int i=1;i<=step;++i)
        cout << ans[i] << ' ';
    return 0;

}