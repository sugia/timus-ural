//#include "stdafx.h"
#include <iostream>
using namespace std;
int n,a,b,c,L=0,res,f[1<<18]={0};
int main()
{
    scanf("%d",&n);
    while ((1<<L) < (n<<1))  ++L;
    res=(1<<L-1);
    for (int i=0;i<=n;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        a=a+res-1,b=b+res-1;
        if (a == res)
            f[a]+=c;
        else  --a;
        if (b == n+res-1)
            f[b]+=c;
        else  ++b;
        while (a^b^1)
        {
            if (a&1^1)  f[a^1]+=c;
            if (b&1)  f[b^1]+=c;
            a>>=1;
            b>>=1;
        }
    }
    for (int i=1;i<=n;++i)
    {
        int sum=0;
        for (int j=i+res-1;j;j>>=1)
            sum+=f[j];
        printf("%d ",sum);
    }
    printf("\n");
    return 0;
}