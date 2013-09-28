//#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
 
vector<int>q[1005];
int f[1005], flag[1005];
 
int k, ans;
void dfs(int t)
{
    flag[t] = 1;
    if(q[t].size() == 0)
    {
        f[t] = 0; return ;
    }
    for(int i = 0; i < q[t].size(); i ++)
    {
        if(flag[q[t][i]] == 0)
        {
            dfs(q[t][i]);
            if(f[q[t][i]] == 0)
            {
                f[t] = 1;
                if(t == k && ans > q[t][i]) ans = q[t][i];
            }
        }
    }
}
int main()
{
    int n, i, x, y;
    scanf("%d%d", &n, &k);
    for(i = 1; i < n; i ++)
    {
        scanf("%d%d", &x, &y);
        q[x].push_back(y);
        q[y].push_back(x);
    }
    memset(flag, 0, sizeof(flag));
    memset(f, 0, sizeof(f));
    ans = 10000;
    dfs(k);
    if(f[k]) printf("First player wins flying to airport %d\n", ans);
    else printf("First player loses\n");
    return 0;
}