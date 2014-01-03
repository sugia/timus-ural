//#include "stdafx.h"
#include <iostream>
 
using namespace std;
 
long m,n;
long i,j,k,l;
long ans=1000000;
long b[100];
long a[100][100];
struct data{
       long x,y,z;
}c[100];
 
int main (){
    cin>>n>>m;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            if (i==j) a[i][j]=0;
            else a[i][j]=1000000;
    for (i=0;i<m;i++){
        cin>>l;
        for (j=0;j<l;j++){
            cin>>b[j];
            b[j]--;
        }
        for (j=0;j<l;j++)
            for (k=0;k<l;k++)
                if (b[j]!=b[k]) a[b[j]][b[k]]=4;
        }
    for (k=0;k<n;k++)
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if ((i!=j)&&(j!=k)&&(i!=k)) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    cin>>m;
    for (i=0;i<m;i++){
        cin>>c[i].x>>c[i].y>>c[i].z;
        c[i].y--;
    }
    l=-1;
    for (i=0;i<n;i++){
        k=1;
        for (j=0;j<m;j++)
            if (((a[c[j].y][i]>c[j].x)&&(c[j].z==0))||(a[c[j].y][i]==1000000)){
                k=0;
                break;
            }
        if (k==0) continue;
        
        k=0;
        for (j=0;j<m;j++)
            if (c[j].z==0) k+=a[c[j].y][i];
        if (k<ans){
            ans=k;
            l=i;
        }
    }
    if (l==-1) cout<<0<<endl;
    else cout<<l+1<<" "<<ans<<endl;
    return (0);
}
