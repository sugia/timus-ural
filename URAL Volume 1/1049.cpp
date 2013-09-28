//#include "stdafx.h"
#include<stdio.h>
#include<string.h>
 
bool p[10001];
int v[1230];
int f[1230]={0};
 
int  main()
{
	int i,j,k,max=0,l=0;
	memset(p,true,sizeof(p));
    p[0]=false;p[1]=false;
	for(i=2;i<10001;i++)
    {
    	if(p[i])
    	{
	    	l+=1;
	    	v[l]=i;
            for(j=i*2;j<10001;j+=(i))
                p[j]=false;
    	}
    }
    for(i=0;i<10;i++)
    {
	    scanf("%d",&k); 
		for(j=1;(j<=l)&&(k!=1);j++)
		    if(k%v[j]==0)
            {
  				if(max<j)max=j;
  				for(;(k%v[j]==0);k/=(v[j]))
  				    f[j]+=1;
  			}	
    }
    int ans=1;
    for(i=1;i<=max;i++)
        ans*=(f[i]+1);
    printf("%d",ans%10);
	return 0;   
}