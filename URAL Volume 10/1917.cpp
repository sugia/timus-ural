#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int maxn=1022;
map<int, int> ditu;
set<int> can;
set<int>::iterator it;
int n, p, tmp;

int num[maxn];
int tot[maxn];
int sum, tim;

void display()
{
    for(int i=1;i<=can.size();++i)
        cout<<num[i]<<' '<<tot[i]<<endl;     
}
int main()
{
    scanf("%d%d", &n, &p);
    for(int i=1;i<=n;++i)
    {
        scanf("%d", &tmp);
        can.insert(-tmp);
        ++ditu[tmp];        
    }    
    
    int id=can.size()+1;
    for(it=can.begin();it!=can.end();++it)
    {
        num[--id]=-*it;
        tot[id]=ditu[num[id]];  
        
    }
    
    for(int i=2;i<=can.size();++i)
        tot[i]+=tot[i-1];
        
        
    //display();
    
    sum=0;
    tim=0;
    bool flag;
    while(1)
    {
        flag=true;
        for(int i=can.size();i>=1;--i)
            if(tot[i]!=0 && tot[i]*num[i]<=p)
            {
                sum+=tot[i];
                ++tim;
                
                for(int j=can.size();j>=i;--j)
                    tot[j]-=tot[i];
                for(int j=1;j<i;++j)
                    tot[j]=0;
                flag=false;
                break;                    
            }
        if(flag)
            break;        
    }    
    
    
    printf("%d %d\n", sum, tim); 
    //system("pause");
    return 0;                                   
}