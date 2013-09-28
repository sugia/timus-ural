//#include "stdafx.h"
#include <iostream>
 
using namespace std;
 
long n,i,j,k,l,okk,flag,x[101],y[101],z[101],ok[101];
double ct,best;
 
double bbs (double now)
{
       if (now>0) return (now);
                  else return (0-now);
}
 
int main ()
{
    cin>>n;
    for (i=0;i<n;i++)
        cin>>x[i]>>y[i]>>z[i];
    for (j=0;j<=500;j++)
        for (k=0;k<=500-j;k++)
                {
                l=500-j-k;
                best=10000000.00000;
                flag=1;
                for (i=0;i<n;i++)
                    {
                    ct=(double)(j)/(double)(x[i])+(double)(k)/(double)(y[i])+(double)(l)/(double)(z[i]);
                    if (bbs(ct-best)<0.000000000001) {
                                                     flag=0;
                                                     continue;
                                                     }
                    if (ct<best) {
                                 flag=1;
                                 best=ct;
                                 okk=i;
                                 }
                    }
                if (flag) ok[okk]=1;
                }
    for (i=0;i<n;i++)
        if (ok[i]) cout<<"Yes"<<endl;
                   else cout<<"No"<<endl;
    return (0);
}