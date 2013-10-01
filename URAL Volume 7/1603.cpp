//#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

const int mov[4][2]={0,1,0,-1,1,0,-1,0};
char dic[6][6],s[18];
int n;
bool found,used[5][5]={false};

inline void dfs(int x,int y,int t)
{
    if (found)  return;
    if ((!x) || (!y) || (x > 4) || (y > 4))
        return;
    if (used[y][x])  return;
    if (dic[y][x] != s[t])  return;
    if (!t)  found=true;
    used[y][x]=true;
    for (int i=0;i<4;++i)
        dfs(x+mov[i][0],y+mov[i][1],t-1);
    used[y][x]=false;
}

inline bool find()
{
    int length=strlen(s)-1;
    found=false;
    for (int x=1;x<=4;++x)
        for (int y=1;y<=4;++y)
        {
            dfs(x,y,length);
            if (found)  return true;
        }
    return false;
}

int main()
{
    for (int i=1;i<=4;++i)
        cin >> &dic[i][1];
    cin >> n;
    for (int i=1;i<=n;++i)
    {
        cin >> s;
        cout << s << ": ";
        if (find())  cout << "YES" << endl;
        else  cout << "NO" << endl;
    }
    return 0;
}