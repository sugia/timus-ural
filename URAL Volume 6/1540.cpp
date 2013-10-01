#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int maxn=122;
vector<int> data[maxn];
int n, x, y;
int sgdata[maxn];
int ans;
map<vector<int>, int> mv;
set<vector<int> > sv;

int sg(vector<int> que)
{
    if(sv.find(que)!=sv.end()) return mv[que];
    if(que.size()==0) return 0;
    if(que.size()==1) return 1;
    bool yes[maxn];
    set<int> can, you;
    for(int i=0;i<que.size();++i)
    {
        if(you.find(que[i])!=you.end()) continue;
        
        memset(yes, true, sizeof(yes));
        for(int j=0;j<que.size();++j)
            if(que[j]<=que[i]) yes[j]=false;
        
        int tmp=0;
        for(int j=0;j<que.size();++j)
            if(yes[j])
            {
                int k=j;
                while(k+1<que.size() && yes[k+1]) ++k;
                vector<int> tmpque;
                for(int x=j;x<=k;++x) tmpque.push_back(que[x]);
                tmp^=sg(tmpque);
                j=k;
            }  
        can.insert(tmp);
        you.insert(que[i]);
    }    
    for(int i=0;i<=101;++i)
        if(can.find(i)==can.end())
        {
            sv.insert(que);
            mv[que]=i;
            return i;
        }
}

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d", &x);
        for(int j=1;j<=x;++j)
        {
            scanf("%d", &y);
            data[i].push_back(y);        
        }        
    }
    
    ans=0;
    for(int i=1;i<=n;++i)
    {
        sgdata[i]=sg(data[i]);
        //cout<<sgdata[i]<<endl;
        ans^=sgdata[i];    
    }
    if(ans==0) printf("S\n");
    else
    {
        printf("G\n");
        bool flag=false;
        for(int x=1;x<=n;++x)
        {
            bool yes[maxn];      
            for(int i=0;i<data[x].size();++i)
            {
                memset(yes, true, sizeof(yes));
                for(int j=0;j<data[x].size();++j)
                    if(data[x][j]<=data[x][i]) yes[j]=false;
                
                int tmp=0;
                for(int j=0;j<data[x].size();++j)
                    if(yes[j])
                    {
                        int k=j;
                        while(k+1<data[x].size() && yes[k+1]) ++k;
                        vector<int> tmpque;
                        for(int y=j;y<=k;++y) tmpque.push_back(data[x][y]);
                        tmp^=sg(tmpque);
                        j=k;
                    } 
                    
                for(int j=1;j<=n;++j)
                    if(j!=x) tmp^=sgdata[j];
                if(tmp==0)
                {
                    printf("%d %d\n", x, i+1);
                    flag=true;          
                } 
                if(flag) break;
            }    
            if(flag) break;
        }
            
    }
//    system("pause");
    return 0;
        
}