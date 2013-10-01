//#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#define maxn 20022
int n,tot=0;
char s[maxn],t[maxn]={'\0'};
inline void renew(int l,int r)
{
    if (l > r)  return;
    int mid=l+(r-l>>1);
    t[mid]=s[++tot];
    renew(l,mid-1);
    renew(mid+1,r);
}
int main()
{
    gets(&s[1]);
    n=strlen(&s[1]);
    renew(1,n);
    puts(&t[1]);
    return 0;
}