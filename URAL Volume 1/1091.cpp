//#include "stdafx.h"
#include <iostream>
 
using namespace std;
 
long long k,s;
long long i,j,l,ans;
 
long long prime (long long x)
{
     long long y;
     for (y=2;y<x;y++)
         if (x%y==0) return (0);
     return (1);
}
 
long long c (long long x,long long y)
{
     long long i,aa=1,bb=2;
     for (i=x-y+1;i<=x;i++)
         {
         aa*=i;
         if ((bb<=y)&&(aa%bb==0)) {
                                  aa=aa/bb;
                                  bb++;
                                  }
         }
     while (bb<=y)
           {
           aa=aa/bb;
           bb++;
           }
     return (aa);
}
 
int main ()
{
    cin>>k>>s;
    for (i=2;i<=s;i++)
        if (prime(i)) {
                      if (i*k<=s) ans+=(c(s/i,k));
                      if (ans>10000) {
                                     ans=10000;
                                     break;
                                     }
                      }
                      else {
                           l=0;
                           for (j=2;j<i;j++)
                               if ((i%j==0)&&(prime(j))&&(prime(i/j))&&(i!=j*j)) {
                                                                                 l=1;
                                                                                 break;
                                                                                 }
                           if (l==0) continue;
                           if (i*k<=s) ans-=(c(s/i,k));
                           if (ans>10000) {
                                          ans=10000;
                                          break;
                                          }
                           }
    cout<<ans<<endl;
    return (0);
}