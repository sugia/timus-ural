//#include "stdafx.h"
#include <iostream>
using namespace std;
const int mov[4][2]={0,1,0,-1,1,0,-1,0};
int n,l=0,r=1,tot,a[201]={0},t[10][10]={0};
struct node
{
    int x,y;
    node()
    {
        x=y=0;
    }
}Q[1001],u,v;
inline int get()
{
    while ((!a[tot]) && tot)  --tot;
    --a[tot];
    return tot;
}
int main()
{
    cin >> n;
    for (int i=n*n;i;--i)
    {
        cin >> tot;
        ++a[tot];
    }
    tot=200;
    Q[1].x=(n+1>>1);
    Q[1].y=(n+1>>1);
    t[Q[1].y][Q[1].x]=get();
    while (l < r)
    {
        u=Q[++l];
        for (int i=0;i<4;++i)
        {
            v.x=u.x+mov[i][0];
            v.y=u.y+mov[i][1];
            if ((v.x < 1) || (v.y < 1) || (v.x > n) || (v.y > n))
                continue;
            if (t[v.y][v.x])  continue;
            t[v.y][v.x]=get();
            Q[++r]=v;
        }
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            cout << t[i][j] << ' ';
        cout << endl;
    }
    return 0;
}